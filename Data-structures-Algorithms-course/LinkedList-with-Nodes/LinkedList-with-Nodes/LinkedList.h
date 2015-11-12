#pragma once

#include <assert.h>

#include "Node.h"

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

private:
	Node<T>* findNodeAt(int) const;
	Node<T>* FindNodeBefore(Node<T> *pNode) const;

private:
	static Node<T> *cloneChain(Node<T> *pFirstNode);
	static void destroyChain(Node<T> *pFirstNode);
	static Node<T> *findEndOfChain(Node<T> *pFirstNode);
};