#pragma once

#include <iostream>
#include <cstring>

const int MAX_WORD_SIZE = 9;

void merge_sort_alphabetically(char** words, size_t size);
void MS(char** words, size_t size, char** buffer);
void merge(char** pA, size_t sizeA, char** pB, size_t sizeB, char** result);


void merge_sort_alphabetically(char** words, size_t size) {
	if (!words || size == 0)
		return;

	char** buffer = new char*[size];

	for (size_t i = 0; i < size; i++) {
		buffer[i] = new (std::nothrow) char[MAX_WORD_SIZE];
	}

	MS(words, size, buffer);

	for (int k = 0; k < size; k++) {
		delete[] buffer[k];
	}
	delete[] buffer;
}

void MS(char** words, size_t size, char** buffer) {
	if (size <= 1)
		return;

	size_t middle = size / 2;

	MS(words, middle, buffer);
	MS(words + middle, size - middle, buffer + middle);

	merge(words, middle, words + middle, size - middle, buffer);

	for (int i = 0; i < size; i++) {
		strcpy(words[i], buffer[i]);
	}
}

void merge(char** pA, size_t sizeA, char** pB, size_t sizeB, char** result) {
	size_t i = 0;
	size_t ia = 0;
	size_t ib = 0;
	//size_t ib = sizeA;

	while (ia < sizeA && ib < sizeB) {
		if (strcmp(pA[ia], pB[ib]) < 0) {
			strcpy(result[i], pA[ia]);
			ia++;
			i++;
		}
		else {
			strcpy(result[i], pB[ib]);
			ib++;
			i++;
		}
	}

	while (ia < sizeA) {
		strcpy(result[i], pA[ia]);
		i++;
		ia++;
	}

	while (ib < sizeB) {
		strcpy(result[i], pB[ib]);
		i++;
		ib++;
	}
}