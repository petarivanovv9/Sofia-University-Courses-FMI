//Напишете програма, която чете от конзолата две цели числа n, m. Програмата трябва да
//изведе на екрана броя на числата в интервала [n, m] на който сборът на делителите е просто
//число
#include <iostream>
#include <cmath>

using namespace std;

//check is the number is prime
bool isPrime(int num) {

    if (num > 1 && num < 4) {
        return true;
    }

    if (num % 2 == 0 || num == 1) {
        return false;
    }

    int lim = (int) sqrt(num);

    for (int i = 3; i <= lim; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

//get the sum of the divisors
int getDivSum(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {

int n;
int m;
int counter = 0;

cout << "Enter two positive numbers, bigger than 0 and different from each other (n and m)!" << endl;

cout << "Enter n = ";
cin >> n;

cout << "Enter m = ";
cin >> m;

if (n <= 0 || m <= 0 || n == m || m > 1000) {
    cerr << "Wrong input!" << endl;
    return 1;
}

for (int i = n; i <= m; i++) {
    if ( isPrime(getDivSum(i)) ) {
        counter++;
    }
}

cout << "Counter = " << counter << endl;

return 0;
}
