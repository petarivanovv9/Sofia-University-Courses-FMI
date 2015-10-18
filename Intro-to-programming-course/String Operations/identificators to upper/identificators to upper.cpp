//За всеки валиден идентификатор (за езика C++) в str променете първата му буква със съответната главна.
#include <iostream>
#include <cctype>

const int MAX_SIZE = 500;

void idenficatorsToUpper(char *str);
bool isValidIdentificator(char *str);

bool isLower(char c);
char toUpper(char c);
bool isAlpha(char c);
bool isAlphaNum(char c);

int countWords(const char* str);
void toWords(const char *sentence, char **word);

int main() {

	char identificators[MAX_SIZE];

	std::cout << "Enter an identificator: ";
	std::cin.getline(identificators, MAX_SIZE);

	int size = strlen(identificators);
	identificators[size + 1] = '\0';

	char **word = NULL;
	int wordsCount = countWords(identificators);
	word = new char *[wordsCount];

	char *result = identificators;

	toWords(identificators, word);

	idenficatorsToUpper(result);

	for (int i = 0; i < wordsCount; i++) {
		delete[] word[i];
	}
	delete[] word;

	return 0;
}


void idenficatorsToUpper(char *str) {
	bool toChange = true;
	char *start = str;

	if (isValidIdentificator(str)) {
		while (*str && (*str == '_' || *str == ' ')) {
			str++;
		}
		while (*str) {
			if (isAlpha(*str)) {
				*str = toUpper(*str);
				toChange = false;
				break;
			}
			str++;
		}
		str = start;
		std::cout << "Result: " << str << "\n";
	}
	else {
		std::cerr << "The identificator " << str << " is not valid!" << "\n";
	}

}

bool isValidIdentificator(char *str) {
	int counter = 0;
	while (*str && (*str == ' ' || *str == '_')) {
		str++;
		counter++;
	}

	if ((str[0] >= '0' && str[0] <= '9') || (str[counter] >= '0' && str[counter] <= '9')) {
		return false;
	}

	while (*str) {
		if (*str == '<' || *str == '>' || *str == '-' || *str == '='
			|| *str == '/' || *str == '*' || *str == '%') {
			return false;
			break;
		}
		str++;
	}

	return true;
}

bool isLower(char c) {
	if (c >= 'a' && c <= 'z') {
		return true;
	}
	else {
		return false;
	}
}

char toUpper(char c) {
	if (!isLower(c)) {
		return c;
	}
	else {
		return c - 'a' + 'A';
	}
}

bool isAlpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
		return true;
	}
	else {
		return false;
	}
}

bool isAlphaNum(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')) {
		return true;
	}
	else {
		return false;
	}
}

int countWords(const char* str) {
	if (str == NULL)
		return 1;

	bool inSpaces = true;
	int numWords = 0;

	while (*str != NULL) {
		if (std::isspace(*str))
		{
			inSpaces = true;
		}
		else if (inSpaces)
		{
			numWords++;
			inSpaces = false;
		}
		++str;
	}

	return numWords;
}

void toWords(const char *sentence, char **word) {
	int wordsCount = countWords(sentence);

	for (int i = 0; i < wordsCount; i++) {
		while (*sentence && (!isAlphaNum(*sentence))) {
			sentence++;
		}

		const char *end = NULL;
		int len = 0;

		if (*sentence) {
			end = sentence + 1;
			while (*end && (isAlphaNum(*end) || *end != ' ')) {
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

		idenficatorsToUpper(word[i]);

		sentence = end;
	}
}
