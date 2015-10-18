// getting all numbers that have 5
#include <iostream>

using namespace std;

int main() {

int m = 10;
int n = 153;


for (int i = m; i <= n; i++) {
    int temp = i;

    while(temp != 0) {
        if (temp % 10 == 5) {
            cout << i << " ";
            break;
        }
        else {
            temp = temp / 10;
        }
    }

}
cout << endl;

return 0;
}
