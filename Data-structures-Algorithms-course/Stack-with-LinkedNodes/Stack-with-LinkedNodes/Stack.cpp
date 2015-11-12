#include <exception>
#include <assert.h>

#include "Stack.h"

using namespace std;

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
/// remove and return the element at the top of the stack
///
//template <typename T>
//bool Stack<T>::pop(T& element) {
//	if (used == 0) {
//		return false;
//	}
//
//	element = pTop->data;
//
//	Node* pOld = pTop;
//	pTop = pTop->pNext;
//
//	delete pOld;
//
//	used--;
//
//	return true;
//}

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

template class Stack <int>;
template class Stack <const char*>;
