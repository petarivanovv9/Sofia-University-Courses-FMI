#pragma once

class DynamicArrayElementProxy;

///
/// Represents Dynamic Array
///
class DynamicArray {
public:
	DynamicArray();
	DynamicArray(DynamicArray const &);
	DynamicArray& operator=(DynamicArray const &);
	~DynamicArray();
	
public:
	void free();
	void add(int);

	size_t getAllocatedSize() const;
	size_t getLength() const;

	int getAt(size_t) const;
	void setAt(size_t, int);

	void print() const;

public:
	DynamicArray operator+(DynamicArray const &) const;
	DynamicArrayElementProxy operator[](size_t);
	const DynamicArrayElementProxy operator[](size_t) const;

private:
	int *pData;
	
	/// size of the allocated memory for the array
	size_t allocatedSize;

	/// number of the used cells from the array
	size_t length;

private:
	void reallocate(size_t);
	void copyFrom(DynamicArray const &);
};


///
/// Represents an element in Dynamic Array
///
class DynamicArrayElementProxy {
public:
	DynamicArrayElementProxy(DynamicArray *, size_t);

public:
	operator int() const;

	DynamicArrayElementProxy& operator=(int);

private:
	/// pointer to the dynamic array that created the proxy
	DynamicArray *pParent;

	/// index of the element in the dynamic array
	/// which is represented from the proxy
	size_t parentElementIndex;
};