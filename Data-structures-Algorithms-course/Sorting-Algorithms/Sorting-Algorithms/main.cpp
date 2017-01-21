#include <iostream>

using namespace std;

#include "merge_sort.h"
#include "selection_sort.h"


int main() {

	int size = 10;

	/////////////////////////////////////////////////////
	// MERGE SORT - O(nlogn)
	/////////////////////////////////////////////////////

	int pTestArray_1[] = { 1, 9, 6, 7, 1, 3, 2, 1, 5, 0 };
	
	cout << "pTestArray_1:" << endl;
	for (int i = 0; i < size; i++)
		cout << pTestArray_1[i] << " ";
	cout << endl;

	merge_sort(pTestArray_1, size);

	cout << "merge_sort, sorted array:" << endl;
	for (int i = 0; i < size; i++)
		cout << pTestArray_1[i] << " ";
	cout << endl;
	cout << endl;

	/////////////////////////////////////////////////////
	// Selection SORT - O(n^2)
	/////////////////////////////////////////////////////

	int pTestArray_2[] = { 1, 9, 6, 7, 1, 3, 2, 1, 5, 0 };

	cout << "pTestArray_2:" << endl;
	for (int i = 0; i < size; i++)
		cout << pTestArray_2[i] << " ";
	cout << endl;

	selection_sort(pTestArray_2, size);

	cout << "selection_sort, sorted array:" << endl;
	for (int i = 0; i < size; i++)
		cout << pTestArray_2[i] << " ";
	cout << endl;
	cout << endl;


	return 0;
}