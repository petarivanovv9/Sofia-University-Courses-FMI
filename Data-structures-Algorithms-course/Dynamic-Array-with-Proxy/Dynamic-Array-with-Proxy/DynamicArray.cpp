#include <iostream>
#include <algorithm>

#include "DynamicArray.h"


DynamicArray::DynamicArray() {
	pData = NULL;
	allocatedSize = 0;
	length = 0;
}

DynamicArray::DynamicArray(DynamicArray const & other) {
	copyFrom(other);
}

DynamicArray& DynamicArray::operator=(DynamicArray const & other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicArray::~DynamicArray() {
	free();
}

void DynamicArray::free() {
	delete[] pData;

	pData = NULL;
	allocatedSize = 0;
	length = 0;
}

void DynamicArray::copyFrom(DynamicArray const & other) {
	free();

	pData = new int[other.allocatedSize];

	for (int i = 0; i < other.length; i++) {
		pData[i] = other.pData[i];
	}

	allocatedSize = other.getAllocatedSize;
	length = other.length;
}

void DynamicArray::reallocate(size_t newSize) {

}

void DynamicArray::add(int element) {

}

size_t DynamicArray::getAllocatedSize() const {
	
}

size_t DynamicArray::getLength() const {

}

int DynamicArray::getAt(size_t index) const {

}

void DynamicArray::setAt(size_t index, int value) {

}

void DynamicArray::print() const {

}

DynamicArray DynamicArray::operator+(DynamicArray const& rhs) const {

}


///
/// Returns proxy object which represents the element of the array with index "index"
///
/// This version of the operator is used for non-constant arrays and returns
/// proxy object which can be used to change the array's cells.
///
/// IMPORTANT!:
/// 1. The operator doesn't make validation of the array's index.
/// Such a validation is made each time when the proxy object is used.
/// 2. The proxy object is connected to a special index,
/// not with a special element in the array.
/// This means that no matter what changes are made in the dynamic array,
/// the proxy object will refer to the same index.
///
DynamicArrayElementProxy DynamicArray::operator[](size_t index) {

}


///
/// Returns proxy object which represents the element of the array with index "index"
///
/// This version of the operator is used for constant arrays and returns
/// constant proxy object that *can't* be used to change the array's cells.
///
const DynamicArrayElementProxy DynamicArray::operator[](size_t index) const {

}


/// ============================================================================


DynamicArrayElementProxy::DynamicArrayElementProxy(DynamicArray * pDynamicArray, size_t elementIndex) :
pParent(pDynamicArray),
parentElementIndex(elementIndex) {
}

DynamicArrayElementProxy::operator int() const {

}

DynamicArrayElementProxy & DynamicArrayElementProxy::operator=(int value) {

}