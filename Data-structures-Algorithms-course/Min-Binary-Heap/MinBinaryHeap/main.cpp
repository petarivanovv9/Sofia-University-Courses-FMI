#include <iostream>

#include "MinHeap.h"

int main() {

	MinHeap test;

	test.insert(11);
	test.insert(16);
	test.insert(15);
	test.insert(10);
	test.insert(9);
	test.insert(17);
	test.insert(12);
	test.insert(14);
	test.insert(13);

	test.printMinHeap();

	std::cout << "Min elem: " << test.extractMin() << std::endl;

	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();
	test.removeMin();

	test.removeMin();

	test.printMinHeap();




	return 0;
}