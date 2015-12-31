#pragma once

#include "Vector.h"

//#include <vector>

class TrieNode {
private:
	char value;
	bool _isFinal;
	Vector<TrieNode*> children;
	//unsigned long _size;
	int counter;

private:
	void copy(const TrieNode & other);

public:
	TrieNode();
	TrieNode(char _val, bool flag, int counter);
	~TrieNode();

	TrieNode(const TrieNode & other);
	TrieNode& operator=(const TrieNode & other);

public:
	void addChild(TrieNode* child) { children.push_back(child); };
	//unsigned long size();
	TrieNode* findChild(char key) const;

	void markNode() { _isFinal = true; }
	void setValue(char _val) { value = _val; }
	void updateCounter() { counter++; }
	bool isFinal() { return _isFinal; }
	int getCounter() { return counter; }
};

TrieNode::TrieNode() : value('\0'), _isFinal(false), counter(0) {
}

TrieNode::TrieNode(char _val, bool flag, int _cntr) :
value(_val), _isFinal(flag), counter(_cntr) {
}

TrieNode::~TrieNode() {
	for (int i = 0; i < children.size(); i++)
		delete children.at(i);
}

///
/// Binary search to find the child - O(logn)
///
TrieNode* TrieNode::findChild(char key) const {
	TrieNode* temp;

	int start = 0;
	int end = children.size() - 1;
	int middle;

	while (start <= end) {
		middle = (start + end) / 2;
		temp = children.at(middle);

		if (temp->value == key)
			return temp;

		if (temp->value > key)
			end = middle - 1;

		if (temp->value < key)
			start = middle + 1;		
	}

	return NULL;
}

void TrieNode::copy(const TrieNode & other) {
	this->value = other.value;
	this->_isFinal = other._isFinal;
	this->counter = other.counter;

	this->children = other.children;
}

TrieNode::TrieNode(const TrieNode & other) {
	copy(other);
}

TrieNode& TrieNode::operator=(const TrieNode & other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}