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
	if (task == 2.1) {
		main_21();
	}
	if (task == 2.25) {
		main_225();
	}
	if (task == 3.10) {
		main_310();
	}
	if (task == 3.19) {
		main_319();
	}
}