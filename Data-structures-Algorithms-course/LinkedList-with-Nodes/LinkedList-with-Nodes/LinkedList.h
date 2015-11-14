#pragma once

#include <iostream>
#include <assert.h>

#include "Node.h"
#include "Iterator.h"

///
/// A single-linked list
///
template <typename T>
class LinkedList {
private:
	Node<T> *pFirst; // Pointer to the first element in the linked list
	Node<T> *pLast; // Pointer to the last element in the linked list
	int size;

public:
	LinkedList();
	LinkedList(LinkedList const &);
	LinkedList& operator= (LinkedList const &);
	~LinkedList();

private:
	void initializerVariables();

public:
	void removeAll();
	bool append(LinkedList const &);

	bool isEmpty() const;
	int getCount() const;

	bool addHead(T const &);
	bool addTail(T const &);

	void removeHead();
	void removeTail();

	T const & getHead();
	T const & getTail();

	bool setHead(T const &);
	bool setTail(T const &);

	bool insertAfter(int, T const &);
	bool insertBefore(int, T const &);
	void removeAt(int);
	T const & getAt(int) const;
	bool setAt(int, T const &);

	Iterator<T> getIterator() const;

private:
	Node<T>* findNodeAt(int) const;
	Node<T>* FindNodeBefore(Node<T> *pNode) const;

private:
	static Node<T> *cloneChain(Node<T> *pFirstNode);
	static void destroyChain(Node<T> *pFirstNode);
	static Node<T> *findEndOfChain(Node<T> *pFirstNode);
};


template <typename T>
LinkedList<T>::LinkedList() {
	initializerVariables();
}

///
/// Creates a new list and copies in it the contents of another list
///
template <typename T>
LinkedList<T>::LinkedList(LinkedList const & otherList) {

}

///
/// Copies the contents of one list to another
///
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList const & otherList) {

}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
void LinkedList<T>::initializerVariables() {
	this->pFirst = NULL;
	this->pLast = NULL;
	this->size = 0;
}

template <typename T>
void LinkedList<T>::removeAll() {

}

///
/// Copies and appends the contents of another list to this one
///
/// \return
///			true if the function succeeds in copying the data.
///			If it fails, the list remains unchanged and
///			the function returns false.
///
template <typename T>
bool LinkedList<T>::append(LinkedList const & otherList) {

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
	return this->size == 0;
}

template <typename T>
int LinkedList<T>::getCount() const {
	return this->size;
}

template <typename T>
bool LinkedList<T>::addHead(T const & data) {
	Node<T> *pNewNode = new Node<T>(data, this->pFirst);

	if (pNewNode) {
		if (this->isEmpty()) {
			this->pFirst = pNewNode;
		}

		this->pFirst = pNewNode;

		this->size++;
	}

	return pNewNode != NULL;
}

template <typename T>
bool LinkedList<T>::addTail(T const & data) {
	Node<T> *pNewNode = new Node<T>(data);

	if (pNewNode) {
		if (this->isEmpty()) {
			this->pFirst = pNewNode;
			this->pLast = pNewNode;
		} 
		else {
			this->pLast->pNext = pNewNode;
			this->pLast = pNewNode;
		}

		this->size++;
	}

	return pNewNode != NULL;
}

template <typename T>
void LinkedList<T>::removeHead() {

}

template <typename T>
void LinkedList<T>::removeTail() {

}

template <typename T>
T const & LinkedList<T>::getHead() {
	assert( ! this->isEmpty() );
	
	return this->pFirst->data;
}

template <typename T>
T const & LinkedList<T>::getTail() {
	assert( ! this->isEmpty() );

	return this->pLast->data;
}

template <typename T>
bool LinkedList<T>::setHead(T const & value) {
	if ( ! this->isEmpty() ) {
		this->pFirst->data = value;
		return true
	}
	else {
		return false;
	}
}

template <typename T>
bool LinkedList<T>::setTail(T const & value) {
	if ( ! this->isEmpty() ) {
		this->pLast->data = value;
		return true;
	}
	else {
		return false;
	}
}

///
/// Insert an element after a specific index in the list
///
template <typename T>
bool LinkedList<T>::insertAfter(int index, T const & value) {

}

///
/// Insert an element before a specific index in the list
///
template <typename T>
bool LinkedList<T>::insertBefore(int index, T const & value) {

}

///
/// Removes the element at a specific index in the list
///
template <typename T>
void LinkedList<T>::removeAt(int index) {

}

///
/// Returns the value of the element at a specific index in the list
///
template <typename T>
T const & LinkedList<T>::getAt(int index) const {

}

///
/// Sets the value of the element at a specific index in the list
///
template <typename T>
bool LinkedList<T>::setAt(int index, T const & value) {

}

///
/// Finds the node at a specific index in the list
///
/// \return
///			NULL if there is no such index in the list
///
template <typename T>
Node<T>* LinkedList<T>::findNodeAt(int index) const {

}

///
/// Searches for a node in the list, which points to another node
///
/// \return
///			The address of the node we are looking for or
///			NULL if there is no such node in the list
///
template <typename T>
Node<T>* LinkedList<T>::FindNodeBefore(Node<T> *pNode) const {

}


///
/// Return a new iterator for this list
///
template <typename T>
Iterator<T> LinkedList<T>::getIterator() const {
	return Iterator<T>(this->pFirst);
}


//-----------------------------------------------------------------------
// OPERATIONS ON CHAINS

///
/// Clones a chain of nodes
///
/// The function receives a pointer to the first node
/// in a chain of nodes and creates a new, identical chain.
///
/// If the function fails it returns NULL.
/// Otherwise it returns a pointer to the first node
/// of the new chain.
///
template <typename T>
Node<T>* LinkedList<T>::cloneChain(Node<T> *pfirstNode) {

}

///
/// Destroys all nodes in a chain
///
/// \param [in] pFirstNode
///			A pointer to the first node in the chain.
template <typename T>
void LinkedList<T>::destroyChain(Node<T> *pFirstNode) {

}

///
/// Returns a pointer to the last node in a chain
///
template <typename T>
Node<T>* LinkedList<T>::findEndOfChain(Node<T> *pfirstNode) {

}