#include "Specialist.h"
#include <iostream>

Specialist::Specialist() : Employee() {
	std::cout << "Specialist::Specialist() : Employee()" << std::endl;
	this->speciality = NULL;
}

Specialist::Specialist(char* name, char* address, char* department, int salary, char* speciality) : Employee(name, address, department, salary) {
	std::cout << "Specialist::Specialist(.....) : Employee(.....)" << std::endl;
	setSpeciality(speciality);
}

Specialist::Specialist(const Specialist& other) : Employee(other) {
	std::cout << "Specialist::Specialist(const Specialist& other)" << std::endl;
	copySpecialist(other);
}

Specialist& Specialist::operator=(const Specialist& other) {
	std::cout << "Specialist& Specialist::operator=(const Specialist& other)" << std::endl;
	if (this != &other) {
		clearSpecialist();
		Employee::operator=(other);
		copySpecialist(other);
	}

	return *this;
}

Specialist::~Specialist() {
	std::cout << "Specialist::~Specialist()" << std::endl;
	clearSpecialist();
}

char* Specialist::getSpeciality() const {
	return this->speciality;
}

void Specialist::setSpeciality(const char* speciality) {
	int length = strlen(speciality) + 1;
	this->speciality = NULL;

	this->speciality = new (std::nothrow) char[length];
	if (speciality == NULL)
		return;

	strcpy_s(this->speciality, length, speciality);
}

void Specialist::printSpecialist() const {
	std::cout << "Specialist: " << std::endl;
	std::cout << "--name: " << getName()
		<< std::endl
		<< "--address: " << getAddress()
		<< std::endl
		<< "--department: " << getDepartment()
		<< std::endl
		<< "--speciality: " << getSpeciality()
		<< std::endl
		<< "--salary: " << getSalary()
		<< std::endl << std::endl;
}

void Specialist::copySpecialist(const Specialist& other) {
	setSpeciality(other.getSpeciality());
}

void Specialist::clearSpecialist() {
	delete[] this->speciality;
}