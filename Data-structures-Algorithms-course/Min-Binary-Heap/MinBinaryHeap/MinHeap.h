#pragma once

#include <vector>

class MinHeap {
public:
	MinHeap(){};
	~MinHeap(){};

public:
	void insert(int element);
	void removeMin();
	int extractMin();

	void printMinHeap();
	int size() { return heap.size(); };

private:
	int getLeftChildIndx(int parentIndx);
	int getRightChildIndx(int parentIndx);
	int getParentIndx(int childIndx);

private:
	void heapify_up(int index);
	void heapify_down(int index);
	
private:
	std::vector<int> heap;
};

