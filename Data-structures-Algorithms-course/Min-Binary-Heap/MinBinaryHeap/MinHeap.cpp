#include "MinHeap.h"

#include <iostream>

void MinHeap::insert(int element) {
	heap.push_back(element);

	heapify_up(heap.size() - 1);
}

void MinHeap::removeMin() {
	if (heap.size() == 0) {
		std::cerr << "The heap is empty." << std::endl;
		return;
	}
	int temp = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	heapify_down(0);

	std::cout << "The element " << temp << " was deleted." << std::endl;
}

int MinHeap::extractMin() {
	if (heap.size() == 0) {
		return -1;
	}
	else {
		return heap.front();
	}
}

int MinHeap::getLeftChildIndx(int parentIndx) {
	int leftChildIndx = parentIndx * 2 + 1;

	if (leftChildIndx < heap.size()) {
		return leftChildIndx;
	}
	else {
		return -1;
	}
}

int MinHeap::getRightChildIndx(int parentIndx) {
	int rightChildIndx = parentIndx * 2 + 2;

	if (rightChildIndx < heap.size()) {
		return rightChildIndx;
	}
	else {
		return -1;
	}
}

int MinHeap::getParentIndx(int childIndx) {
	int parentIndx = (childIndx - 1) / 2;
	
	if (childIndx == 0) {
		return -1;
	}
	else {
		return parentIndx;
	}
}

void MinHeap::heapify_up(int addedElemIndex) {
	if (addedElemIndex >= 0 && getParentIndx(addedElemIndex) >= 0 &&
		heap[getParentIndx(addedElemIndex)] > heap[addedElemIndex])
	{
		int temp = heap[addedElemIndex];
		heap[addedElemIndex] = heap[getParentIndx(addedElemIndex)];
		heap[getParentIndx(addedElemIndex)] = temp;

		heapify_up(getParentIndx(addedElemIndex));
	}
}

void MinHeap::heapify_down(int firstElemIndx) {
	int leftChildIndx = getLeftChildIndx(firstElemIndx);
	int rightChildIndx = getRightChildIndx(firstElemIndx);

	if (leftChildIndx >= 0 && rightChildIndx >= 0 
		&& heap[leftChildIndx] > heap[rightChildIndx]) 
	{
		leftChildIndx = rightChildIndx;
	}

	if (leftChildIndx > 0) {
		int temp = heap[firstElemIndx];
		heap[firstElemIndx] = heap[leftChildIndx];
		heap[leftChildIndx] = temp;

		heapify_down(leftChildIndx);
	}
}

void MinHeap::printMinHeap() {
	std::vector <int>::iterator pos = heap.begin();
	std::cout << "MinHeap -->  ";
	while (pos != heap.end()) {
		std::cout << *pos << " ";
		pos++;
	}
	std::cout << std::endl;
}