#pragma once

#include <iostream>

#include "Box.h"

using namespace std;


class RLEString {
public:
	RLEString();
	RLEString(char const*);
	RLEString(RLEString const & other);
	RLEString& operator=(RLEString const & other);
	~RLEString();

public:
	friend ostream& operator<<(ostream& os, const RLEString&);

public:
	size_t length() const;
	//char& operator[](int i);
	RLEString operator+(RLEString const & right) const;
	void splice(int start, int length);
	void insert(const RLEString& rles, int pos);

private:
	void encode(char const* input);
	
	void copyString(char const* input);
	void append(RLEString const & right);
	void removeAll();

	void init();

private:
	char* input;
	//size_t input_length;
	//char* decompressed_input;
	Box* pFirst;
	Box* pLast;
};


