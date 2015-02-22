// Проверява дали две числа са с еднакви цифри. Примерно за 234 и 342 трябва да изведе TRUE.
// Задачата трябва да бъде направена с рекурсия без използване на цикли.
#include <iostream>

using namespace std;

bool hasSameDig(int num1, int num2);
bool hasDig(int num1, int num2);

int main() {

	int num1 = 0;
	cout << "Enter the first number: ";
	cin >> num1;

	int num2 = 0;
	cout << "Enter the second number: ";
	cin >> num2;

	if (num1 < 0) {
		num1 = -1 * num1;
	}
	if (num2 < 0) {
		num2 = -1 * num2;
	}

	if (hasSameDig(num1, num2)) {
		cout << "TRUE!" << endl;
	}
	else {
		cout << "FALSE!" << endl;
	}

	return 0;
}

bool hasSameDig(int num1, int num2) {
	if (num1 == 0) {
		return true;
	}
	return hasDig(num1 % 10, num2) && hasSameDig(num1 / 10, num2);
}

bool hasDig(int num1, int num2) {
	if (num2 == 0) {
		return false;
	}
	return num1 == num2 % 10 || hasDig(num1, num2 / 10);
}