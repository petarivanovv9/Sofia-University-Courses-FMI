// Petar Ivanov, Faculty number: 45121
// Informatics, group 1,
// OOP Homework 3

#include "Vector.h"
#include "BooleanVector.h"
#include <iostream>

int main() {
	
	Vector v1;
	v1.addValuesToVector();
	v1.printVector();
	
	std::cout << "\n";

	int currentIndex = 0;
	std::cout << "Enter an index of the vector you want to get: ";
	std::cin >> currentIndex;

	std::cout << "v1[" << currentIndex << "] = " 
					<< v1[currentIndex] << "\n";

	std::cout << "v1[10] = " << v1[10] << "\n";

	std::cout << "v1[4] = " << v1[4] << "\n";

	std::cout << "\n";

	Vector v2;
	v2.addValuesToVector();
	v2.printVector();
	std::cout << "\n";

	v2 += v1;
	v2.printVector();
	std::cout << "\n";

	v1.printVector();
	std::cout << "\n";

	Vector v3;
	v3 = v1 + v2;
	v3.printVector();

	Vector v4;
	v4 = v3 - v1;
	v4.printVector();
	std::cout << "\n";

	Vector v5;
	v5 -= v2;
	v5.printVector();
	std::cout << "\n";

	Vector v6;
	v6.addValuesToVector();
	v6 *= 2.2;
	v6.printVector();
	std::cout << "\n";

	Vector v7;
	v7 = v6 * 2.5;
	v7.printVector();
	std::cout << "\n";
	
	Vector v8(v6);
	v8 /= 0;
	v8.printVector();
	std::cout << "\n";

	Vector v9;
	v9.addValuesToVector();
	v9.printVector();
	std::cout << "\n";

	Vector v10;
	v10.addValuesToVector();
	v10.printVector();
	
	double scalar_product = v10 % v9;
	std::cout << "SCALAR PRODUCT: " << scalar_product << "\n";

	std::cout << "\n";
	v9.printVector();
	v10.printVector();
	std::cout << "\n";

	std::cout << std::endl;
	std::cout << "---------FOR BOOLEAN VECTOR---------" << std::endl;
	std::cout << std::endl;

	BooleanVector bv1;
	bv1.addValueToVector();
	bv1.printVector();
	
	std::cout << "\n";


	currentIndex = 0;
	std::cout << "Enter an index of the vector you want to set: ";
	std::cin >> currentIndex;

	bv1.set(currentIndex);
	bv1.printVector();

	std::cout << "\n";

	std::cout << "Enter an index of the vector you want to clear: ";
	std::cin >> currentIndex;

	bv1.clear(currentIndex);
	bv1.printVector();

	std::cout << "\n";

	std::cout << "Enter an index of the vector you want to get: ";
	std::cin >> currentIndex;

	std::cout << bv1[currentIndex] << "\n";
	std::cout << "\n";


	return 0;
}