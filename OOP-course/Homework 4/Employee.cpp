#include "Employee.h"
#include <iostream>


Employee::Employee() {
	std::cout << "Employee::Employee()" << std::endl;
	this->name = NULL;
	this->address = NULL;
	this->department = NULL;
	this->salary = 0;
}

Employee::Employee(char* name, char* address, char* department, int salary) {
	std::cout << "Employee::Employee(....)" << std::endl;
	setName(name);
	setAddress(address);
	setDepartment(department);
	setSalary(salary);
}

Employee::~Employee() {
	std::cout << "Employee::~Employee()" << std::endl;
	clearEmployee();
}

Employee::Employee(const Employee& other) {
	std::cout << "Employee::Employee(const Employee& other)" << std::endl;
	copyEmployee(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		clearEmployee();
		copyEmployee(other);
	}
	return *this;
}

void Employee::printEmployee() const {
	std::cout << "Employee: " << std::endl;
	std::cout << "--name: " << getName()
		<< std::endl
		<< "--address: " << getAddress()
		<< std::endl
		<< "--department: " << getDepartment()
		<< std::endl
		<< "--salary: " << getSalary()
		<< std::endl << std::endl;
}

char* Employee::getName() const {

	return this->name;
}

char* Employee::getAddress() const {
	return this->address;
}

char* Employee::getDepartment() const {
	return this->department;
}

int Employee::getSalary() const {
	return this->salary;
}

void Employee::clearEmployee() {
	delete[] this->name;
	delete[] this->address;
	delete[] this->department;
	this->salary = 0;
}

void Employee::setName(const char* name) {
	int length = strlen(name) + 1;
	this->name = NULL;

	this->name = new (std::nothrow) char[length];

	if (name == NULL) {
		return;
	}

	strcpy_s(this->name, length, name);
}

void Employee::setAddress(const char* address) {
	int length = strlen(address) + 1;
	this->address = NULL;

	this->address = new (std::nothrow) char[length];

	if (address == NULL) {
		return;
	}

	strcpy_s(this->address, length, address);
}

void Employee::setDepartment(const char* department) {
	int length = strlen(department) + 1;
	this->department = NULL;

	this->department = new (std::nothrow) char[length];

	if (department == NULL) {
		return;
	}

	strcpy_s(this->department, length, department);
}

void Employee::setSalary(const int salary) {
	this->salary = salary;
}

void Employee::copyEmployee(const Employee& other) {
	setName(other.getName());
	setAddress(other.getAddress());
	setDepartment(other.getDepartment());
	setSalary(other.getSalary());
}
