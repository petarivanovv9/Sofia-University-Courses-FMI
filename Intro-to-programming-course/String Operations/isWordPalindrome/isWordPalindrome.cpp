#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STR = 50;

bool isAlpha(char c);
int countLetters(char str[], int sizeStr);
void extractWord(char str[], int sizeStr, char *word);
void isPalindrome(char *word, int counterLetters);

int main() {

	char str[MAX_STR];
	cout << "Enter a word to check is it a polindrome: ";
	cin.getline(str, MAX_STR);

	int sizeStr = strlen(str);
	str[sizeStr + 1] = '\0';

	int counterLetters = countLetters(str, sizeStr);

	char *word = new char[counterLetters];

	extractWord(str, sizeStr, word);

	isPalindrome(word, counterLetters);

	return 0;
}

bool isAlpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	}
	else {
		return false;
	}
}

int countLetters(char str[], int sizeStr) {
	int counter = 0;
	for (size_t i = 0; i < sizeStr; i++) {
		if (isAlpha(str[i])) {
			counter++;
		}
	}
	return counter;
}

void extractWord(char str[], int sizeStr, char *word) {
	int k = 0;

	for (size_t i = 0; i < sizeStr; i++) {
		if (isAlpha(str[i])) {
			word[k] = str[i];
			k++;
		}
	}
	word[k] = '\0';

	cout << "The extracted word from the sentence is: " << word << endl;
}

void isPalindrome(char *word, int counterLetters) {
	bool isPalindrome = true;

	for (size_t i = 0; i < counterLetters; i++) {
		if (word[i] != word[counterLetters - i - 1]) {
			isPalindrome = false;
		}
	}
	if (isPalindrome) {
		cout << "The word is a palindrome!" << endl;
	}
	else {
		cout << "The word is not a palindrome!" << endl;
	}
}