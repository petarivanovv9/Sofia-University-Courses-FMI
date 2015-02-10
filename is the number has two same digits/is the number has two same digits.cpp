// is the number has two same digits
#include <iostream>

using namespace std;

int main() {

int num = 0;
int counter = 0;

cout << "Enter a number to check is it has two same digits: ";
cin >> num;

int temp = num;

while(temp != 0) {
   temp = temp / 10;
   counter++;
}

int digit = 0;
int i = 0;
temp = num;
int arr[counter];

while(temp != 0) {
    digit = temp % 10;
    temp = temp / 10;
    arr[i] = digit;
    i++;
}

bool sameDigits = false;

for (int i = 0; i < counter; i++) {
    for (int j = i + 1; j < counter; j++) {
        if (arr[i] == arr[j]) {
            sameDigits = true;
            break;
        }
    }
}

if (sameDigits) {
    cout << "The number has two same digits!" << endl;
}
else {
    cout << "There are not same digits!" << endl;
}


return 0;
}
