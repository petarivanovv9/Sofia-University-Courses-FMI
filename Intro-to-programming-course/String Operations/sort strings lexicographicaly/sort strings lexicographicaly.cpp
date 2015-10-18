#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char str[10][50];
	char temp[50];

	for (size_t i = 0; i < 10; i++) {
		cout << "str[" << i << "] = ";
		cin.getline(str[i], 50);
	}

	for (size_t i = 0; i < 9; i++) {
		for (size_t j = i + 1; j < 10; j++) {
			if ( strcmp(str[i], str[j]) > 0 ) {
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}

	cout << "In lexicographical order: " << endl;
	
	for (size_t i = 0; i < 10; i++) {
		cout << str[i] << endl;
	}

	return 0;
}