#include "Jar.h"
#include<iostream>

Jar::Jar() {
	manyCookies = NULL;
	sizeArr = 0;
}

Jar::Jar(const Jar& other) {
	manyCookies = new (std::nothrow) Cookie[other.getSize()];
	if (manyCookies == NULL) {
		return;
	}
	for (int i = 0; i < sizeArr; i++) {
		manyCookies[i] = other.getJar()[i];
	}
}

Jar::~Jar() {
	delete[] manyCookies;
}

const Cookie* Jar::getJar() const {
	return manyCookies;
}

const int Jar::getSize() const {
	return sizeArr;
}

bool Jar::isEmpty() const {
	return sizeArr == 0;
}

void Jar::putCookie(const Cookie& newOne) {
	if (isEmpty()) {
		manyCookies = new (std::nothrow) Cookie[1];
		if (manyCookies == NULL) {
			return;
		}
		manyCookies[0] = newOne;
		sizeArr = 1;
	}
	else {
		Cookie* buffer = new (std::nothrow) Cookie[sizeArr + 1];
		if (buffer == NULL) {
			return;
		}
		for (int i = 0; i < sizeArr; i++) {
			buffer[i] = manyCookies[i];
		}
		buffer[sizeArr] = newOne;

		delete[] manyCookies;
		sizeArr++;
		manyCookies = new (std::nothrow) Cookie[sizeArr];
		manyCookies = buffer;
	}
}

void Jar::takeCookie() {
	if (isEmpty()) {
		std::cout << "No cookies left!" << std::endl;
	}
	else {
		if (sizeArr - 1 == 0) {
			sizeArr--;
			delete[] manyCookies;
			manyCookies = NULL;
		}
		else {
			Cookie* buffer = new (std::nothrow) Cookie[sizeArr - 1];
			if (buffer == NULL) {
				return;
			}
			for (int i = 0; i < sizeArr - 1; i++) {
				buffer[i] = manyCookies[i];
			}
			delete[] manyCookies;
			manyCookies = new (std::nothrow) Cookie[sizeArr - 1];
			manyCookies = buffer;

			//if (sizeArr - 1 <= sizeArr / 2) {
				sizeArr--;
			//}
		}
	}
}

void Jar::printJar() const {
	std::cout << "Jar: " << "\n";

	for (int i = 0; i < this->sizeArr; i++) {
		std::cout << "--";
		this->manyCookies[i].printCookie();
	}
	std::cout << "\n";
}