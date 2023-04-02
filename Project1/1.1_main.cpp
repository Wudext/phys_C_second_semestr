#include "main.h"

class Complex {
private:
	double real, imaginary;
public:
	explicit Complex(double a = 0, double b = 0) {
		imaginary = a;
		real = b;
	};

	Complex(const Complex& src) : imaginary(src.imaginary), real(src.real) {
	};

	Complex& operator=(const Complex& src) {
		imaginary = src.imaginary;
		real = src.real;
		return *this;
	}

	Complex& operator+=(const Complex& src) {
		imaginary = imaginary + src.imaginary;
		real = real + src.real;
		return *this;
	}

	Complex& operator*=(int k) {
		imaginary = imaginary * k;
		real = real * k;
		return *this;
	}

	Complex& operator/=(int k) {
		imaginary = double(imaginary) / double(k);
		real = double(real) / double(k);
		return *this;
	}

	Complex& operator-=(const Complex& src) {
		imaginary = imaginary - src.imaginary;
		real = real - src.real;
		return *this;
	}

	Complex operator+(const Complex& src2) const {
		Complex res(*this);
		res += src2;
		return res;
	}

	Complex operator-(const Complex& src2) const {
		Complex res(*this);
		res -= src2;
		return res;
	}

	Complex operator*(int k) const {
		Complex res(*this);
		res *= k;
		return res;
	}

	Complex operator/(int k) const {
		Complex res(*this);
		res /= k;
		return res;
	}

	double im() const { return imaginary; };
	double rl() const { return real; };
};

ostream& operator<<(ostream& os, const Complex& src) {
	os << "Your number is: " << src.im() << "i + " << src.rl() << flush << endl;
	return os;
}

istream& operator>>(istream& is, Complex& r) {
	int imaginary;
	is >> imaginary;
	int real;
	is >> real;

	r = Complex(imaginary, real);
	return is;
}

void main_11() {
	Complex first;
	Complex second;
	int k;

	cout << "Введите первое число: ";
	cin >> first;
	cout << first;
	cout << "Введите второе число: ";
	cin >> second;
	cout << second;
	cout << "Сумма: " << endl << first + second;
	cout << "Разность" << endl << first - second;
	cout << "Введите коэффициент: ";
	cin >> k;
	cout << "Умножение на число:" << endl << first * k;
	cout << "Деление на число:" << endl << first / k;
}