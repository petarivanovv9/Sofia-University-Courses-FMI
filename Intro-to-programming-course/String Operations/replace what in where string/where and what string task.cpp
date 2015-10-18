#include <iostream>
#include <cstring>

using namespace std;

const int MAX_WHAT = 20;
const int MAX_WHERE = 100;

int counterWhatInWhere(const char strWhat[], char strWhere[], int sizeWhat, int sizeWhere);
void modifyWhere(char strWhere[], int startIndx, int endIndx);

int main() {

	char strWhat[MAX_WHAT];
	char strWhere[MAX_WHERE];

	cout << "Enter a -what- string: ";
	cin.getline(strWhat, MAX_WHAT);
	
	cout << "Enter a -where- string: ";
	cin.getline(strWhere, MAX_WHERE);

	int sizeWhat = strlen(strWhat);
	strWhat[sizeWhat + 1] = '\0';
	
	int sizeWhere = strlen(strWhere);
	strWhere[sizeWhere + 1] = '\0';

	int counterWhat = 0;
	counterWhat = counterWhatInWhere(strWhat, strWhere, sizeWhat, sizeWhere);

	cout << "counterWhat: " << counterWhat << endl;

	cout << "strWhere was modified: " << strWhere << endl;

	return 0;
}

int counterWhatInWhere(const char strWhat[], char strWhere[], int sizeWhat, int sizeWhere) {
	int counter = 0;
	int startIndx = 0;
	int endIndx = 1;

	for (int i = 0; i < sizeWhere; i++) {
		int k = 0;
		if (strWhere[i] == strWhat[k]) {
			int temp = sizeWhat;
			int j = i;
			bool isHere = true;
			
			while (temp != 0) {
				if (strWhere[j] == strWhat[k]) {
					j++;
					k++;
					isHere = true;
				}
				else {
					isHere = false;
					break;
				}
				temp--;
			}
			if (isHere) {
				counter++;
				startIndx = i;
				endIndx = k;
				modifyWhere(strWhere, startIndx, endIndx);
			}
		}
	}

	return counter;
}

void modifyWhere(char strWhere[], int startIndx, int endIndx) {
	while (startIndx != endIndx) {
		strWhere[startIndx] = '*';
		startIndx++;
	}
}