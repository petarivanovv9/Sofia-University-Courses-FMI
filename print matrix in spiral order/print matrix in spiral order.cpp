#include <iostream>

using namespace std;

int readN(int num) {

	do {
		cin.clear();
		cin.sync();
		cout << "Enter n: ";
		cin >> num;
	} while (!cin.good() || num < 3 || num > 129);

	return num;
}

int main() {

int n;
int counter = 1;

n = readN(n);

int** matrix = new int*[n];

//create the matrix
for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
}

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        matrix[i][j] = counter;
        counter ++;
    }
}

int direction = 0;
int top = 0;
int bottom = n - 1;
int left = 0;
int right = n - 1;

//print the matrix in spiral order
while (top <= bottom && left <= right) {
    if (direction == 0){
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        direction = 1;
    }
    else if (direction == 1) {
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        direction = 2;
    }
    else if (direction == 2) {
        for (int i = right; i >= left; i--) {
            cout << matrix[bottom][i] << " ";
        }
        bottom--;
        direction = 3;
    }
    else {
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
        direction = 0;
    }
}

//delete the matrix
for (int i = 0; i < n; ++i) {
    delete [] matrix[i];
}
delete [] matrix;

return 0;
}
