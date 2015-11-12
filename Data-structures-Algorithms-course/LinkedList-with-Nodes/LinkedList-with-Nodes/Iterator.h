#pragma once

#include "Node.h"

template <typename T>
class Iterator {
private:
	Node<T> *pStart;
	Node<T> *pCurrent;
public:
	Iterator(Node<T> *pStart);

	T const & getCurrent() const;
	void setCurrent(T const &);
	void moveNext();
	void rewind();
	bool endReached() const;
};

///
/// Creates a new iterator and initializes it, so that
/// it will start from the element pStart points to.
///
template <typename T>
Iterator<T>::Iterator(Node<T> *pStart) {

}

///
/// Retrieves the current list element
///
template <typename T>
T const & Iterator<T>::getCurrent() const {

}

///
/// Changes the value of the current list element
///
template <typename T>
void Iterator<T>::setCurrent(T const & value) {

}

///
/// Moves the iterator one step forward
///
/// If the iterator has reached the end of the list,
/// the function does nothing.
///
template <typename T>
void Iterator<T>::moveNext() {

}

///
/// Returns the iterator to its initial state
///
template <typename T>
void Iterator<T>::rewind() {

}

///
/// Checks whether the iterator has moved past the end of the list.
///
/// \return
/// true if there are no more elements to be iterated,
/// or false otherwise.
///
template <typename T>
bool Iterator<T>::endReached() const {

}