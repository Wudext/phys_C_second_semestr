#include "main.h"

const int N = 2;

class M {
private:
	int* m;
	int len;
public:
	explicit M(int N = 2) : len(0), m(0) {
		if (N > 0) {
			m = new int(N);
		}
		if (m) {
			len = N;
		}
	}

	M(const M& temp) {
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

	M& operator=(const M& src) {
		len = src.len;
		m = new int[len];
		for (int i = 0; i < len; i++) {
			m[i] = src.m[i];
		}
		return *this;
	}

	M& operator+=(const M& src) {
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

	M& operator-=(const M& src) {
		for (int i = 0; i < src.len; i++) {
			if (m[i]) {
				m[i] -= src.m[i];
			}
		}
		return *this;
	}

	M& operator*=(const M& src) {
		for (int i = 0; i < src.len; i++) {
			if (m[i]) {
				m[i] *= src.m[i];
			}
		}
		return *this;
	}

	M operator+(const M& src) {
		M res(*this);
		res += src;
		return res;
	}

	M operator-(const M& src) {
		M res(*this);
		res -= src;
		return res;
	}

	M operator*(const M& src) {
		M res(*this);
		res *= src;
		return res;
	}

	int& operator [](int index) { return m[index]; };
	int operator [](int index) const { return m[index]; };

	friend ostream& operator<<(ostream& os, const M& src) {
		os << "[";
		for (int i = 0; i < src.len; i++) {
			cout << src.m[i] << ", ";
		}
		os << "]" << endl;
		return os;
	}

	friend istream& operator>>(istream& is, M& src) {
		cout << "Введите массив: " << endl;
		for (int i = 0; i < src.len; i++) {
			cin >> src.m[i];
		}
		return is;
	}
};

class MN: public M {
private:
	size_t size;
	M* a;
public:
	explicit MN(int N = 0) : a(0), size(N) {
		if (N > 0) {
			a = new M[size]; //Строчки
			for (int i = 0; i < size; i++) {
				a[i] = M(size); //Столбцы
			}
			if (a) size = N;
		}
	}

	MN(const MN& temp) : a(0), size(0) {
		if (temp.size > 0) {
			a = new M[temp.size];
			for (int i = 0; i < temp.size; i++) {
				a[i] = M(temp.size);
			}
		}
		if (a) {
			size = temp.size;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					a[i][j] = temp.a[i][j];
				}
			}
		}
	}

	MN& operator=(const MN src) {
		size = src.size;
		a = new M[size];
		for (int i = 0; i < size; i++) {
			a[i] = M(size);
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] = src.a[i][j];
			}
		}
		return *this;
	}

	MN& operator+=(const MN& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] += src.a[i][j];
			}
		}
		return *this;
	}

	MN& operator-=(const MN& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] -= src.a[i][j];
			}
		}
		return *this;
	}

	MN& operator*=(const MN& src) {
		MN n(src.size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				n.a[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					n.a[i][j] += a[i][k] * src.a[k][j];
				}
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] = n.a[i][j];
			}
		}
		return *this;
	}

	MN operator+(const MN& src2) const {
		MN res(*this);
		res += src2;
		return res;
	}

	MN operator-(const MN& src2) const {
		MN res(*this);
		res -= src2;
		return res;
	}

	MN operator*(const MN& src2) const {
		MN res(*this);
		res *= src2;
		return res;
	}

	friend istream& operator>>(istream& is, MN& src) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				is >> src.a[i][j];
			}
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, MN& r) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				os << r.a[i][j] << " ";
				if (j % r.size == r.size - 1) {
					os << endl;
				}
			}
		}
		return os;
	}

	M& operator [](int index) { return a[index]; };
	M operator [](int index) const { return a[index]; };
};

void main_319() {
	MN m1(N);
	MN m2(N);
	cin >> m1;
	cout << m1;
	cin >> m2;
	cout << m2;
	MN res = m1 * m2;
	cout << res;
}
