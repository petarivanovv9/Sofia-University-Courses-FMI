#include <iostream>

using namespace std;

void diagonalnoObhojdane1(int arr[][5]);
void diagonalnoObhojdane2(int arr[][5]);

int main() {

	int arr[5][5];

	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			cout << "Enter array[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}

	diagonalnoObhojdane1(arr);
	cout << endl;

	diagonalnoObhojdane2(arr);
	cout << endl;

	return 0;
}

// обхождане от долния ляв ъгъл
void diagonalnoObhojdane1(int arr[][5]) {

	for (int k = 4; k >= 0; k--) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == j + k) {
					cout << arr[i][j] << " ";
				}
			}
		}
		cout << endl;
	}

	for (int k = 1; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == i + k) {
					cout << arr[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
}

// обхождане от долния десен ъгъл
void diagonalnoObhojdane2(int arr[][5]) {



	for (int k = 4; k >= 0; k--) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 4; j >= 0; j--) {
				if (i + j == k + 4) {
					cout << arr[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
	for (int k = 3; k >= 0; k--) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 4; j >= 0; j--) {
				if (i + j == k) {
					cout << arr[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
}