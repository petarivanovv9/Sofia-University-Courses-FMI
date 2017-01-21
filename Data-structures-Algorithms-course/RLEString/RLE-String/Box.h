#pragma once

#include <iostream>

using namespace std;

class Box {
public:
	size_t repetions;
	char letter;
	Box* pNext;
	//Box* pPrev;

public:
	Box() {
		this->pNext = NULL;
		//this->pPrev = NULL;
	}

	//Box(size_t, char, Box* pNext, Box* pPrev);
	Box(size_t repetions, char letter, Box* pNext = NULL) {
		this->repetions = repetions;
		this->letter = letter;
		this->pNext = pNext;
		//this->pPrev = pPrev;
	}
	//void print() const;

	friend ostream& operator<<(ostream& os, const Box& my_obj) {
		os << "(" << my_obj.repetions << "," << my_obj.letter << ")" << " ";
		return os;
	}

	void print() const {
		cout << "(" << repetions << "," << letter << ")" << " ";
	}
};

//
//Box::Box(size_t repetions, char letter, Box* pNext = NULL, Box* pPrev = NULL) {
//	this->repetions = repetions;
//	this->letter = letter;
//	this->pNext = pNext;
//	this->pPrev = pPrev;
//}
//
//void Box::print() const {
//	std::cout << "(" << repetions << "," << letter << ")" << " ";
//}
