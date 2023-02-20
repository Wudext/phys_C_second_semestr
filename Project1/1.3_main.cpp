#include "main.h"

class Matrix {
private:
	int a1, a2, a3, a4;
public:
	explicit Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		a1 = a;
		a2 = b;
		a3 = c;
		a4 = d;
	};

	Matrix(const Matrix& src) : a1(src.a1), a2(src.a2), a3(src.a3), a4(src.a4) {
	};

	Matrix& operator=(const Matrix& src) {
		a1 = src.a1;
		a2 = src.a2;
		a3 = src.a3;
		a4 = src.a4;
		return *this;
	}

	Matrix& operator+=(const Matrix& src) {
		a1 = a1 + src.a1;
		a2 = a2 + src.a2;
		a3 = a3 + src.a3;
		a4 = a4 + src.a4;
		return *this;
	}

	Matrix& operator-=(const Matrix& src) {
		a1 = a1 - src.a1;
		a2 = a2 - src.a2;
		a3 = a3 - src.a3;
		a4 = a4 - src.a4;
		return *this;
	}

	Matrix& operator*=(const Matrix& src2) {
		Matrix n;
		n.a1 = a1 * src2.a1 + a2 * src2.a3;
		n.a2 = a1 * src2.a2 + a2 * src2.a4;
		n.a3 = a3 * src2.a1 + a4 * src2.a3;
		n.a4 = a3 * src2.a2 + a4 * src2.a4;
		return n;
	}

	Matrix& operator/=(const Matrix& src) {
		Matrix n;
		n.a1 = a1 / src.a1 + a2 / src.a3;
		n.a2 = a1 / src.a2 + a2 / src.a4;
		n.a3 = a3 / src.a1 + a4 / src.a3;
		n.a4 = a3 / src.a2 + a4 / src.a4;
		return n;
	}

	Matrix& operator+(const Matrix& src2) {
		Matrix res(*this);
		return res += src2;
	}

	Matrix& operator-(const Matrix& src2) const {
		Matrix res(*this);
		return res -= src2;
	}

	Matrix& operator*(const Matrix& src2) const {
		Matrix res(*this);
		return res *= src2;
	}

	Matrix& operator/(const Matrix& src2) const {
		Matrix res(*this);
		return res /= src2;
	}

	int first() const { return a1; };
	int second() const { return a2; };
	int third() const { return a3; };
	int fourth() const { return a4; };

};

ostream& operator<<(ostream& os, const Matrix& src) {
	int first = src.first();
	int second = src.second();
	int third = src.third();
	int fourth = src.fourth();
	os << "Your matrix is: " << endl << first << " " << second << endl << third << " " << fourth << endl << flush;
	return os;
}

istream& operator>>(istream& is, Matrix& r) {
	int a;
	is >> a;
	int b;
	is >> b;
	int c;
	is >> c;
	int d;
	is >> d;

	r = Matrix(a, b, c, d);
	return is;
}

void main_13() {
	Matrix m1;
	Matrix m2;
	cout << "¬ведите первую матрицу: ";
	cin >> m1;
	cout << m1;
	cout << "¬ведите вторую матрицу: ";
	cin >> m2;
	cout << m2;

	cout << m1 * m2;
	cout << m1 + m2;
	cout << m1 - m2;
	cout << m1 / m2;
}