#include "Secretary.h"

#include <iostream>

Secretary::Secretary() {
	std::cout << "Secretary::Secretary()" << std::endl;
	this->numberLanguages = 0;
	this->languages = NULL;
}

Secretary::Secretary(const Secretary& other) {
	std::cout << "Secretary::Secretary(const Secretary& other)" << std::endl;
	copySecretary(other);
}

Secretary& Secretary::operator=(const Secretary& other) {
	std::cout << "Secretary& Secretary::operator=(const Secretary& other)" << std::endl;
	if (this != &other) {
		clearSecretary();
		copySecretary(other);
	}

	return *this;
}

Secretary::~Secretary() {
	clearSecretary();
}

void Secretary::clearSecretary() {
	for (int i = 0; i < this->numberLanguages; i++) {
		delete[] this->languages[i];
	}
	delete[] this->languages;
	this->numberLanguages = 0;
}

void Secretary::addLanguage(char* lang) {
	int newNumLan = this->numberLanguages + 1;
	char** temp = new (std::nothrow) char*[newNumLan];
	if (temp == NULL)
		return;

	for (int i = 0; i < this->numberLanguages; i++) {
		temp[i] = new char[strlen(this->languages[i]) + 1];
		strcpy_s(temp[i], strlen(this->languages[i]) + 1, this->languages[i]);

	}
	for (int i = 0; i < this->numberLanguages; i++) {
		delete[] this->languages[i];
	}
	delete[] languages;
	//clearSecretary();
	
	temp[newNumLan - 1] = new (std::nothrow) char[strlen(lang) + 1];
	if (temp[newNumLan - 1] == NULL)
		return;
	strcpy_s(temp[newNumLan - 1], strlen(lang) + 1, lang);
	
	this->numberLanguages += 1;

	this->languages = new (std::nothrow) char*[this->numberLanguages];
	if (this->languages == NULL)
		return;
	for (int i = 0; i < this->numberLanguages; i++) {
		this->languages[i] = new char[strlen(temp[i]) + 1];
		strcpy_s(this->languages[i], strlen(temp[i]) + 1, temp[i]);
	}
	for (int i = 0; i < this->numberLanguages - 1; i++) {
		delete[] temp[i];
	}
	delete[] temp;
}

char** Secretary::getLanguages() const {
	return this->languages;
}

int Secretary::getNumberLanguages() const {
	return this->numberLanguages;
}

void Secretary::printSecretary() const {
	std::cout << "Secretary speakes " << getNumberLanguages() << " languages: " << std::endl;
	//std::cout << this->numberLanguages << std::endl;
	for (int i = 0; i < this->numberLanguages; i++) {
		std::cout << i << " " << this->languages[i] << std::endl;
	}
	std::cout << std::endl;
}

void Secretary::copySecretary(const Secretary& other) {
	this->numberLanguages = other.numberLanguages;
	this->languages = new (std::nothrow) char*[this->numberLanguages];
	if (this->languages == NULL)
		return;
	for (int i = 0; i < this->numberLanguages; i++) {
		this->languages[i] = new char[strlen(other.languages[i]) + 1];
		strcpy_s(this->languages[i], strlen(other.languages[i]) + 1, other.languages[i]);
	}
}