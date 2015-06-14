#pragma once

class Employee {
public:
	Employee();
	Employee(char*, char*, char*, int);
	Employee(const Employee& other);
	~Employee();
	Employee& operator=(const Employee& other);
public:
	char* getName() const;
	char* getAddress() const;
	char* getDepartment() const;
	int getSalary() const;
public:
	void setAddress(const char*);
	void setName(const char*);
	void setDepartment(const char*);
	void setSalary(int);
public:
	void printEmployee() const;
private:
	char* name;
	char* address;
	char* department;
	int salary;
private:
	void clearEmployee();
	void copyEmployee(const Employee& other);
};