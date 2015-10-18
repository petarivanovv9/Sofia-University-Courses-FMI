//Напишете програма, която чете от конзолата цяло число n. Програмата трябва да изведе на
//екрана ромб от числа. Първият ред трябва да съдържа само числото n/2 , всеки следващ ред
//трябва да съдържа 2 числа, редът n/2 трябва да съдържа всички числа от 1 до n, след което броят
//им намалява с 2 на всеки ред.
//Например:
 //2 3
//1 2 3 4
//1 2 3 4
// 2 3
//или
 //3
// 2 3 4
//1 2 3 4 5
// 2 3 4
// 3
#include <iostream>

using namespace std;

int main() {

int n;

cout << "Enter positive number ( n >= 3 and n <= 20 ): ";
cin >> n;

if (n <= 2 || n > 20) {
    cerr << "Wrong input!" << endl;
    return 1;
}

int counter = 1; //counting the whitespaces on a row

//maka an interval with these two variables - stepPos and stepPos2
int stepsPos = n / 2;
int stepsPos2 = n / 2 + 1;

bool revrs = false; //to know when to reverse the interval in order to start making it smaller

//when the number is even
if (n % 2 == 0) {
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            //check when to reverse the interval
            if ( (row == n / 2) || (row == n / 2 + 1) ) {
                cout << " " << col << " ";
                revrs = true;
                stepsPos = 1;
                stepsPos2 = n;
            }
            else {
                //printing the numbers in the interval
                if ( (counter >= stepsPos) && (counter <= stepsPos2) ) {
                    cout << " " << col << " ";
                    counter++;
                }
                else {
                    cout << "   ";
                    counter++;
                }
            }
        }
        //reverse the interval in order to start making it smaller
        if (revrs){
            stepsPos++;
            stepsPos2--;
        }
        //making the interval bigger
        else {
            stepsPos--;
            stepsPos2++;
        }
        counter = 1;
        cout << endl;
    }
}
//when the number is odd
else {
    //reset the variables
    counter = 1;
    stepsPos = n / 2 + 1;
    stepsPos2 = n / 2 + 1;
    revrs = false;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if ( row == n / 2 + 1 ) {
                cout << " " << col << " ";
                revrs = true;
                stepsPos = 1;
                stepsPos2 = n;
            }
            else {
                if ( (counter >= stepsPos) && (counter <= stepsPos2) ) {
                    cout << " " << col << " ";
                    counter++;
                }
                else {
                    cout << "   ";
                    counter++;
                }
            }
        }
        if (revrs) {
            stepsPos++;
            stepsPos2--;
        }
        else {
            stepsPos--;
            stepsPos2++;
        }
        counter = 1;
        cout << endl;
    }
}

return 0;
}
