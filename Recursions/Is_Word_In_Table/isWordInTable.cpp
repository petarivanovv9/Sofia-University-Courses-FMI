#include <iostream>
#include <cstring>

using namespace std;

int readN();
int readM(int n);
int readT();
void copyString(char *destStr, char *fromStr);
bool isWordInTable(char **table, char *word, int row, int col, char **table_copy);
bool isWordSnakeDiagonal(char **table_copy, char *word_copy, int row, int col, int x, int y, int wordLen);

int main() {

	int n; // rows
	int m; // cols
	int t;

	n = readN(); // rows
	m = readM(n); // cols
	t = readT();

	char** table = new char *[n];

	for (int i = 0; i < n; i++) {
		table[i] = new char[m];
	}

	char** table_copy = new char *[n];

	for (int i = 0; i < n; i++) {
		table_copy[i] = new char[m];
	}

	cout << "Enter letters: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//std::cout << "Enter a letter in the table[" << i << "][" << j << "] = ";
			std::cin >> table[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << "\n";
	}

	int maxWord = n * m;
	char* word = new char[maxWord];

	for (int i = 0; i < t; i++) {
		std::cout << "Enter a word: ";
		std::cin >> word;
		
		// copy the table
		for (int i = 0; i < n; i++) {
			copyString(table_copy[i], table[i]);
		}
		if (isWordInTable(table, word, n, m, table_copy)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}

	for (int i = 0; i < n; i++) {
		delete[] table[i];
	}
	delete[] table;

	for (int i = 0; i < n; i++) {
		delete[] table_copy[i];
	}
	delete[] table_copy;

	delete[] word;

	return 0;
}

int readN() {
	int n = 0;
	do {
		std::cin.clear();
		std::cin.sync();
		std::cout << "Enter n: ";
		std::cin >> n;
	} while (!std::cin.good() || n < 4 || n > 99);

	return n;
}

int readM(int n) {
	int m = 0;
	do {
		std::cin.clear();
		std::cin.sync();
		std::cout << "Enter m: ";
		std::cin >> m;
	} while (!std::cin.good() || m < n || m > 99);

	return m;
}

int readT() {
	int t = 0;
	do {
		std::cin.clear();
		std::cin.sync();
		std::cout << "Enter t: ";
		std::cin >> t;
	} while (!std::cin.good() || t < 1);

	return t;
}

void copyString(char *destStr, char *fromStr) {
	int counter = 0;

	while (fromStr[counter] != '\0') {
		destStr[counter] = fromStr[counter];
		counter++;
	}
	destStr[counter] = '\0';
}

bool isWordInTable(char **table, char *word, int row, int col, char **table_copy) {
	bool isWordHere = false;
	int wordLen = strlen(word);
	char *word_copy = new char(wordLen + 1);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (table_copy[i][j] == *word) {
				if (isWordHere == false) {
					copyString(word_copy, word);
					isWordHere = isWordSnakeDiagonal(table_copy, word_copy, row, col, i, j, wordLen);
					// copy the table
					for (int k = 0; k < row; k++) {
						copyString(table_copy[k], table[k]);
					}
				}
			}
		}
	}
	return isWordHere;
}

bool isWordSnakeDiagonal(char **table_copy, char *word_copy, int row, int col, int x, int y, int wordLen) {

	*word_copy = '*';
	table_copy[x][y] = '*';
	
	//надясно
	if (y + 1 < col && *word_copy && table_copy[x][y + 1] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x, y + 1, wordLen);
	}
	//надолу-надясно
	if (x + 1 < row && y + 1 < col && *word_copy && table_copy[x + 1][y + 1] == *(word_copy + 1) ) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x + 1, y + 1, wordLen);
	}
	//надолу
	if (x + 1 < row && *word_copy && table_copy[x + 1][y] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x + 1, y, wordLen);
	}
	//надолу-наляво
	if (x + 1 < row && y - 1 >= 0 && *word_copy && table_copy[x + 1][y - 1] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x + 1, y - 1, wordLen);
	}
	//наляво
	if (y - 1 >= 0 && *word_copy && table_copy[x][y - 1] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x, y - 1, wordLen);
	}
	//нагоре-наляво
	if (x - 1 >= 0 && y - 1 >= 0 && *word_copy && table_copy[x - 1][y - 1] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x - 1, y - 1, wordLen);
	}
	//нагоре-надясно
	if (x - 1 >= 0 && y + 1 < col && *word_copy && table_copy[x - 1][y + 1] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x - 1, y + 1, wordLen);
	}
	//нагоре
	if (x - 1 >= 0 && *word_copy && table_copy[x - 1][y] == *(word_copy + 1)) {
		isWordSnakeDiagonal(table_copy, word_copy + 1, row, col, x - 1, y, wordLen);
	}
	if ( *(word_copy + wordLen - 1) == '*' ) {
		return true;
	}
	else {
		return false;
	}
}