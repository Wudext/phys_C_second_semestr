#include "main.h"

void main() {
	double task;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите задачу: ";
	cin >> task;
	if (task == 1.1) {
		main_11();
	}
	if (task == 1.3) {
		main_13();
	}
}