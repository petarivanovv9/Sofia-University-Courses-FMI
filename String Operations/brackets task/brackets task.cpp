#include <iostream>
#include <string>

using namespace std;

int main() {

string brackets = "";
int counterLeft = 0;
int counterRight = 0;

cout << "Enter brackets: ";
cin >> brackets;

if ((brackets.length() % 2) != 0) {
    cerr << "It is not correct!" << endl;
    return 1;
}
for (int i = 0; i < brackets.length(); i++) {
    if ( (brackets[0] != '(') && (brackets[brackets.length() - 1] != ')') ) {
        cerr << "It is not correct!" << endl;
        return 1;
        }
    }
for (int i = 0; i < brackets.length() / 2; i++) {
    if (brackets[i] == '(') {
        counterLeft++;
    }
    }
for (int i = brackets.length() / 2; i < brackets.length(); i++) {
    if (brackets[i] == ')') {
            counterRight++;
    }
    }
if (counterLeft == counterRight) {
    cout << "SUCCESSFUL" << endl;
    }
else {
    cerr << "It is not correct!" << endl;
    }


return 0;
}
