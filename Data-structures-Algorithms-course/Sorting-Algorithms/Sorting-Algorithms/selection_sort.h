#pragma once

void swapif(int& a, int& b);
void selection_sort(int* pArr, int size);


void swapif(int& a, int& b) {
	if (b < a) {
		int temp(a);
		a = b;
		b = temp;
	}
}

void selection_sort(int* pArr, int size) {
	if (!pArr || size == 0)
		return;

	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (pArr[j] < pArr[min])
				min = j;
		}
		swapif(pArr[i], pArr[min]);
	}
}