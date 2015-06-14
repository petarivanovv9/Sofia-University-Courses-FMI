#pragma once

#include "Employee.h"
#include "Specialist.h"

class TeamLeader : public Specialist {
public:
	TeamLeader();
	TeamLeader(char*, char*, char*, int, char*, char*);
	TeamLeader(const TeamLeader& other);
	TeamLeader& operator=(const TeamLeader& other);
	~TeamLeader();
public:
	//const Employee** getEmployeesTeam() const;
	Employee** getEmployeesTeam() const;

	char* getDepartmentDescription() const;
	int getNumberEmployees() const;
public:
	void setDepartmentDescription(const char*);
public:
	//void addEmployee(const Employee& other);
	
	//void addEmployee(Employee& other);
	void addEmployee(Employee* other);
	
	void printTeamLeader() const;
private:
	void clearTeamLeader();
	void copyTeamLeader(const TeamLeader& other);
private:
	char* departmentDescription;
	Employee** employees;
	int numberEmployees;
	int capacityEmployees;
}; 
