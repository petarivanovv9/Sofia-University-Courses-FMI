#include <iostream>

#include "DynamicArray.h"

int main() {

	DynamicArray test;

	//
	// 1: Adding elements to the array
	//
	std::cout << "Adding numbers to the array: ";
	for (int i = 0; i < 10; i++) {
		test.add(i);
		std::cout << i << ", ";
	}
	std::cout << "done\n\n";

	//
	// 2: Getting elements with [] operator
	//
	std::cout << "The array contains: " << test[0];
	for (size_t i = 1; i < test.getLength(); i++) {
		std::cout << ", " << test[i];
	}
	std::cout << "\n\n";

	test.print();
	std::cout << "\n";

	//
	// 3:
	//
	std::cout << "Multiplying each array element by 10...\n";
	for (size_t i = 0; i < test.getLength(); i++) {
		//
		//
		//
		test[i] = test[i] * 10;
	}

	test.print();
	std::cout << "\n";

	//
	// 4:
	//
	std::cout << "Let's go constant!\n";

	const DynamicArray & consTest = test;

	std::cout << "The fifth element is " << consTest[5] << "\n\n"; // this code is correct ...

	// ...but the given code in the next comment will not be compiled:
	// cda[5] = 10;


	//
	// 5: 
	//
	std::cout << "Trying to access an invalid index...\n";
	try {
		test.getAt(test.getLength() + 1);
	}
	catch (std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}


	return 0;
}