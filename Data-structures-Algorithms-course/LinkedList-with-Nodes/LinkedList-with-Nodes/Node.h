#pragma once

template <typename T>
class Node {
public:
	T data;
	Node<T>* pNext;

public:
	Node(T const & data, Node<T> *pNext = NULL);
	bool hasSuccessor() const;
};


template <typename T>
Node<T>::Node(T const & data, Node<T> *pNext = NULL) {
	this->data = data;
	this->pNext = pNext;
}

///
///	Checks whether the linked list element has a successor
/// (i.e. points to another element)
///
template <typename T>
bool Node<T>::hasSuccessor() const {
	return this->pNext != NULL;
}