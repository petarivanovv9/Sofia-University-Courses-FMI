#include "Vector.h"
#include <iostream>


Vector::Vector() {
	this->arr = NULL;
	this->sizeArr = 0;
}

Vector::~Vector() {
	clearVector();
}

Vector::Vector(const Vector& other) {
	copyVector(other.arr, other.sizeArr);
}

void Vector::addValuesToVector() {

	std::cout << "Enter the size of your vector: ";
	std::cin >> this->sizeArr;

	this->arr = new (std::nothrow) double[this->sizeArr];

	if (this->arr == NULL) {
		return;
	}

	for (int i = 0; i < this->sizeArr; i++) {
		std::cout << "Enter a value to your vector[" << i << "] = ";
		std::cin >> this->arr[i];
	}
}

void Vector::printVector() const {
	std::cout << "Vector: ";

	for (int i = 0; i < this->sizeArr; i++) {
		std::cout << this->arr[i] << " ";
	}
	std::cout << "\n";
}

const double& Vector::operator[](int index) const {
	if (index >= this->sizeArr) {
		return this->zero;
	}
	return this->arr[index];
}

void Vector::copyVector(const double* arr, int sizeAr) {
	this->sizeArr = sizeAr;
	this->arr = new (std::nothrow) double[sizeArr];

	if (this->arr == NULL) {
		return;
	}

	for (int i = 0; i < sizeArr; i++) {
		this->arr[i] = arr[i];
	}
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		clearVector();
		copyVector(other.arr, other.sizeArr);
	}
	return *this;
}

void Vector::clearVector() {
	delete[] this->arr;
	this->arr = NULL;
	this->sizeArr = 0;
}

void Vector::makeNewArray(int maxSize) {
	int currentSize = this->sizeArr;

	double* tempArr = new (std::nothrow) double[maxSize];

	if (tempArr == NULL) {
		return;
	}

	for (int i = 0; i < currentSize; i++) {
		tempArr[i] = this->arr[i];
	}

	for (int i = this->sizeArr; i < maxSize; i++) {
		tempArr[i] = 0;
	}

	clearVector();

	this->arr = new (std::nothrow) double[maxSize];

	if (arr == NULL) {
		return;
	}

	for (int i = 0; i < maxSize; i++) {
		this->arr[i] = tempArr[i];
	}

	this->sizeArr = maxSize;
	delete[] tempArr;
}

Vector& Vector::operator+=(const Vector& other) {
	int maxSize = 0;

	if (this->sizeArr >= other.sizeArr) {
		maxSize = this->sizeArr;
	}
	else {
		maxSize = other.sizeArr;
		makeNewArray(maxSize);
	}

	for (int i = 0; i < this->sizeArr; i++) {
		double a = (*this)[i];
		double b = other[i];

		this->arr[i] = a + b;
	}

	return *this;
}

Vector Vector::operator+(Vector& other) const {
	Vector temp(*this);
	temp += other;

	return temp;
}

Vector& Vector::operator-=(Vector& other) {
	int maxSize = 0;

	if (this->sizeArr >= other.sizeArr) {
		maxSize = this->sizeArr;
	}
	else {
		maxSize = other.sizeArr;
		makeNewArray(maxSize);
	}

	for (int i = 0; i < this->sizeArr; i++) {
		double a = (*this)[i];
		double b = other[i];

		this->arr[i] = a - b;
	}

	return *this;
}

Vector Vector::operator-(Vector& other) const {
	Vector temp(*this);
	temp -= other;

	return temp;
}

Vector& Vector::operator*=(double number) {
	for (int i = 0; i < this->sizeArr; i++) {
		this->arr[i] *= number;
	}

	return *this;
}

Vector Vector::operator*(double number) {
	Vector temp(*this);
	temp *= number;
	
	return temp;
}

Vector& Vector::operator/=(double number) {
	if (number == 0) {
		return *this;
	}

	for (int i = 0; i < this->sizeArr; i++) {
		this->arr[i] /= number;
	}

	return *this;
}

Vector Vector::operator/(double number) const {
	Vector temp(*this);
	if (number == 0) {
		return *this;
	}
	temp /= number;

	return temp;
}

double Vector::operator%(Vector& other) {
	double result = 0;

	int maxSize = 0;

	if (this->sizeArr >= other.sizeArr) {
		maxSize = this->sizeArr;
	}
	else {
		maxSize = other.sizeArr;
		makeNewArray(maxSize);
	}
		
	for (int i = 0; i < this->sizeArr; i++) {
		double a = (*this)[i];
		double b = other[i];

		result += (a * b);
	}

	return result;
}