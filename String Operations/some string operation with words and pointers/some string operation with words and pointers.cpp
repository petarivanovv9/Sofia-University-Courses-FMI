//Потребителят въвежда цяло число N и речник с N думи (с максимална дължина 16
//символа). След това въвежда символен низ. Вашата програма трябва да направи нов символен
//низ, който съдържа всички думи от изходния символен низ, които се срещат в речника, но
//написани на обратно. В резултата записаните думи трябва да са в същия ред, както и в
//изходният символен низ. Резултатът трябва да е записан в динамична памет с точната
//големина
#include <iostream>
#include <cstring>

const int MAX_SENTENCE = 500;

int readN();
bool isAlpha(char c);
int wordCount(const char *sentence);
int toWords(const char *sentence, char **word, const char dictionary[][16], int n, char **&result);
char *strRev(char* str);

int main() {

	int n;
	n = readN();

	char dictionary[50][16];

	for (size_t i = 0; i < n; i++) {
		std::cout << "Enter a word in the dictionary: ";
		std::cin.clear();
		std::cin.sync();
		std::cin.getline(dictionary[i], 17);
	}
	std::cout << "\n";

	char sentence[MAX_SENTENCE];
	std::cout << "Enter a sentence: ";
	std::cin.getline(sentence, MAX_SENTENCE);

	int counterWords;
	int counterSameW;

	char **word = NULL;
	counterWords = wordCount(sentence);
	word = new char *[counterWords];

	char **result = NULL;

	counterSameW = toWords(sentence, word, dictionary, n, result);

	//delete memory
	for (int i = 0; i < counterWords; i++) {
		delete[] word[i];
	}
	delete[] word;

	for (int i = 0; i < counterSameW; i++) {
		delete[] result[i];
	}
	delete[] result;

	return 0;
}

int readN() {
	int n = 0;
	do {
		std::cin.clear();
		std::cin.sync();
		std::cout << "Enter n: ";
		std::cin >> n;
	} while (!std::cin.good() || n < 1 || n > 10);

	return n;
}

bool isAlpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	}
	else {
		return false;
	}
}

int wordCount(const char *sentence) {
	int counter = 0;

	while (*sentence != '\0') {
		while ((*sentence != '\0') && (!isAlpha(*sentence))) {
			sentence++;
		}
		if (*sentence != '\0') {
			counter++;
		}
		while (isAlpha(*sentence)) {
			sentence++;
		}
	}

	return counter;
}

int toWords(const char *sentence, char **word, const char dictionary[][16], int n, char **&result) {
	int wordsCount = wordCount(sentence);
	int cnt = 0;

	for (int i = 0; i < wordsCount; i++) {
		while (*sentence && (!isAlpha(*sentence))) {
			sentence++;
		}

		const char *end = NULL;
		int len = 0;

		if (*sentence) {
			end = sentence + 1;
			while (isAlpha(*end)) {
				end++;
			}
			len = end - sentence;
		}

		if (len > 0) {
			word[i] = new char[len + 1];
			for (int pos = 0; pos < len; pos++) {
				word[i][pos] = sentence[pos];
			}
			word[i][len] = '\0';
			len = 0;
		}

		sentence = end;
	}

	for (size_t i = 0; i < wordsCount; i++) {
		for (size_t j = 0; j < n; j++) {
			if (strcmp(word[i], dictionary[j]) == 0) {
				cnt++;
			}
		}
	}

	result = new char*[cnt];
	size_t indx = 0;

	std::cout << "The result is:";
	for (size_t i = 0; i < wordsCount; i++) {
		for (size_t j = 0; j < n; j++) {
			if (strcmp(word[i], dictionary[j]) == 0) {
				result[indx] = new char[strlen(word[i]) + 1];
				strcpy(result[indx], word[i]);
				strRev(result[indx]);
				std::cout << " " << result[indx];
				indx++;
			}
		}

	}
	std::cout << "\n";

	return cnt;
}

char *strRev(char *str) {
	char temp;
	char *start;
	char *end;

	start = str;
	end = &str[strlen(str) - 1];

	while (end > start) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

	return str;
}
