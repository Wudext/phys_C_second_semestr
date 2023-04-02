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
		if (src.type == "Окружность") {
			return 3.14 * src.a;
		}
		if (src.type == "Ромб") {
			return 0.5 * src.a * src.b;
		}
	}
};

class Circle : public Geom{
public:
	Geom obj;
	explicit Circle(int a = 0): obj("Окружность", 0, 0) {
		if (a > 0) {
			obj = Geom("Окружность", a, 0);
		}
	}
	Circle(const Circle& src) : obj("Окружность", 0, 0) {
		obj = src.obj;
	}

	friend istream& operator>>(istream& is, Circle& r) {
		cout << "Введите радиус: ";
		int rad;
		is >> rad;
		r.obj = Geom("Окружность", rad, 0);
		return is;
	}

	friend ostream& operator<<(ostream& os, Circle& r) {
		cout << "----- Окружность -----" << endl;
		cout << "Радиус: " << r.obj.a << endl;
		cout << "Площадь: " << r.obj.area(r.obj) << endl;
		return os;
	}
};

class Romb : public Geom {
public:
	Geom obj;
	explicit Romb(int a = 0, int b = 0) : obj("Ромб", 0, 0) {
		if (a > 0) {
			obj = Geom("Ромб", a, b);
		}
	}
	Romb(const Romb& src) : obj("Ромб", 0, 0) {
		obj = src.obj;
	}

	friend istream& operator>>(istream& is, Romb& r) {
		cout << "Введите первую диагональ: ";
		int d1;
		is >> d1;
		cout << "Введите вторую диагональ: ";
		int d2;
		is >> d2;
		r.obj = Geom("Ромб", d1, d2);
		return is;
	}

	friend ostream& operator<<(ostream& os, Romb& r) {
		cout << "----- Ромб -----" << endl;
		cout << "Первая диагональ: " << r.obj.a << endl;
		cout << "Вторая диагональ: " << r.obj.b << endl;
		cout << "Площадь: " << r.obj.area(r.obj) << endl;
		return os;
	}
};

void main_43() {
	Circle* c;
	Romb* r;
	int k = 0;
	double s = 0;
	cout << "Введите кол-во кругов: ";
	cin >> k;
	c = new Circle[k];
	for (int i = 0; i < k; i++) {
		cout << "Введите " << i+1 << "-ый элемент" << endl;
		cin >> c[i];
			s += c[i].area(c[i].obj);
		cout << c[i];
	}
	cout << "Итоговая сумма площадей кругов: " << s << endl;
	s = 0;
	cout << "Введите кол-во ромбов: ";
	cin >> k;
	r = new Romb[k];
	for (int i = 0; i < k; i++) {
		cout << "Введите " << i + 1 << "-ый элемент" << endl;
		cin >> r[i];
		s += r[i].area(r[i].obj);
		cout << r[i];
	}
	cout << "Итоговая сумма площадей ромбов: " << s;
}