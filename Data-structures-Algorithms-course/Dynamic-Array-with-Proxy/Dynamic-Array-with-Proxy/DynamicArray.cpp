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

	for (size_t i = 0; i < other.length; i++) {
		pData[i] = other.pData[i];
	}

	allocatedSize = other.allocatedSize;
	length = other.length;
}

void DynamicArray::reallocate(size_t newSize) {
	int *pTemp = new int[newSize];

	size_t limit = std::min(allocatedSize, newSize);

	for (size_t i = 0; i < limit; i++) {
		pTemp[i] = pData[i];
	}

	delete[] pData;
	pData = pTemp;
	allocatedSize = newSize;
}

void DynamicArray::add(int element) {
	if (length >= allocatedSize) {
		int newSize = (allocatedSize == 0 ? 2 : allocatedSize * 2);

		reallocate(newSize);
	}

	pData[length++] = element;
}

size_t DynamicArray::getAllocatedSize() const {
	return allocatedSize;
}

size_t DynamicArray::getLength() const {
	return length;
}

int DynamicArray::getAt(size_t index) const {
	if (index >= length) {
		throw std::out_of_range("index out of range!");
	}

	return pData[index];
}

void DynamicArray::setAt(size_t index, int value) {
	if (index >= length) {
		throw std::out_of_range("index out of range!");
	}

	pData[index] = value;
}

void DynamicArray::print() const {
	std::cout
		<< "Dynamic Array at 0x" << this
		<< ", buffer at 0x"		 << pData
		<< ", size ("			 << length
		<< " / "				 << allocatedSize
		<< ")\n";

	if (length > 0) {
		std::cout << "Contents: " << pData[0];

		for (size_t i = 1; i < length; i++) {
			std::cout << ", " << pData[i];
		}
		std::cout << "\n";
	}
}

///
/// Generate new Dynamic Array from the concatenation of
/// the current and rhs arrays
///
DynamicArray DynamicArray::operator+(DynamicArray const& rhs) const {
	DynamicArray temp(*this);

	for (size_t i = 0; i < rhs.length; i++) {
		temp.add(rhs.getAt(i));
	}

	return temp;
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
	return DynamicArrayElementProxy(this, index);
}


///
/// Returns proxy object which represents the element of the array with index "index"
///
/// This version of the operator is used for constant arrays and returns
/// constant proxy object that *can't* be used to change the array's cells.
///
const DynamicArrayElementProxy DynamicArray::operator[](size_t index) const {
	return DynamicArrayElementProxy(const_cast<DynamicArray*>(this), index);
}


/// ============================================================================


DynamicArrayElementProxy::DynamicArrayElementProxy(DynamicArray * pDynamicArray, size_t elementIndex) : 
pParent(pDynamicArray), parentElementIndex(elementIndex) 
{
}

DynamicArrayElementProxy::operator int() const {
	return pParent->getAt(parentElementIndex);
}

DynamicArrayElementProxy & DynamicArrayElementProxy::operator=(int value) {
	pParent->setAt(parentElementIndex, value);

	return *this;
}