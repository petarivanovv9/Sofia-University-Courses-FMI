#include <iostream>

#include "BST.h"

int main() {

	BST test;
	
	test.insertValue(19);
	test.insertValue(4);
	test.insertValue(20);
	test.insertValue(2);
	test.insertValue(15);
	test.insertValue(3);
	test.insertValue(9);
	test.insertValue(1);

	test.print();
	
	std::cout << std::endl;
	
	if (test.searchValue(7)) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	if (test.removeValue(4)) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	test.print();

	std::cout << std::endl;

	std::cout << (test.root->left->left->right == NULL) << std::endl;
	
	std::cout << (test.root->left->right->value) << std::endl;


	return 0;
}