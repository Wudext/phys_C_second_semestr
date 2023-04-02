#include "main.h"
#include <vector>

class Geom {
public:
	const char* type;
	int a, b;
	explicit Geom(const char* type_src = NULL, int p1 = 0, int p2 = 0) :type(NULL), a(0), b(0) {
		if (type_src) {
			type = type_src;
			a = p1;
			b = p2;
		}
	}

	Geom(const Geom& src) :type(NULL), a(0), b(0) {
		if (src.type) {
			type = src.type;
			a = src.a;
			b = src.b;
		}
	}

	virtual double area(const Geom& src) {
		if (src.type == "����������") {
			return 3.14 * src.a;
		}
		if (src.type == "����") {
			return 0.5 * src.a * src.b;
		}
	}
};

class Circle : public Geom{
public:
	Geom obj;
	explicit Circle(int a = 0): obj("����������", 0, 0) {
		if (a > 0) {
			obj = Geom("����������", a, 0);
		}
	}
	Circle(const Circle& src) : obj("����������", 0, 0) {
		obj = src.obj;
	}

	friend istream& operator>>(istream& is, Circle& r) {
		cout << "������� ������: ";
		int rad;
		is >> rad;
		r.obj = Geom("����������", rad, 0);
		return is;
	}

	friend ostream& operator<<(ostream& os, Circle& r) {
		cout << "----- ���������� -----" << endl;
		cout << "������: " << r.obj.a << endl;
		cout << "�������: " << r.obj.area(r.obj) << endl;
		return os;
	}
};

class Romb : public Geom {
public:
	Geom obj;
	explicit Romb(int a = 0, int b = 0) : obj("����", 0, 0) {
		if (a > 0) {
			obj = Geom("����", a, b);
		}
	}
	Romb(const Romb& src) : obj("����", 0, 0) {
		obj = src.obj;
	}

	friend istream& operator>>(istream& is, Romb& r) {
		cout << "������� ������ ���������: ";
		int d1;
		is >> d1;
		cout << "������� ������ ���������: ";
		int d2;
		is >> d2;
		r.obj = Geom("����", d1, d2);
		return is;
	}

	friend ostream& operator<<(ostream& os, Romb& r) {
		cout << "----- ���� -----" << endl;
		cout << "������ ���������: " << r.obj.a << endl;
		cout << "������ ���������: " << r.obj.b << endl;
		cout << "�������: " << r.obj.area(r.obj) << endl;
		return os;
	}
};

void main_43() {
	Circle* c;
	Romb* r;
	int k = 0;
	double s = 0;
	cout << "������� ���-�� ������: ";
	cin >> k;
	c = new Circle[k];
	for (int i = 0; i < k; i++) {
		cout << "������� " << i+1 << "-�� �������" << endl;
		cin >> c[i];
			s += c[i].area(c[i].obj);
		cout << c[i];
	}
	cout << "�������� ����� �������� ������: " << s << endl;
	s = 0;
	cout << "������� ���-�� ������: ";
	cin >> k;
	r = new Romb[k];
	for (int i = 0; i < k; i++) {
		cout << "������� " << i + 1 << "-�� �������" << endl;
		cin >> r[i];
		s += r[i].area(r[i].obj);
		cout << r[i];
	}
	cout << "�������� ����� �������� ������: " << s;
}