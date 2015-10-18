#pragma once

#include "Cookie.h"

class Jar {
public:
	Jar();
	Jar(const Jar& other);
	~Jar();
	bool isEmpty() const;
	void putCookie(const Cookie& newOne);
	void takeCookie();
	const Cookie* getJar() const;
	const int getSize() const;
	void Jar::printJar() const;
private:
	Cookie* manyCookies;
	int sizeArr;
};