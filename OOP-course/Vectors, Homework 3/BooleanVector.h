#pragma once

const int BOOLEAN_VECTOR_SIZE = 32;

class BooleanVector {
public:
	BooleanVector();
	BooleanVector(const BooleanVector&);
	//~BooleanVector();
public:
	const int operator[](int);
	bool set(int);
	bool clear(int);
public:
	void addValueToVector();
	void printVector() const;
private:
	unsigned int number;
private:
	void copyVector(const int);
};