#include <iostream>
#include <iomanip>

using namespace std;

int main() {

int rows;
cout << "Enter the number of rows: ";
cin >> rows;

if (rows <= 0 || rows > 12) {
    cerr << "Wrong input!" << endl;
    return 1;
}

int num = 1;
int arr[rows - 1]; //saving all elements of the last row in the pascal's triangle

for (int j = 0; j <= rows - 1; j++) {
    if (j == 0) {
        num = 1;
        arr[j] = num;
    }
    else {
        num  = num * (rows - 1 - j + 1) / j;
        arr[j] = num;
    }
}

for (int i = 0; i < rows; i++) {
    for (int whiteSpaces = 1; whiteSpaces <= rows - i; whiteSpaces++) {
        cout << "  ";
    }
    for (int j = 0; j <= i; j++) {
        if (j == 0 || i == 0) {
            num = 1;
        }
        else {
            num = num * (i - j + 1) / j;
        }
        cout << "   " << setw(3) << num * arr[i];
    }
    cout << endl << endl;
}

return 0;
}
