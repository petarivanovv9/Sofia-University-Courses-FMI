#pragma once

#include <algorithm>

template <typename T>
class Vector {
public:
	Vector();
	Vector(const Vector<T> &);
	Vector<T>& operator=(const Vector<T> &);
	~Vector();

public:
	void clear();
	void push_back(T);

	size_t size() const;

	T at(size_t) const;

private:
	T *pData;

	/// size of the allocated memory for the array
	size_t allocatedSize;

	/// number of the used cells from the array
	size_t _size;

private:
	void copyFrom(const Vector<T> & other);
	void reallocate(size_t);
};

template <typename T>
Vector<T>::Vector() {
	pData = NULL;
	allocatedSize = 0;
	_size = 0;
}

template <typename T>
Vector<T>::Vector<T>(Vector<T> const & other) {
	copyFrom(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> & other) {
	if (this != &other) {
		clear();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector() {
	clear();
}

template <typename T>
void Vector<T>::clear() {
	delete[] pData;

	pData = NULL;
	allocatedSize = 0;
	_size = 0;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T> & other) {
	clear();

	pData = new T[other.allocatedSize];

	for (size_t i = 0; i < other._size; i++) {
		pData[i] = other.pData[i];
	}

	this->allocatedSize = other.allocatedSize;
	this->_size = other._size;
}

template <typename T>
void Vector<T>::reallocate(size_t newSize) {
	T *pTemp = new T[newSize];

	size_t limit = std::min(allocatedSize, newSize);

	for (size_t i = 0; i < limit; i++) {
		pTemp[i] = pData[i];
	}

	delete[] pData;
	pData = pTemp;
	allocatedSize = newSize;
}

template <typename T>
void Vector<T>::push_back(T element) {
	if (this->_size >= allocatedSize) {
		int newSize = (allocatedSize == 0 ? 2 : allocatedSize * 2);

		reallocate(newSize);
	}

	pData[this->_size++] = element;
}

template <typename T>
size_t Vector<T>::size() const {
	return _size;
}

template <typename T>
T Vector<T>::at(size_t index) const {
	if (index >= _size) {
		throw std::out_of_range("index out of range!");
	}

	return pData[index];
}