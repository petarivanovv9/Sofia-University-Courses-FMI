#pragma once

#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class LinkedList {

private:
	Node<T>* pFront;
	Node<T>* pBack;
	int _size;

private:
	void copy(const LinkedList<T> & other);

	Node<T>* MS(Node<T>* first, int size);
	Node<T>* merge(Node<T>* left, Node<T>* right);
	Node<T>* getAt(Node<T>* start, int index);

public:
	LinkedList() : pFront(NULL), pBack(NULL), _size(0) {};
	LinkedList(const LinkedList<T> & other);
	LinkedList<T>& operator=(const LinkedList<T> & other);
	~LinkedList();

public:
	bool operator>(const LinkedList<T> & other) const;
	bool operator>=(const LinkedList<T> & other) const;

	void mergeSort();

public:
	void push_front(const T & data);
	void push_back(const T & data);

	void pop_front();
	void pop_back();

	T& front() const;
	int size() const;
	bool empty() const;
	void clear();
};

template <typename T>
LinkedList<T>::~LinkedList() {
	clear();
}

template <typename T>
void LinkedList<T>::clear() {
	while (!this->empty()) {
		pop_front();
	}
	this->_size = 0;
	this->pFront = NULL;
	this->pBack = NULL;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> & other) {
	Node<T>* otherFront = other.pFront;

	while (otherFront != NULL) {
		push_back(otherFront->data);
		otherFront = otherFront->next;
	}

	this->_size = other._size;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & other)
:pFront(NULL), pBack(NULL), _size(0) {
	copy(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> & other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
void LinkedList<T>::push_front(const T & data) {
	Node<T>* newNode = new (std::nothrow) Node<T>;

	if (newNode == NULL) {
		std::cerr << "Couldn't allocate memory!\n";
		return;
	}

	if (this->pFront != NULL) {
		newNode->next = this->pFront;
		this->pFront = newNode;
	}
	else {
		this->pFront = newNode;
	}

	this->pFront->data = data;

	if (this->pBack == NULL) {
		this->pBack = pFront;
		this->pBack->next = NULL;
	}

	this->_size++;
}

template <typename T>
void LinkedList<T>::push_back(const T & data) {
	Node<T>* newNode = new (std::nothrow) Node<T>;

	if (newNode == NULL) {
		std::cerr << "Couldn't allocate memory!\n";
		return;
	}

	if (this->pBack != NULL) {
		this->pBack->next = newNode;
		this->pBack = newNode;
	}
	else {
		this->pBack = newNode;
	}

	this->pBack->data = data;
	this->pBack->next = NULL;

	if (this->pFront == NULL) {
		this->pFront = this->pBack;
	}

	this->_size++;
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (this->pFront == NULL) {
		std::cerr << "Trying to pop from an empty list!\n";
		return;
	}

	Node<T>* oldNode = this->pFront;
	this->pFront = this->pFront->next;
	delete oldNode;

	if (this->pFront == NULL) {
		this->pBack = NULL;
	}

	this->_size--;
}

template <typename T>
void LinkedList<T>::pop_back() {
	if (this->pBack == NULL) {
		std::cerr << "Trying to pop from an empty list!\n";
		return;
	}

	Node<T>* oldNode = this->pBack;
	if (this->_size == 1) {
		this->pBack = NULL;
	}
	else {
		this->pBack = getAt(pFront, this->_size - 1);
		this->pBack->next = NULL;
	}

	delete oldNode;

	if (this->pBack == NULL) {
		this->pFront = NULL;
	}

	this->_size--;
}

template <typename T>
int LinkedList<T>::size() const {
	return this->_size;
}

template <typename T>
T& LinkedList<T>::front() const {
	return this->pFront->data;
}

template <typename T>
bool LinkedList<T>::empty() const {
	return this->pFront == NULL;
}

template <typename T>
void LinkedList<T>::mergeSort() {
	this->pFront = MS(this->pFront, this->_size);
}

template <typename T>
Node<T>* LinkedList<T>::MS(Node<T>* first, int size) {
	if (size == 1) {
		return first;
	}

	if (size == 2) {
		if (first->data > first->next->data) {
			first->next->next = first;
			first = first->next;
			first->next->next = NULL;
		}
		return first;
	}

	Node<T>* firstHalfEnd = getAt(first, size / 2);
	Node<T>* secondHalfStart = firstHalfEnd->next;
	firstHalfEnd->next = NULL;
	first = MS(first, size / 2);
	secondHalfStart = MS(secondHalfStart, size - size / 2);

	return merge(first, secondHalfStart);
}

template <typename T>
Node<T>* LinkedList<T>::merge(Node<T>* left, Node<T>* right) {
	Node<T>* connector = NULL;
	Node<T>* start = NULL;

	while (left || right) {
		if (!left || (right && left->data > right->data)) {
			if (!connector) {
				start = right;
				connector = right;
				right = right->next;
			}
			else {
				connector->next = right;
				connector = connector->next;
				right = right->next;
			}
		}

		if (right == NULL && left == NULL) {
			return start;
		}

		if (!right || (left && right->data >= left->data)) {
			if (!connector) {
				start = left;
				connector = left;
				left = left->next;
			}
			else {
				connector->next = left;
				connector = connector->next;
				left = left->next;
			}
		}
	}

	connector->next = NULL;
	return start;
}

template<class T>
Node<T>* LinkedList<T>::getAt(Node<T>* start, int index) {
	if (index > this->_size || index <= 0) {
		std::cerr << "Wrong index\n";
		return NULL;
	}

	Node<T>* wantedNode = start;
	while (index > 1) {
		wantedNode = wantedNode->next;
		index--;
	}

	return wantedNode;
}

template<class T>
bool LinkedList<T>::operator>(const LinkedList<T> & other) const {
	return this->_size > other._size;
}

template<class T>
bool LinkedList<T>::operator>=(const LinkedList<T> & other) const {
	return this->_size >= other._size;
}