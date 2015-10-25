#include "Director.h"
#include "Specialist.h"
#include <iostream>

Director::Director() {
	std::cout << "Director::Director()" << std::endl;
	this->allEmployees = NULL;
	this->allSpecialists = NULL;
	this->allTeamLeaders = NULL;

	this->numberAllEmployees = 0;
	this->numberAllSpecialists = 0;
	this->numberAllTeamLeaders = 0;

	this->capacityAllEmployees = 6;
	this->capacityAllSpecialists = 6;
	this->capacityAllTeamLeaders = 6;
}

Director::Director(const Director& other) {
	std::cout << "Director::Director(const Director& other)" << std::endl;
	//copyDirector(other);
}

Director& Director::operator=(const Director& other) {
	std::cout << "Director& Director::operator=(const Director& other)" << std::endl;
	if (this != &other) {
		//clearDirector();
		//copyDirector(other);
	}

	return *this;
}

Director::~Director() {
	std::cout << "Director::~Director()" << std::endl;
}

Secretary Director::getSecretary() const {
	return this->mySecretary;
}

void Director::setSecretary(const Secretary& other) {
	this->mySecretary = other;
}

void Director::addEmployee(Employee* other) {
	if (this->numberAllEmployees + 1 == this->capacityAllEmployees) {
		this->capacityAllEmployees *= 2;
	}
	Employee** temp = new (std::nothrow) Employee*[this->capacityAllEmployees];
	if (temp == NULL)
		return;
	for (int i = 0; i < this->numberAllEmployees; i++) {
		temp[i] = this->allEmployees[i];
	}
	//for (int i = 0; i < this->numberAllEmployees; i++) {
	//	delete[] this->allEmployees[i];
	//}
	delete[] allEmployees;

	temp[this->numberAllEmployees] = other;
	this->numberAllEmployees += 1;
	this->allEmployees = new (std::nothrow) Employee*[this->capacityAllEmployees];
	if (this->allEmployees == NULL)
		return;
	for (int i = 0; i < this->numberAllEmployees; i++) {
		this->allEmployees[i] = temp[i];
	}
	//for (int i = 0; i < this->numberAllEmployees - 1; i++) {
	//	delete[] temp[i];
	//}
	delete[] temp;
}

void Director::addSpecialist(Specialist* other) {
	if (this->numberAllSpecialists + 1 == this->capacityAllSpecialists) {
		this->capacityAllSpecialists *= 2;
	}
	Specialist** temp = new (std::nothrow) Specialist*[this->capacityAllSpecialists];
	if (temp == NULL)
		return;
	for (int i = 0; i < this->numberAllSpecialists; i++) {
		temp[i] = this->allSpecialists[i];
	}
	//for (int i = 0; i < this->numberAllSpecialists; i++) {
	//	delete[] this->allSpecialists[i];
	//}
	delete[] allSpecialists;

	temp[this->numberAllSpecialists] = other;
	this->numberAllSpecialists += 1;
	this->allSpecialists = new (std::nothrow) Specialist*[this->capacityAllSpecialists];
	if (this->allSpecialists == NULL)
		return;
	for (int i = 0; i < this->numberAllSpecialists; i++) {
		this->allSpecialists[i] = temp[i];
	}
	//for (int i = 0; i < this->numberAllSpecialists - 1; i++) {
	//	delete[] temp[i];
	//}
	delete[] temp;
}

void Director::addTeamLeader(TeamLeader* other) {
	if (this->numberAllTeamLeaders + 1 == this->capacityAllTeamLeaders) {
		this->capacityAllTeamLeaders *= 2;
	}
	TeamLeader** temp = new (std::nothrow) TeamLeader*[this->capacityAllTeamLeaders];
	if (temp == NULL)
		return;
	for (int i = 0; i < this->numberAllTeamLeaders; i++) {
		temp[i] = this->allTeamLeaders[i];
	}
	//for (int i = 0; i < this->numberAllTeamLeaders; i++) {
	//	delete[] this->allTeamLeaders[i];
	//}
	delete[] allTeamLeaders;

	temp[this->numberAllTeamLeaders] = other;
	this->numberAllTeamLeaders += 1;
	this->allTeamLeaders = new (std::nothrow) TeamLeader*[this->capacityAllTeamLeaders];
	if (this->allTeamLeaders == NULL)
		return;
	for (int i = 0; i < this->numberAllTeamLeaders; i++) {
		this->allTeamLeaders[i] = temp[i];
	}
	//for (int i = 0; i < this->numberAllTeamLeaders - 1; i++) {
	//	delete[] temp[i];
	//}
	delete[] temp;
}

int Director::getNumberAllEmployees() const {
	return this->numberAllEmployees;
}

int Director::getNumberAllSpecialists() const {
	return this->numberAllSpecialists;
}

int Director::getNumberAllTeamLeaders() const {
	return this->numberAllTeamLeaders;
}

Employee** Director::getAllEmployees() const {
	return this->allEmployees;
}

Specialist** Director::getAllSpecialists() const {
	return this->allSpecialists;
}

TeamLeader** Director::getAllTeamLeaders() const {
	return this->allTeamLeaders;
}

void Director::copyDirector(const Director& other) {
	setSecretary(other.getSecretary());
	this->numberAllEmployees = other.getNumberAllEmployees();
	this->numberAllSpecialists = other.getNumberAllSpecialists();
	this->numberAllTeamLeaders = other.getNumberAllTeamLeaders();

	this->capacityAllEmployees = other.capacityAllEmployees;
	this->capacityAllSpecialists = other.capacityAllSpecialists;
	this->capacityAllTeamLeaders = other.capacityAllTeamLeaders;

	this->allEmployees = new (std::nothrow) Employee*[this->capacityAllEmployees];
	if (this->allEmployees == NULL)
		return;
	for (int i = 0; i < this->numberAllEmployees; i++) {
		this->allEmployees[i] = other.getAllEmployees()[i];
	}

	this->allSpecialists = new (std::nothrow) Specialist*[this->capacityAllSpecialists];
	if (this->allSpecialists == NULL)
		return;
	for (int i = 0; i < this->numberAllSpecialists; i++) {
		this->allSpecialists[i] = other.getAllSpecialists()[i];
	}

	this->allTeamLeaders = new (std::nothrow) TeamLeader*[this->capacityAllTeamLeaders];
	if (this->allTeamLeaders == NULL)
		return;
	for (int i = 0; i < this->numberAllTeamLeaders; i++) {
		this->allTeamLeaders[i] = other.getAllTeamLeaders()[i];
	}
}

void Director::clearDirector() {
	//for (int i = 0; i < this->numberAllEmployees; i++) {
	//	delete[] this->allEmployees[i];
	//}
	delete[] this->allEmployees;
	this->numberAllEmployees = 0;
	this->capacityAllEmployees = 2;

	//for (int i = 0; i < this->numberAllSpecialists; i++) {
	//	delete[] this->allSpecialists[i];
	//}
	delete[] this->allSpecialists;
	this->numberAllSpecialists = 0;
	this->capacityAllSpecialists = 2;

	//for (int i = 0; i < this->numberAllTeamLeaders; i++) {
	//	delete[] this->allTeamLeaders[i];
	//}
	delete[] this->allTeamLeaders;
	this->numberAllTeamLeaders = 0;
	this->capacityAllTeamLeaders = 2;
}