#include <iostream>

using namespace std;

int main() {

int numbers[] = {1, 3, 5, 7, 8, 2, 1, 3, 7, 4, 3, 5, 6};
int pos = 0;
int bestPos = 0;
int counter = 1;
int bestCounter = 1;
bool toChange = true;

for (int i = 1; i < 13; i++) {
    if (numbers[i - 1] < numbers[i]) {
        counter++;
        if (toChange  && (counter < bestCounter)) {
            pos = i - 1;
            toChange = false;
        }
    }
    else {
        toChange = true;
        if (counter > bestCounter) {
            bestCounter = counter;
            counter = 1;
        }
        if (toChange) {
            bestPos = pos;
            pos = i;
        }
    }
}

cout << "Best counter: " << bestCounter << endl;
cout << endl;
cout << "Best position: " << bestPos << endl;
cout << endl;

for (int i = bestPos; i < bestPos + bestCounter; i++) {
    cout << numbers[i] << " ";
}
cout << endl;

return 0;
}
