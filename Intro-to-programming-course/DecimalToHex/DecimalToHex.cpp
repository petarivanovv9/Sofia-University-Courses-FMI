#include <iostream>

using namespace std;

void decimalToHex(unsigned long number, char *arr, int k);

int main() {

	unsigned long number;

	cout << "Enter a number: ";
	cin >> number;

	int counter = 0;

	unsigned long temp = number;

	while (temp != 0) {
		temp = temp / 16;
		counter++;
	}

	char *result = new (std::nothrow) char[counter + 1];
	result[counter] = '\0';

	if (!result) {
		cerr << "ERROR!" << endl;
		return 1;
	}
	
	decimalToHex(number, result, 0);

	for (int i = counter - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] result;

	return 0;
}

void decimalToHex(unsigned long number, char *result, int k) {
	int remainder = 0;

	while (number != 0) {

		remainder = number % 16;

		if (remainder > 9) {
			result[k] = (char)(remainder + 55);
		}
		else {
			result[k] = remainder + '0';
		}

		number = number / 16;

		k++;
	}
}