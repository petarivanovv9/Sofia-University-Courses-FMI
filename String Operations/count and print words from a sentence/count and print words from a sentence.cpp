//Примерно изпълнение 1:
//Enter a text: One Two Three Four One Two One Two
//One – 3 time(s)
//Two – 3 time(s)
//Three – 1 time(s)
//Fout – 1 time(s)
//Примерно изпълнение 2:
//Enter a text: 8u8 abc123+_+_ *** &yy&a__,bc 8u8
//8u8 – 2 time(s)
//abc123+_+_ - 1 time(s)
//*** - 1 time(s)
//&yy&a__,bc – 1 time(s)
#include <iostream>
#include <cstring>

using namespace std;

int countWords(char *text);
void toWords(const char *text, char **word, int wordsCount);

int main() {

	char text[1000];
	cout << "Enter a text: ";
	cin.getline(text, 1000);

	int sizeText = strlen(text);
	text[sizeText + 1] = '\0';

	cout << "The text is " << text << endl;

	int wordsCount = 0;
	wordsCount = countWords(text);

	cout << "wordsCount: " << wordsCount << endl;

	char **word = new (nothrow) char *[wordsCount];

	toWords(text, word, wordsCount);

	for (size_t i = 0; i < wordsCount; i++) {

		int currentWordCount = 0;
		bool isCounted = false;

		for (size_t j = 0; j < i; j++) {
			if (strcmp(word[i], word[j]) == 0) {
				isCounted = true;
			}
		}

		if (isCounted == false) {
			for (size_t k = i; k < wordsCount; k++) {
				if (strcmp(word[i], word[k]) == 0) {
					currentWordCount++;
				}
			}
			cout << word[i] << " - " << currentWordCount << " time(s)" << endl;
		}

	}

	for (int i = 0; i < wordsCount; i++) {
		delete[] word[i];
	}
	delete[] word;

	return 0;
}

int countWords(char *text) {
	int counter = 0;

	while (*text) {
		while (*text && *text == ' ') {
			text++;
		}
		if (*text) {
			counter++;
		}
		while (*text && *text != ' ') {
			text++;
		}
	}

	return counter;
}

void toWords(const char *text, char **word, int wordsCount) {
	for (size_t i = 0; i < wordsCount; i++) {
		while (*text && *text == ' ') {
			text++;
		}

		const char *endText = NULL;
		int len = 0;

		if (*text) {
			endText = text + 1;
			while (*endText != ' ') {
				endText++;
			}
			len = endText - text;
		}

		if (len > 0) {
			word[i] = new char[len + 1];
			for (size_t pos = 0; pos < len; pos++) {
				word[i][pos] = text[pos];
			}
			word[i][len] = '\0';
			len = 0;
		}

		text = endText;
	}
}
