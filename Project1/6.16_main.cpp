#include "main.h"

class MyMap {
private:
	vector<string> keys;
	vector<float> values;
	int size;
public:
	explicit MyMap(int j = 0) : size(0), keys(0), values(0) {
		size = j;
		keys = vector<string>(size);
		values = vector<float>(size);
	}

	MyMap(const MyMap& src) {
		size = src.size;
		keys = src.keys;
		values = src.values;
	}

	MyMap& append(string key, float value) {
		keys.push_back(key);
		values.push_back(value);
		return *this;
	}

	friend istream& operator>>(istream& is, MyMap& r) {
		string key;
		float value;
		for (int i = 0; i < r.size; i++) {
			cout << "Введите ключ и значение через пробел: ";
			cin >> key >> value;
			r.append(key, value);
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, MyMap& r) {
		for (int i = r.size; i < r.size*2; i++) {
			os << "'" << r.keys[i] << "': " << r.values[i] << endl;
		}
		return os;
	}

	float operator[](string key) const {
		for (int i = 0; i < size; i++) {
			if (keys[i] == key){
				return values[i];
			}
		}
	}

	float& operator[](string key) {
		for (int i = size; i < size*2; i++) {
			if (keys[i] == key) {
				return values[i];
			}
		}
	}
};

void main_616() {
	MyMap m(3);
	cin >> m;
	cout << m;
	cout << m["c"];
}