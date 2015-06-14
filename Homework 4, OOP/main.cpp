#include <iostream>

#include "Employee.h"
#include "Specialist.h"
#include "TeamLeader.h"
#include "Secretary.h"
#include "Director.h"


int main() {

	Employee gonzo("Gonzo", "Ovchka kupel", "IT", 1000);
	gonzo.printEmployee();

	Employee petkan("Petkan", "Ovchka kupel 2", "Marketing", 1200);
	petkan.printEmployee();
	//std::cout << pesho.getSalary() << std::endl;

	Employee ivan(gonzo);
	ivan = gonzo;
	//std::cout << ivan.getSalary() << std::endl;

	Specialist mincho("Pesho", "Ovchka kupel", "IT", 2500, "django");
	mincho.printSpecialist();

	TeamLeader peshko("Peshko", "Ovchka kupel", "IT", 10000, "django", "nice");
	peshko.printTeamLeader();

	//peshko.addEmployee(ivan);
	peshko.printTeamLeader();

	Employee* pIvan = &ivan;
	Employee* pPetkan = &petkan;

	peshko.addEmployee(pIvan);
	peshko.addEmployee(pPetkan);
	peshko.printTeamLeader();


	TeamLeader petrito;
	//TeamLeader petrito(peshko);
	petrito = peshko;
	std::cout << petrito.getNumberEmployees() << std::endl;
	std::cout << petrito.getSpeciality() << std::endl;
	std::cout << "petrito name: " << petrito.getName() << std::endl;

	petrito.printTeamLeader();

	Employee** peshkoTeam = peshko.getEmployeesTeam();
	int peshoNumberEmployeesTeam = peshko.getNumberEmployees();
	for (int i = 0; i < peshoNumberEmployeesTeam; i++) {
		peshkoTeam[i]->printEmployee();
	}

	Secretary mariika;
	mariika.addLanguage("bulgarian");
	mariika.addLanguage("english");
	mariika.addLanguage("deutch");
	mariika.printSecretary();

	Secretary ivanka;
	ivanka = mariika;
	ivanka.printSecretary();

	Director big_pesho;
	big_pesho.setSecretary(ivanka);

	Employee* pGonzo = &gonzo;
	big_pesho.addEmployee(pGonzo);
	//Employee* pPetkan = &petkan;
	big_pesho.addEmployee(pPetkan);
	Specialist* pMincho = &mincho;
	big_pesho.addSpecialist(pMincho);
	TeamLeader* pPeshko = &peshko;
	big_pesho.addTeamLeader(pPeshko);

	int allMoney = 0;

	int a = big_pesho.getNumberAllEmployees();
	for (int i = 0; i < a; i++) {
		allMoney += big_pesho.getAllEmployees()[i]->getSalary();
	}

	int b = big_pesho.getNumberAllSpecialists();
	for (int i = 0; i < b; i++) {
		allMoney += big_pesho.getAllSpecialists()[i]->getSalary();
	}

	int c = big_pesho.getNumberAllTeamLeaders();
	for (int i = 0; i < c; i++) {
		allMoney += big_pesho.getAllTeamLeaders()[i]->getSalary();
	}

	std::cout << "----The amount of all money that will be needed is: " << allMoney << std::endl;
	
	Secretary antoaneta = big_pesho.getSecretary();
	antoaneta.printSecretary();


	return 0;
}