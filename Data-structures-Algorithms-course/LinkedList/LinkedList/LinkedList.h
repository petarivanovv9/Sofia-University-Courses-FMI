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
	Node<T>* front;
	Node<T>* back;
	int size;

private:
	void copy(const LinkedList<T> & other);

	Node<T>* MS(Node<T>* first, int size);
	Node<T>* merge(Node<T>* left, Node<T>* right);
	Node<T>* getAt(Node<T>* start, int index);

public:
	LinkedList() : front(NULL), back(NULL), size(0) {};
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

	T& getFront() const;
	int getSize() const;
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
	this->size = 0;
	this->front = NULL;
	this->back = NULL;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> & other) {
	Node<T>* otherFront = other.front;

	while (otherFront != NULL) {
		push_back(otherFront->data);
		otherFront = otherFront->next;
	}

	this->size = other.size;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & other)
:front(NULL), back(NULL), size(0) {
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

	if (this->front != NULL) {
		newNode->next = this->front;
		this->front = newNode;
	}
	else {
		this->front = newNode;
	}

	this->front->data = data;

	if (back == NULL) {
		back = front;
		back->next = NULL;
	}

	this->size++;
}

template <typename T>
void LinkedList<T>::push_back(const T & data) {
	Node<T>* newNode = new (std::nothrow) Node<T>;

	if (newNode == NULL) {
		std::cerr << "Couldn't allocate memory!\n";
		return;
	}

	if (this->back != NULL) {
		this->back->next = newNode;
		this->back = newNode;
	}
	else {
		this->back = newNode;
	}

	this->back->data = data;
	this->back->next = NULL;

	if (this->front == NULL) {
		this->front = this->back;
	}

	this->size++;
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (this->front == NULL) {
		std::cerr << "Trying to pop from an empty list!\n";
		return;
	}

	Node<T>* oldNode = this->front;
	this->front = this->front->next;
	delete oldNode;

	if (this->front == NULL) {
		this->back = NULL;
	}

	this->size--;
}

template <typename T>
void LinkedList<T>::pop_back() {
	if (this->back == NULL) {
		std::cerr << "Trying to pop from an empty list!\n";
		return;
	}

	Node<T>* oldNode = this->back;
	if (size == 1) {
		this->back = NULL;
	}
	else {
		this->back = getAt(front, size - 1);
		this->back->next = NULL;
	}

	delete oldNode;

	if (this->back == NULL) {
		this->front = NULL;
	}

	this->size--;
}

template <typename T>
int LinkedList<T>::getSize() const {
	return this->size;
}

template <typename T>
T& LinkedList<T>::getFront() const {
	return this->front->data;
}

template <typename T>
bool LinkedList<T>::empty() const {
	return this->front == NULL;
}

template <typename T>
void LinkedList<T>::mergeSort() {
	this->front = MS(this->front, this->size);
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
	if (index > size || index <= 0) {
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
	return this->size > other.size;
}

template<class T>
bool LinkedList<T>::operator>=(const LinkedList<T> & other) const {
	return this->size >= other.size;
}