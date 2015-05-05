#include "Cookie.h"
#include <iostream>

Cookie::Cookie() {
	this->cookie = NULL;
	this->sizeArr = 0;
}

Cookie::Cookie(const Cookie& other) {
	int otherSize = other.getSize();
	this->sizeArr = otherSize;
	this->cookie = new (std::nothrow) char*[otherSize];

	if (cookie == NULL) {
		return;
	}

	copyCookie((const char**)other.getCookie(), otherSize);
}

void Cookie::copyCookie(const char** other, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		this->cookie[i] = new (std::nothrow) char[strlen(other[i]) + 1];
		
		if (this->cookie[i] == NULL) {
			return;
		}

		strcpy(cookie[i], other[i]);
	}
}

void Cookie::deleteArray(char** arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

Cookie::~Cookie() {
	deleteArray(this->cookie, this->sizeArr);
}

const char** Cookie::getCookie() const {
	return (const char**)this->cookie;
}

const int Cookie::getSize() const {
	return this->sizeArr;
}

void Cookie::printCookie() const {
	std::cout << "Cookie: ";

	for (int i = 0; i < this->sizeArr; i++) {
		std::cout << this->cookie[i] << " ";
	}
	std::cout << "\n";
}

bool Cookie::isEmpty() const {
	return this->sizeArr == 0;
}

void Cookie::addFeature(const char* feature) {
	if (isEmpty()) {
	
		cookie = new (std::nothrow) char*[1];
		if (cookie == NULL) {
			return;
		}
		cookie[0] = new (std::nothrow) char[strlen(feature) + 1];
		if (cookie == NULL) {
			return;
		}
		strcpy(cookie[0], feature);
		this->sizeArr++;
	}
	else {
		int sizeNewArr = this->sizeArr + 1;
		char** buffer = new (std::nothrow) char*[this->sizeArr + 1];
		if (buffer == NULL) {
			return;
		}
		for (int i = 0; i < this->sizeArr; i++) {
			buffer[i] = new (std::nothrow) char[strlen(this->cookie[i]) + 1];
			if (buffer[i] == NULL) {
				return;
			}
			strcpy(buffer[i], this->cookie[i]);
		}
		buffer[this->sizeArr] = new (std::nothrow) char[strlen(feature) + 1];
		if (buffer == NULL) {
			return;
		}
		strcpy(buffer[this->sizeArr], feature);
		deleteArray(this->cookie, this->sizeArr);
		this->cookie = new (std::nothrow) char*[this->sizeArr + 1];
		if (this->cookie == NULL) {
			return;
		}
		copyCookie((const char**)buffer, this->sizeArr + 1);
		deleteArray(buffer, this->sizeArr + 1);
		this->sizeArr += 1;
	}
}

const Cookie& Cookie::operator=(const Cookie& other) {
	if (this->cookie != other.getCookie()) {
		deleteArray(this->cookie, this->sizeArr);
		this->sizeArr = other.getSize();
		cookie = new (std::nothrow) char*[sizeArr];
		copyCookie(other.getCookie(), this->sizeArr);
	}
	return *this;
}