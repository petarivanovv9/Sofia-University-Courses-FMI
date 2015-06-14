#pragma once
#include "Employee.h"

class Specialist : public Employee {
public:
	Specialist();
	Specialist(char*, char*, char*, int, char*);
	Specialist(const Specialist& other);
	Specialist& operator=(const Specialist& other);
	~Specialist();
public:
	char* getSpeciality() const;
public:
	void setSpeciality(const char*);
public:
	void printSpecialist() const;
private:
	void copySpecialist(const Specialist& other);
	void clearSpecialist();
private:
	char* speciality;
};