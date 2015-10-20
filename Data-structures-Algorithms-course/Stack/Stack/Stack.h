#pragma once

#include <iostream>

template <typename T>
class Stack {

	class Node {
	public:
		T data;
		Node* pNext;
		Node(T, Node* = NULL);
	};

public:
	Stack();
	~Stack();
	Stack(Stack const & other);
	Stack& operator=(Stack const & other);

public:
	bool push(T);
	bool pop(T&);
	T peek() const;

	void removeAll();

	size_t getAllocatedSize() const;
	size_t getSize() const;
	
	bool isEmpty() const;

private:
	void init();
	void destroy();
	void copyFrom(Stack const & other);

private:
	Node* pTop;
	size_t used;
};