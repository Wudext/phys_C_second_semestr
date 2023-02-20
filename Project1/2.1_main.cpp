#include "main.h"

class Compl {
private:
	double real, imaginary;
public:
	explicit Compl(double a = 0, double b = 0) {
		imaginary = a;
		real = b;
	};

	Compl(const Compl& src) : imaginary(src.imaginary), real(src.real) {
	};

	Compl& operator=(const Compl& src) {
		imaginary = src.imaginary;
		real = src.real;
		return *this;
	}

	Compl& operator+=(const Compl& src) {
		imaginary = imaginary + src.imaginary;
		real = real + src.real;
		return *this;
	}

	Compl& operator*=(int k) {
		imaginary = imaginary * k;
		real = real * k;
		return *this;
	}

	Compl& operator/=(int k) {
		imaginary = double(imaginary) / double(k);
		real = double(real) / double(k);
		return *this;
	}

	Compl& operator-=(const Compl& src) {
		imaginary = imaginary - src.imaginary;
		real = real - src.real;
		return *this;
	}

	bool operator!=(const Compl& src) {
		if ((imaginary != src.imaginary) and (real != src.real)) {
			return true;
		}
		else {
			return false;
		}
	}

	Compl operator+(const Compl& src2) const {
		Compl res(*this);
		res += src2;
		return res;
	}

	Compl operator-(const Compl& src2) const {
		Compl res(*this);
		res -= src2;
		return res;
	}

	Compl operator*(int k) const {
		Compl res(*this);
		res *= k;
		return res;
	}

	Compl operator/(int k) const {
		Compl res(*this);
		res /= k;
		return res;
	}

	friend ostream& operator<<(ostream& os, const Compl& src) {
		os << "Your number is: " << src.imaginary << "i + " << src.real << flush << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Compl& r) {
		int imaginary;
		is >> imaginary;
		int real;
		is >> real;

		r = Compl(imaginary, real);
		return is;
	}
};

class ComplexVector {
private:
	Compl* v;
	int len;
public:
	explicit ComplexVector(int N = 0) : v(0), len(0) {
		if (N > 0) {
			v = new Compl[N];
			if (v) len = N;
		}
	}

	ComplexVector(const ComplexVector& temp) : v(0), len(0) {
		if (temp.len > 0) v = new Compl[temp.len];
		if (v){
			len = temp.len;
			for (int i = 0; i < len; i++) {
				v[i] = temp.v[i];
			}
		}
	}

	ComplexVector append(int index, const Compl& addition) {
		int i = index;
		Compl tmp, replace=addition;
		while (v[i] != Compl(NULL, NULL)) {
			tmp = v[i];
			v[i] = replace;
			replace = tmp;
			i++;
		}
		this->len += 1;
		return *this;
	}

	ComplexVector del(int index) {
		int i = index;
		Compl tmp;
		while (v[i + 1] != Compl(NULL, NULL)) {
			v[i] = v[i + 1];
			i++;
		}
		this->len -= 1;
		return *this;
	}

	// int size() const { return len; }
	Compl& operator [] (int index) { return v[index]; };
	Compl operator [](int index) const { return v[index]; };

	friend ostream& operator<<(ostream& os, const ComplexVector& src) {
		os << "Your Vector is:" << endl;
		for (int i = 0; i < src.len; i++) {
			cout << src[i];
		}
		return os;
	}

	friend istream& operator>>(istream& is, ComplexVector& src) {
		cout << "¬ведите массив комлпексных чисел: " << endl;
		for (int i = 0; i < src.len; i++) {
			cin >> src[i];
		}
		return is;
	}
};


void main_21() {
	const int N = 5;
	ComplexVector PtArray(N);
	ComplexVector* VComplex;
	Compl addition;
	cin >> PtArray;
	cout << PtArray << endl;
	cin >> addition;
	PtArray.append(2, addition);
	cout << PtArray;
	PtArray.del(0);
	cout << PtArray;
}