//Да се дефинира рекурсивна функция, която проверява дали елементите на редица са трион,
//т.е. имат вида a0  > a1 < a2 > a3 < ...
#include <iostream>

using namespace std;

bool isTrion(int *arr, int i, int n);

int main() {

	int n = 0;
	cout << "numbers: ";
	cin >> n;

	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	if (isTrion(arr, 1, n)) {
		cout << "marti e boginq!" << endl;
	}
	else {
		cout << "smert!" << endl;
	}

	delete[] arr;

	return 0;
}
// a0  > a1 < a2 > a3 <
bool isTrion(int *arr, int i, int n) {
	if (i == n - 1) {
		return true;
	}

	if (i % 2 == 0) {
		if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) {
			return false;
		}
	}
	else {
		if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
			return false;
		}
	}
	return isTrion(arr, i + 1, n);

}
