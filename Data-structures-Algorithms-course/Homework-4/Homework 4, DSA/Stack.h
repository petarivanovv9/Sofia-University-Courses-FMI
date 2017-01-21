#pragma once

#include <iostream>
#include <assert.h>
#include <exception>

template <typename T>
class Stack {

	class Node {
	public:
		T data;
		Node* pNext;
		Node(T, Node* = NULL);
	};

public:
	Stack();
	~Stack();
	Stack(Stack<T> const & other);
	Stack& operator=(Stack<T> const & other);

public:
	bool push(T);
	bool pop();
	T peek() const;

	void removeAll();

	size_t getAllocatedSize() const;
	size_t getSize() const;

	bool isEmpty() const;

private:
	void init();
	void destroy();
	void copyFrom(Stack<T> const & other);

private:
	Node* pTop;
	size_t used;
};

template <typename T>
Stack<T>::Node::Node(T _data, Node* _pNext) {
	this->data = _data;
	this->pNext = _pNext;
}

template <typename T>
Stack<T>::Stack() {
	init();
}

template <typename T>
Stack<T>::~Stack() {
	destroy();
}

template <typename T>
Stack<T>::Stack(Stack<T> const & other) {
	init();
	copyFrom(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const & other) {
	if (this != &other) {
		destroy();
		copyFrom(other);
	}

	return *this;
}

///
/// set initial values of the properties
///
template <typename T>
void Stack<T>::init() {
	this->pTop = NULL;
	this->used = 0;
}

///
/// delete all values in the stack
/// realese the allocated memory
///
template <typename T>
void Stack<T>::destroy() {
	Node* p;

	while (pTop) {
		p = pTop;
		pTop = pTop->pNext;
		delete p;
	}

	init();
}

///
/// copy the content of another stack
///
/// the function suggests that the stack
///		in which we copy is empty
///
template <typename T>
void Stack<T>::copyFrom(Stack<T> const & other) {
	if (other.isEmpty()) {
		return;
	}

	Node *ours, *theirs;

	try {
		pTop = new Node(other.pTop->data);

		ours = pTop;
		theirs = other.pTop->pNext;

		while (theirs) {
			ours->pNext = new Node(theirs->data);
			ours = ours->pNext;
			theirs = theirs->pNext;
		}

		used = other.used;
	}
	catch (std::bad_alloc&) {
		destroy();

		throw;
	}
}

///
/// add new element at the top of the stack
///
template <typename T>
bool Stack<T>::push(T element) {
	Node* pNewNode;

	try {
		pNewNode = new Node(element, pTop);
	}
	catch (...) {
		return false;
	}

	pTop = pNewNode;
	used++;

	return true;
}

///
/// remove the element at the top of the stack
///
template <typename T>
bool Stack<T>::pop() {
	if (used == 0) {
		return false;
	}
	Node* p;
	p = pTop;
	pTop = pTop->pNext;
	delete p;

	used--;

	return true;
}

///
/// return the element at the top of the stack
///
template <typename T>
T Stack<T>::peek() const {
	assert(used != 0);

	return pTop->data;
}

template <typename T>
void Stack<T>::removeAll() {
	destroy();
}

template <typename T>
size_t Stack<T>::getAllocatedSize() const {
	return used * sizeof(Node);
}

template <typename T>
size_t Stack<T>::getSize() const {
	return used;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return used == 0;
}