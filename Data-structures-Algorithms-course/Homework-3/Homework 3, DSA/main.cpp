///
///  main.cpp : Defines the entry point for the console application.
///  Homework 3
///
///  Created by Petar Ivanov with #45121 on 13/12/2015.
///

#include <iostream>
#include <cstring>

#include "merge_sort_alphabetically.h"
#include "Trie.h"

//const int MAX_WORD_SIZE = 9;
const int MAX_COMMAND_SIZE = 7;

void readWords(int, char**);
void clearWords(char**, int);

int main() {

	int t, n, q;
	std::cin >> t;

	char** words = NULL;
	int counter = 0;

	for (size_t i = 0; i < t; i++) {
		std::cin >> n >> q;
		counter = 0;
		words = new (std::nothrow) char*[n];
		readWords(n, words);
		if (words == NULL) {
			return 1;
		}

		///
		/// Use merge sort in order to sort words alphabetically.
		/// It takes O(nlogn) time and it's a stable sort.
		///
		merge_sort_alphabetically(words, n);

		int a = 0;
		int b = n - 1;
		bool isNewInterval = false;

		///
		/// Make a trie from the words
		/// The trie can insert and find strings in O(N) time (where N represent the length of a single word)
		/// but it requires more memory
		///
		Trie* trie = new Trie();

		for (size_t k = 0; k < q; k++) {
			counter = 0;
			char command[MAX_COMMAND_SIZE];
			std::cin >> command;

			if (strncmp(command, "ENTER", 5) == 0) {
				std::cin >> a >> b;

				///
				/// Make new trie for the specific interval of words
				///
				Trie* newIntervalTrie = new Trie();
				for (size_t j = a; j < b + 1; j++) {
					newIntervalTrie->addWord(words[j]);
				}
				trie = newIntervalTrie;
				isNewInterval = true;
			}
			///
			/// If there is no interval entered, we make
			/// a trie in the entire interval.
			///
			if (isNewInterval == false) {
				for (size_t j = a; j < b + 1; j++) {
					trie->addWord(words[j]);
				}
				isNewInterval = true;
			}
			if (strncmp(command, "QUERY", 6) == 0) {
				char prefix[MAX_WORD_SIZE];
				std::cin >> prefix;

				counter = trie->searchPrefix(prefix);
				//std::cout << "------result: " << counter << std::endl;
				std::cout << counter << std::endl;
			}
		}

		///
		/// Delete the used memory for the words.
		///
		clearWords(words, n);
	}

	return 0;
}

void readWords(int n, char** words) {
	for (size_t i = 0; i < n; i++) {
		words[i] = new (std::nothrow) char[MAX_WORD_SIZE];
	}

	for (size_t i = 0; i < n; i++) {
		char buffer[MAX_WORD_SIZE];
		std::cin >> buffer;
		strncpy(words[i], buffer, MAX_WORD_SIZE);
	}
}

void clearWords(char** words, int n) {
	for (int k = 0; k < n; k++) {
		delete[] words[k];
	}
	delete[] words;
}
