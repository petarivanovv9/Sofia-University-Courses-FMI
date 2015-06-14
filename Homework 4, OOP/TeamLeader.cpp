#include "TeamLeader.h"

#include <iostream>

TeamLeader::TeamLeader() : Specialist() {
	std::cout << "TeamLeader::TeamLeader()" << std::endl;
	this->departmentDescription = NULL;
	this->employees = NULL;
	this->numberEmployees = 0;
	this->capacityEmployees = 2;
}

TeamLeader::TeamLeader(char* name, char* address, char* department, int salary, char* speciality, char* departmentDescription)
: Specialist(name, address, department, salary, speciality) {
	std::cout << "TeamLeader::TeamLeader(.....) : Specialist(....)" << std::endl;
	int lenDepDesc = strlen(departmentDescription) + 1;
	this->departmentDescription = NULL;

	this->departmentDescription = new (std::nothrow) char[lenDepDesc];
	if (this->departmentDescription == NULL)
		return;
	strcpy_s(this->departmentDescription, lenDepDesc, departmentDescription);
	this->employees = NULL;
	this->numberEmployees = 0;
	this->capacityEmployees = 2;
}

TeamLeader::TeamLeader(const TeamLeader& other) : Specialist(other) {
	std::cout << "TeamLeader::TeamLeader(const TeamLeader& other)" << std::endl;
	copyTeamLeader(other);
}

TeamLeader& TeamLeader::operator=(const TeamLeader& other) {
	std::cout << "TeamLeader& TeamLeader::operator=(const TeamLeader& other)" << std::endl;
	if (this != &other) {
		clearTeamLeader();
		Specialist::operator=(other);
		copyTeamLeader(other);
	}
	return *this;
}

TeamLeader::~TeamLeader() {
	std::cout << "TeamLeader::~TeamLeader()" << std::endl;
	clearTeamLeader();
}

//void TeamLeader::addEmployee(Employee& other) {
//	if (this->numberEmployees + 1 == this->capacityEmployees) {
//		this->capacityEmployees *= 2;
//	}
//	Employee** temp = new (std::nothrow) Employee*[this->capacityEmployees];
//	if (temp == NULL)
//		return;
//	std::cout << "numberEmployees: " << this->numberEmployees << std::endl;
//	for (int i = 0; i < this->numberEmployees; i++) {
//		temp[i] = this->employees[i];
//	}
//	for (int i = 0; i < this->numberEmployees; i++) {
//		delete[] this->employees[i];
//	}
//	delete[] employees;
//
//	temp[this->numberEmployees] = &other;
//	this->numberEmployees += 1;
//	this->employees = new (std::nothrow) Employee*[this->capacityEmployees];
//	if (this->employees == NULL)
//		return;
//	for (int i = 0; i < this->numberEmployees; i++) {
//		this->employees[i] = temp[i];
//	}
//	for (int i = 0; i < this->numberEmployees - 1; i++) {
//		delete[] temp[i];
//	}
//	delete[] temp;
//}

void TeamLeader::addEmployee(Employee* other) {
	if (this->numberEmployees + 1 == this->capacityEmployees) {
		this->capacityEmployees *= 2;
	}
	Employee** temp = new (std::nothrow) Employee*[this->capacityEmployees];
	if (temp == NULL)
		return;
	for (int i = 0; i < this->numberEmployees; i++) {
		temp[i] = this->employees[i];
	}
	//for (int i = 0; i < this->numberEmployees; i++) {
	//	delete[] this->employees[i];
	//}
	delete[] employees;
	
	temp[this->numberEmployees] = other;
	this->numberEmployees += 1;
	this->employees = new (std::nothrow) Employee*[this->capacityEmployees];
	if (this->employees == NULL)
		return;
	for (int i = 0; i < this->numberEmployees; i++) {
		//this->employees[i] = new Employee;
		this->employees[i] = temp[i];
	}
	//for (int i = 0; i < this->numberEmployees - 1; i++) {
	//	delete[] temp[i];
	//}
	delete[] temp;
}

char* TeamLeader::getDepartmentDescription() const {
	return this->departmentDescription;
}

void TeamLeader::setDepartmentDescription(const char* departmentDescription) {
	int lenDepDesc = strlen(departmentDescription) + 1;
	this->departmentDescription = NULL;

	this->departmentDescription = new (std::nothrow) char[lenDepDesc];
	if (this->departmentDescription == NULL)
		return;
	strcpy_s(this->departmentDescription, lenDepDesc, departmentDescription);
}

int TeamLeader::getNumberEmployees() const {
	return this->numberEmployees;
}

void TeamLeader::clearTeamLeader() {
	delete[] this->departmentDescription;

	//for (int i = 0; i < this->numberEmployees - 1; i++) {
	//	delete[] this->employees[i];
	//}
	delete[] this->employees;
	this->numberEmployees = 0;
	this->capacityEmployees = 2;
}

void TeamLeader::copyTeamLeader(const TeamLeader& other) {
	setDepartmentDescription(other.getDepartmentDescription());
	this->numberEmployees = other.getNumberEmployees();
	this->capacityEmployees = other.capacityEmployees;

	this->employees = new (std::nothrow) Employee*[this->numberEmployees];
	if (this->employees == NULL)
		return;
	for (int i = 0; i < this->numberEmployees; i++) {
		this->employees[i] = other.getEmployeesTeam()[i];
	}
}

void TeamLeader::printTeamLeader() const {
	std::cout << "TeamLeader: " << std::endl;
	std::cout << "--name: " << getName()
		<< std::endl
		<< "--address: " << getAddress()
		<< std::endl
		<< "--department: " << getDepartment()
		<< std::endl
		<< "--speciality: " << getSpeciality()
		<< std::endl
		<< "--salary: " << getSalary()
		<< std::endl
		<< "--departmentDescription: " << getDepartment()
		<< std::endl
		<< "--has " << getNumberEmployees() << " employees in his team."
		<< std::endl << std::endl;
}

Employee** TeamLeader::getEmployeesTeam() const {
	return this->employees;
}
