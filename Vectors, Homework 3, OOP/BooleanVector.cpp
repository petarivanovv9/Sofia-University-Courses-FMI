#include "BooleanVector.h"
#include <iostream>

// using this library only to print to integer in binary format
#include <bitset> 

BooleanVector::BooleanVector() {
	this->number = 0;
}

BooleanVector::BooleanVector(const BooleanVector& other) {
	copyVector(other.number);
}

//BooleanVector::~BooleanVector() {
//
//}


void BooleanVector::copyVector(const int other) {
	this->number = other;
}

const int BooleanVector::operator[](int index) {
	if (index >= BOOLEAN_VECTOR_SIZE) {
		return -1;
	}
	return (this->number >> index) & 1;
}

bool BooleanVector::set(int index) {
	if (index >= BOOLEAN_VECTOR_SIZE) {
		return false;
	}
	this->number |= 1 << index;
	return 1;
}

bool BooleanVector::clear(int index) {
	if (index >= BOOLEAN_VECTOR_SIZE) {
		return false;
	}
	this->number &= ~(1 << index);
	return 1;
}

void BooleanVector::printVector() const {
	std::cout << (std::bitset<32>) this->number << "\n";
}

void BooleanVector::addValueToVector() {
	std::cout << "Enter a positive number to present the boolean vector: ";
	std::cin >> this->number;
}