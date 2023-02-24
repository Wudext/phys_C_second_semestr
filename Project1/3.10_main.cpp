#include "main.h"

class Massive {
private:
	int* m;
	int len;
public:
	explicit Massive(int N = 2) : len(0), m(0) {
		if (N > 0) {
			m = new int(N);
		}
		if (m) {
			len = N;
		}
	}

	Massive(const Massive& temp) {
		if (temp.len > 0) {
			len = temp.len;
			m = new int[len];
		}
		if (m) {
			for (int i = 0; i < len; i++) {
				m[i] = temp.m[i];
			}
		}
	}

	Massive& operator=(const Massive& src) {
		len = src.len;
		m = new int[len];
		for (int i = 0; i < len; i++) {
			m[i] = src.m[i];
		}
		return *this;
	}

	Massive& operator+=(const Massive& src) {
		for (int i = 0; i < src.len; i++) {
			if (m[i]) {
				m[i] += src.m[i];
			}
			else {
				m[i] = src.m[i];
			}
		}
		return *this;
	}

	Massive& operator-=(const Massive& src) {
		for (int i = 0; i < src.len; i++) {
			if (m[i]) {
				m[i] -= src.m[i];
			}
		}
		return *this;
	}

	Massive& operator*=(const Massive& src) {
		for (int i = 0; i < src.len; i++) {
			if (m[i]) {
				m[i] *= src.m[i];
			}
		}
		return *this;
	}

	Massive operator+(const Massive& src) {
		Massive res(*this);
		res += src;
		return res;
	}

	Massive operator-(const Massive& src) {
		Massive res(*this);
		res -= src;
		return res;
	}

	Massive operator*(const Massive& src) {
		Massive res(*this);
		res *= src;
		return res;
	}

	int& operator [](int index) { return m[index]; };
	int operator [](int index) const { return m[index]; };

	friend ostream& operator<<(ostream& os, const Massive& src) {
		os << "[";
		for (int i = 0; i < src.len; i++) {
			cout << src.m[i] << ", ";
		}
		os << "]" << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Massive& src) {
		cout << "¬ведите массив: " << endl;
		for (int i = 0; i < src.len; i++) {
			cin >> src.m[i];
		}
		return is;
	}
};

class Matrix2 : public Massive {
private:
	int size = 2;
	Massive* m;
public:
	explicit Matrix2() : m(0) {
		m = new Massive[size];
		for (int i = 0; i < size; i++) {
			m[i] = Massive(size);
		}
	}

	Matrix2(const Matrix2& temp) {
		if (temp.size > 0) {
			m = new Massive[temp.size];
			for (int i = 0; i < temp.size; i++) {
				m[i] = Massive(size);
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m[i][j] = temp.m[i][j];
			}
		}
	}

	Matrix2& operator=(const Matrix2& src) {
		size = src.size;
		m = new Massive[size];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m[i][j] = src.m[i][j];
			}
		}
		return *this;
	}

	Matrix2& operator+=(const Matrix2& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m[i][j] += src.m[i][j];
			}
		}
		return *this;
	}

	Matrix2& operator-=(const Matrix2& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m[i][j] -= src.m[i][j];
			}
		}
		return *this;
	}

	Matrix2& operator*=(const Matrix2& src) {
		Matrix2 n;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				n.m[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					n.m[i][j] += m[i][k] * src.m[k][j];
				}
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				m[i][j] = n.m[i][j];
			}
		}
		return *this;
	}

	Matrix2 operator+(const Matrix2& src2) const {
		Matrix2 res(*this);
		res += src2;
		return res;
	}

	Matrix2 operator-(const Matrix2& src2) const {
		Matrix2 res(*this);
		res -= src2;
		return res;
	}

	Matrix2 operator*(const Matrix2& src2) const {
		Matrix2 res(*this);
		res *= src2;
		return res;
	}

	friend ostream& operator<<(ostream& os, const Matrix2& src) {
		for (int i = 0; i < src.size; i++) {
			for (int j = 0; j < src.size; j++) {
				cout << src.m[i][j] << " ";
				if (j % src.size == src.size - 1) {
					os << endl;
				}
			}
		}
		return os;
	}

	friend istream& operator>>(istream& is, Matrix2& src) {
		for (int i = 0; i < src.size; i++) {
			for (int j = 0; j < src.size; j++) {
				cin >> src.m[i][j];
			}
		}
		return is;
	}

	Massive& operator [](int index) { return m[index]; };
	Massive operator [](int index) const { return m[index]; };
};

void main_310() {
	Matrix2 m1;
	Matrix2 m2;
	cin >> m1;
	cout << m1;
	cin >> m2;
	cout << m2;
	Matrix2 res;
	res = m1 - m2;
	cout << res;
}