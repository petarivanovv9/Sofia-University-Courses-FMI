#include "RLEString.h"

using namespace std;

RLEString::RLEString() {
	init();
}

RLEString::RLEString(char const* input) {
	init();
	copyString(input);
	//this->input_length = strlen(input);
	encode(this->input);
	//make_decompressed_string();
}

void RLEString::copyString(char const* input) {
	this->input = new char[strlen(input) + 1];
	strcpy(this->input, input);
	this->input[strlen(input)] = '\0';
}

RLEString::RLEString(RLEString const & other) {
	init();
	append(other);
	copyString(other.input);
}

RLEString& RLEString::operator=(RLEString const & other) {
	if (this != &other) {
		removeAll();
		init();
		append(other);
		copyString(other.input);
	}

	return *this;
}

void RLEString::init() {
	input = NULL;
	//decompressed_input = NULL;
	pFirst = NULL;
	pLast = NULL;
	//input_length = 0;
}

void RLEString::append(RLEString const & right) {
	Box* pRightFirst = new Box(right.pFirst->repetions, right.pFirst->letter);
	Box* pRightLast = new Box(right.pLast->repetions, right.pLast->letter);

	Box* pCurrent = right.pFirst->pNext;
	Box* pTempRightFirst = pRightFirst;
	// clone chain
	while (pCurrent->pNext) {
		pTempRightFirst->pNext = new Box(pCurrent->repetions, pCurrent->letter);
		pCurrent = pCurrent->pNext;
		pTempRightFirst = pTempRightFirst->pNext;
	}
	pTempRightFirst->pNext = pRightLast;

	if (pFirst == NULL) {
		pFirst = pRightFirst;
		pLast = pRightLast;
	}
	else {
		pLast->pNext = pRightFirst;
		pLast = pRightLast;
	}
}

void RLEString::removeAll() {
	Box* pCurrent = pFirst;
	Box* pOld = pFirst;

	while (pCurrent) {
		pOld = pCurrent;
		pCurrent = pCurrent->pNext;
		delete pOld;
	}
}

RLEString::~RLEString() {
	removeAll();
	init();
}

void RLEString::encode(char const* input) {
	char const* pInput = input;
	size_t counter = 1;
	char current_letter = *pInput;

	while (*pInput != '\0') {
		if (*(pInput + 1) == current_letter) {
			counter++;
		}
		else {
			if (this->pFirst == NULL) {
				Box* current = new Box(counter, current_letter);
				this->pFirst = current;
				this->pLast = current;
			}
			else {
				Box* current = new Box(counter, current_letter);
				this->pLast->pNext = current;
				this->pLast = current;
			}
			counter = 1;
			current_letter = *(pInput + 1);
		}
		pInput++;
	}
}

ostream& operator<<(ostream& os, const RLEString& my_obj) {
	Box* pCurrent = my_obj.pFirst;
	while (pCurrent) {
		os << *pCurrent;	
		pCurrent = pCurrent->pNext;
	}
	return os;
}

size_t RLEString::length() const {
	Box* pCurrent = pFirst;
	size_t length = 0;
	while (pCurrent) {
		char buffer[200];
		itoa(pCurrent->repetions, buffer, 10);
		//(3,A) -> length 6, '(', '3', ',', 'A', ')', ' '.
		length += 1 + strlen(buffer) + 1 + 1 + 1 + 1;
		pCurrent = pCurrent->pNext;
	}
	return length;
}

RLEString RLEString::operator+(RLEString const & right) const {
	RLEString* new_obj = new RLEString(*this);
	new_obj->append(right);
	char* buffer = new char[strlen(new_obj->input) + strlen(right.input) + 1];
	strcpy(buffer, new_obj->input);
	strcat(buffer, right.input);
	buffer[strlen(new_obj->input) + strlen(right.input)] = '\0';
	delete new_obj->input;
	new_obj->input = buffer;

	return *new_obj;
}

void RLEString::splice(int start, int length) {
	size_t newInputLength = strlen(input) - length;
	char* newInput = new char[newInputLength + 1];
	char* pNewInputStart = newInput;
	int current_indx = 0;
	while (*input != '\0') {
		if (current_indx == start) {
			input += length;
			current_indx += length;
		}
		*newInput++ = *input;
		++input;
		current_indx++;
	}
	newInput = pNewInputStart;
	newInput[newInputLength] = '\0';

	removeAll();
	init();
	copyString(newInput);
	encode(this->input);
}

void RLEString::insert(const RLEString& rles, int pos) {
	size_t newInputLength = strlen(input) + strlen(rles.input);
	char* newInput = new char[newInputLength + 1];
	char* pNewInputStart = newInput;
	int current_indx = 0;
	while (*input != '\0') {
		if (current_indx == pos) {
			strcpy(newInput, rles.input);
			newInput += strlen(rles.input);
			current_indx += strlen(rles.input);
		}
		*newInput++ = *input;
		++input;
		current_indx++;
	}
	newInput = pNewInputStart;
	newInput[newInputLength] = '\0';

	removeAll();
	init();
	copyString(newInput);
	encode(this->input);
}

