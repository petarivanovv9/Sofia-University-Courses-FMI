#pragma once

void merge_sort(int* pArr, int size);
void merge_sort_step(int* pArr, int size, int* pBuffer);
void merge(int* pA, int size_A, int* pB, int size_B, int* pResult);


void merge_sort(int* pArr, int size) {
	if (!pArr || size == 0)
		return;
	
	int* pBuffer = new int[size];
	
	merge_sort_step(pArr, size, pBuffer);
	
	delete[] pBuffer;
}

void merge_sort_step(int* pArr, int size, int* pBuffer) {
	if (size <= 1)
		return;
	
	int middle = size / 2;

	merge_sort_step(pArr, middle, pBuffer);

	merge_sort_step(pArr + middle, size - middle, pBuffer + middle);

	merge(pArr, middle, pArr + middle, size - middle, pBuffer);

	for (int i = 0; i < size; i++)
		pArr[i] = pBuffer[i];
}

void merge(int* pA, int size_A, int* pB, int size_B, int* pResult) {
	int i = 0;
	int i_A = 0;
	int i_B = 0;

	while (i_A < size_A && i_B < size_B) {
		pResult[i++] = (pA[i_A] < pB[i_B] ? pA[i_A++] : pB[i_B++]);
	}

	while (i_A < size_A) {
		pResult[i++] = pA[i_A++];
	}

	while (i_B < size_B) {
		pResult[i++] = pB[i_B++];
	}
}