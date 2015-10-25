#pragma once

#include "Secretary.h"
#include "Employee.h"
#include "TeamLeader.h"

class Director {
public:
	Director();
	//Director(const Secretary& otherSecretary);
	Director(const Director& other);
	Director& operator=(const Director& other);
	~Director();
public:
	void addEmployee(Employee* other);
	void addSpecialist(Specialist* other);
	void addTeamLeader(TeamLeader* other);
public:
	Secretary getSecretary() const;
	void setSecretary(const Secretary& other);
	int getNumberAllEmployees() const;
	int getNumberAllSpecialists() const;
	int getNumberAllTeamLeaders() const;

	Employee** getAllEmployees() const;
	Specialist** getAllSpecialists() const;
	TeamLeader** getAllTeamLeaders() const;
private:
	void copyDirector(const Director& other);
	void clearDirector();
private:
	Secretary mySecretary;

	Employee** allEmployees;
	int numberAllEmployees;
	int capacityAllEmployees;

	Specialist** allSpecialists;
	int numberAllSpecialists;
	int capacityAllSpecialists;

	TeamLeader** allTeamLeaders;
	int numberAllTeamLeaders;
	int capacityAllTeamLeaders;
};