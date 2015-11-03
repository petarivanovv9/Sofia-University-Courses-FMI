#include <iostream>
#include <algorithm>

#include "DynamicArray.h"


DynamicArray::DynamicArray() {

}


DynamicArray::~DynamicArray() {

}

DynamicArray::DynamicArray(DynamicArray const & other) {

}

DynamicArray& DynamicArray::operator=(DynamicArray const & other) {

}

DynamicArray::~DynamicArray() {

}

void DynamicArray::free() {

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
/// Връща proxy обект, който представя елемента на масива с индекс index.
///
/// Тази версия на оператора се използва за неконстантни масиви и връща
/// proxy обект, който може да се използва за промяна на клетките на масива.
///
/// ВАЖНО:
/// 1. Операторът не прави проверка за това дали index
/// е валиден индекс в масива. Такава проверка се прави
/// всеки път, когато proxy обектът се използва.
/// 2. proxy обектът е свързан с конкретен индекс, а не с конкретен елемент
/// на масива. Това означава, че независимо от това какви промени се правят
/// в динамичния масив, proxy обектът винаги ще реферира един и същ индекс.
///
DynamicArrayElementProxy DynamicArray::operator[](size_t index) {

}


///
/// Връща proxy обект, който представя елемента на масива с индекс index.
///
/// Тази версия на оператора се използва за константни масиви и връща
/// константен proxy обект, който *не може* да се използва за промяна
/// на клетките на масива.
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