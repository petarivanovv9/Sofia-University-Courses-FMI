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
	Node<T>* findNodeBefore(Node<T> *pNode) const;

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
	initializerVariables();
	append(otherList);
}

///
/// Copies the contents of one list to another
///
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList const & otherList) {
	if (this != &otherList) {
		removeAll();
		append(otherList);
	}

	return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	removeAll();
}

template <typename T>
void LinkedList<T>::initializerVariables() {
	this->pFirst = NULL;
	this->pLast = NULL;
	this->size = 0;
}

template <typename T>
void LinkedList<T>::removeAll() {
	destroyChain(this->pFirst);

	initializerVariables();
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
	// if there is nothing to copy, don't copy
	if (otherList.isEmpty()) {
		return true;
	}
	else {
		// try to clone the data from the other list
		Node<T> *pNewChain = cloneChain(otherList.pFirst);

		if (pNewChain) {
			this->pLast->pNext = pNewChain;
			this->pLast = findEndOfChain(pNewChain);
		}

		return pNewChain != NULL;
	}
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
	// we can only remove the head of a non-empty list
	if ( ! this->isEmpty() ) {
		assert(this->pFirst != NULL);

		// this pointer will keep the address of the old first node
		Node<T> *pOldHead = this->pFirst;

		// Advance the first element pointer with one position forward
		this->pFirst = this->pFirst->pNext;

		// if this was the last element, the list is now empty and we have
		// to set the last element pointer to NULL
		if (this->pFirst == NULL) {
			this->pLast = NULL;
		}

		this->size--;

		delete pOldHead;
	}
}

template <typename T>
void LinkedList<T>::removeTail() {
	if ( ! this->isEmpty() ) {
		removeAt(this->size - 1);
	}
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
	// try to find the node at the specified node
	Node<T> *pNodeAtIndex = findNodeAt(index);

	// if there is such node, try to insert an element after it
	if (pNodeAtIndex) {
		Node<T> *pNewNode = new Node<T>(value, pNodeAtIndex->pNext);

		// if memory allocation fails, return false
		if ( ! pNewNode) {
			return false;
		}

		// make the node at the desired index point to the new node
		pNodeAtIndex->pNext = pNewNode;

		if (pNodeAtIndex == this->pFirst) {
			this->pLast = pNewNode;
		}

		this->size++;

		return true;
	}
	else {
		return false;
	}
}

///
/// Insert an element before a specific index in the list
///
template <typename T>
bool LinkedList<T>::insertBefore(int index, T const & value) {
	if (index == 0) {
		return addHead(value);
	}
	else {
		return insertAfter(index - 1, value);
	}
}

///
/// Removes the element at a specific index in the list
///
template <typename T>
void LinkedList<T>::removeAt(int index) {
	if (index == 0) {
		this->removeHead();
	}
	// Here we should have that:
	// (1) There are at least two elements in the list
	// (2) index != 0
	// (3) we are not trying to remove the first element
	else {
		assert(this->getCount() >= 2);

		// find the node before the one we want to remove
		Node<T> *pNodeBeforeIndex = findNodeAt(index - 1);

		// make sure the index is valid
		assert(pNodeBeforeIndex != NULL);

		Node<T> *pNodeAtIndex = pNodeBeforeIndex->pNext;

		if (index == this->size - 1) {
			this->pLast = pNodeBeforeIndex;
		}

		pNodeBeforeIndex->pNext = pNodeAtIndex->pNext;

		delete pNodeAtIndex;

		this->size--;
	}
} 

///
/// Returns the value of the element at a specific index in the list
///
template <typename T>
T const & LinkedList<T>::getAt(int index) const {
	Node<T> *pNode = findNodeAt(index);

	assert(pNode != NULL);

	return pNode->data;
}

///
/// Sets the value of the element at a specific index in the list
///
template <typename T>
bool LinkedList<T>::setAt(int index, T const & value) {
	Node<T> *pNode = findNodeAt(index);

	if (pNode != NULL) {
		pNode->data = value;
	}

	return pNode != NULL;
}

///
/// Finds the node at a specific index in the list
///
/// \return
///			NULL if there is no such index in the list
///
template <typename T>
Node<T>* LinkedList<T>::findNodeAt(int index) const {
	if (index < 0 || index >= this->size) {
		return NULL;
	}
	else {
		Node<T> *p = this->pFirst;

		for (int i = 0; i < index; i++) {
			p = p->pNext;
		}

		return p;
	}
}

///
/// Searches for a node in the list, which points to another node
///
/// \return
///			The address of the node we are looking for or
///			NULL if there is no such node in the list
///
template <typename T>
Node<T>* LinkedList<T>::findNodeBefore(Node<T> *pNode) const {
	Node<T> *pCurrent = this->pFirst;

	while (pCurrent && pCurrent->pNext != pNode) {
		pCurrent = pCurrent->pNext;
	}

	// At this point, if we have reached the end of the list
	// without finding the desired node, pCurrent is NULL.
	// Otherwise it points to the books we are looking for.
	return pCurrent;
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
	if (pfirstNode) {

		// pointer to the start of the new chain
		Node<T> *pNewChain = new Node(pfirstNode);

		// pointer to the element that we have to copy next
		Node<T> *pReadFrom = pfirstNode->pNext;

		// pointer to the element after which we have to copy the new element
		Node<T> *pWriteAfter = pNewChain;

		while (pReadFrom) {
			if ( ! pWriteAfter) {
				destroyChain(pNewChain);
				pNewChain = NULL;
				break;
			}

			pWriteAfter->pNext = new Node(pReadFrom);
			pWriteAfter = pWriteAfter->pNext;

			pReadFrom = pReadFrom->pNext;
		}

		return pNewChain;
	}

	return NULL;
}

///
/// Destroys all nodes in a chain
///
/// \param [in] pFirstNode
///			A pointer to the first node in the chain.
template <typename T>
void LinkedList<T>::destroyChain(Node<T> *pFirstNode) {
	Node<T> *pCurrent = pFirstNode;
	Node<T> *pOld = pFirstNode;

	while (pCurrent) {
		pOld = pCurrent;
		pCurrent = pCurrent->pNext;
		delete pOld;
	}
}

///
/// Returns a pointer to the last node in a chain
///
template <typename T>
Node<T>* LinkedList<T>::findEndOfChain(Node<T> *pfirstNode) {
	Node<T> pCurrent = pFirstNode;

	if (pCurrent) {
		while (pCurrent->pNext) {
			pCurrent = pCurrent->pNext;
		}
	}

	return pCurrent;
}