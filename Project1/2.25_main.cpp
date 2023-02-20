#include "main.h"

const int N = 2;

class MatrixN {
private:
	size_t size;
	int** a;
public:
	explicit MatrixN(int N = 0) : a(0), size(N) {
		if (N > 0) {
			a = new int*[size]; //Строчки
			for (int i = 0; i < size; i++) {
				a[i] = new int[size]; //Столбцы
			}
			if (a) size = N;
		}
	}

	MatrixN(int ** temp, int s) : a(temp), size(s) {
		if (s > 0) {
			a = new int* [s];
			for (int i = 0; i < s; i++) {
				a[i] = new int[s];
			}
		}
		if (a) {
			size = s;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					a[i][j] = temp[i][j];
				}
			}
		}
	}


	MatrixN(const MatrixN& temp) : a(0), size(0) {
		if (temp.size > 0) {
			a = new int* [temp.size];
			for (int i = 0; i < temp.size; i++) {
				a[i] = new int[temp.size];
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

	MatrixN& operator=(const MatrixN src) {
		size = src.size;
		a = new int* [size];
		for (int i = 0; i < size; i++) {
			a[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] = src.a[i][j];
			}
		}
		return *this;
	}

	MatrixN& operator+=(const MatrixN& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] += src.a[i][j];
			}
		}
		return *this;
	}

	MatrixN& operator-=(const MatrixN& src) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] -= src.a[i][j];
			}
		}
		return *this;
	}

	MatrixN& operator*=(const MatrixN& src) {
		MatrixN n(src.size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				n.a[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					n.a[i][j] += a[i][k]*src.a[k][j];
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

	bool null() {
		for (int i = 0; i < size*size; i++) {
			if (a[i] != 0) {
				return false;
			}
		}
		return true;
	}

	MatrixN operator+(const MatrixN& src2) const {
		MatrixN res(*this);
		res += src2;
		return res;
	}

	MatrixN operator-(const MatrixN& src2) const {
		MatrixN res(*this);
		res -= src2;
		return res;
	}

	MatrixN operator*(const MatrixN& src2) const {
		MatrixN res(*this);
		res *= src2;
		return res;
	}

	friend istream& operator>>(istream& is, MatrixN& r) {
		int** input = new int*[N];
		for (int i = 0; i < N; i++) {
			input[i] = new int[N];
			for (int j = 0; j < N; j++) {
				is >> input[i][j];
			}
		}
		r = MatrixN(input, N);
		return is;
	}

	friend ostream& operator<<(ostream& os, MatrixN& r) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				os << r.a[i][j] << " ";
				if (j % r.size == r.size-1) {
					os << endl;
				}
			}
		}
		return os;
	}
};

class MatrixVector {
private:
	int len;
	MatrixN* m;
public:
	explicit MatrixVector(int N = 0) : m(0), len(0) {
		if (N > 0) {
			m = new MatrixN(N);
			len = N;
		}
	}

	MatrixVector(const MatrixVector& temp) : m(0), len(0) {
		if (temp.len > 0) m = new MatrixN(temp.len);
		if (m) {
			len = temp.len;
			for (int i = 0; i < len; i++) {
				m[i] = temp.m[i];
			}
		}
	}

	MatrixN& operator [](int index) { return m[index]; };
	MatrixN operator [](int index) const { return m[index]; };

	MatrixVector append(int index, const MatrixN& addition) {
		MatrixN tmp;
		MatrixN replace = addition;
		for (int i = index; i < len; i++) {
			cout << m[i] << endl;
			if (m[i].null()) {
				m[i] = replace;
				return *this;
			}
			tmp = m[i];
			m[i] = replace;
			replace = tmp;
		}
		this->len += 1;
		m[len-1] = replace;
		return *this;
	}

	MatrixVector del(int index) {
		MatrixN tmp;
		for (int i = index; i < len; i++) { m[i] = m[i + 1];}
		this->len -= 1;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const MatrixVector& src) {
		os << "Your Vector is:" << endl;
		for (int i = 0; i < src.len; i++) {
			cout << src.m[i] << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, MatrixVector& src) {
		cout << "Введите массив матриц: " << endl;
		for (int i = 0; i < src.len; i++) {
			cin >> src.m[i];
		}
		return is;
	}
};

void main_225() {
	//MatrixN first(N), second(N);
	//cout << "Введите первую матрицу: ";
	//cin >> first;
	//cout << first;
	//cout << "Введите вторую матрицу: ";
	//cin >> second;
	//cout << second;
	//MatrixN res(N);
	//res = first + second;
	//cout << endl << "Сумма:" << endl << res;
	//res = first - second;
	//cout << endl << "Разность:" << endl << res;
	//res = first * second;
	//cout << endl << "Произведение:" << endl << res;

	MatrixVector PtArray(N);
	MatrixVector* VMartix;
	MatrixN addition;
	cin >> PtArray;
	cout << PtArray;
	cin >> addition;
	PtArray.append(0, addition);
	cout << PtArray;
	PtArray.del(0);
	cout << PtArray;
}