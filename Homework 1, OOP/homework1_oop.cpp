// Petar Ivanov, Faculty number: 45121
// Informatics, group 1,
// OOP Homework 1

#include <iostream>
#include <fstream>
#include <cstring>

const int SIZE_NAME = 23;

struct Car {
	char carName[SIZE_NAME];
	int carHorsePower;
};

struct CarOwner {
	char carOwnerName[SIZE_NAME];
	int idCarNumber;
	int regNumber;
};

void addCarOwnerToFile(); // добавя всички записи на притежатели на коли във файла db-save.dat
bool checkRegCarNumber(int); // проверява дали регистрационния номер на колата вече съществува
double avrgCarsHorsePower(const Car cars[]); // намира средната мощност на всички коли до момента
int mostPopularCar(); // намира най-популярната кола
int ownersAdded(); // връща бройката на притежатели на коли във файла db-save.dat до момента

// добавя най-популярната кола, средната мощност на всички притежавани коли
// и по 1 ред за всеки притежател с името и общата мощност на притежаваните от него коли във файла car-report.txt
void addOwnerCarsToFile(const Car cars[]);


		
int main() {

	// инициализация на масив от структури с възможните коли
	const Car cars[4] = {
		{ "Lambordgini Murcielago", 670 },
		{ "Mercedes-AMG", 503 },
		{ "Pagani Zonda R", 740 },
		{ "Bugatti Veyron", 1020 }
	};

	int choice = 0;
	
	// генериране на меню за удобство на потребителя
	std::cout << "Menu:" << "\n";
	std::cout << "1. Add new car owner." << std::endl
		<< "2. Check what is the average horse power of all cars." << std::endl
		<< "3. Check which is the most popular car." << std::endl
		<< "4. Generate car report file." << std::endl
		<< "0. Exit the application." << std::endl << std::endl;
	
	do {
		std::cin.clear();
		std::cin.sync();
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
			case 1: {
				addCarOwnerToFile();
				std::cout << std::endl;
				break;
			}
			case 2: {
				std::cout << "The average horse power of all cars is: "
					<< avrgCarsHorsePower(cars) << std::endl << std::endl;
				break;
			}
			case 3: {
				std::cout << "The most popular car is: "
					<< cars[mostPopularCar()].carName << std::endl << std::endl;
				break;
			}
			case 4: {
				addOwnerCarsToFile(cars);
				std::cout << "The car-report file was generated successfully." << std::endl << std::endl;
				break;
			}
			case 0: {
				return 0;
				break;
			}
		}
	} while (!std::cin.good() || choice != 0);

	return	0;
}

void addCarOwnerToFile() {

	CarOwner Owner;

	char ownerName[SIZE_NAME];
	std::cout << "Enter the car owner name (less than 23): ";
	std::cin.get();
	std::cin.getline(ownerName, SIZE_NAME);

	strcpy(Owner.carOwnerName, ownerName);

	int regNum = 0;
	std::cout << "Enter the registration car number: ";
	std::cin >> regNum;

	Owner.regNumber = regNum;

	if (checkRegCarNumber(regNum)) {
		std::cerr << "ERROR! The registration car number exist!" << std::endl;
		return;
	}

	int idNum = 0;
	std::cout << "Enter the identification car number (0, 1, 2, 3): ";
	std::cin >> idNum;

	if (idNum > 3 || idNum < 0) {
		std::cerr << "ERROR! Invalid indentification car number." << std::endl;
		return;
	}

	Owner.idCarNumber = idNum;

	std::ofstream myFile("db-save.dat", std::ios::binary | std::ios::app);

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		return;
	}

	myFile.write((const char*)&Owner, sizeof(CarOwner));

	myFile.close();
}

bool checkRegCarNumber(int idCarNum) {
	bool isNumExist = false;

	std::ifstream myFile("db-save.dat", std::ios::binary);

	CarOwner Owner;

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		std::exit;
	}

	do {
		myFile.read((char*)&Owner, sizeof(CarOwner));

		if (myFile) {
			if (idCarNum == Owner.regNumber) {
				return true;
			}
		}

	} while (myFile);

	return isNumExist;
}

double avrgCarsHorsePower(const Car cars[]) {
	std::ifstream myFile("db-save.dat", std::ios::binary);

	CarOwner Owner;

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		std::exit;
	}

	int counterCars = 0;
	int totalHorsePower = 0;
	int currentIdCar;

	do {
		myFile.read((char*)&Owner, sizeof(CarOwner));

		if (myFile) {
			counterCars += 1;
			currentIdCar = Owner.idCarNumber;
			totalHorsePower += cars[currentIdCar].carHorsePower;
		}

	} while (myFile);

	if (counterCars == 0) {
		return 0;
	}

	return totalHorsePower / counterCars;
}

int mostPopularCar() {

	std::ifstream myFile("db-save.dat", std::ios::binary);

	CarOwner Owner;

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		std::exit;
	}

	int popularCar[4] = { 0, 0, 0, 0 }; // масив, който пази бройката на срещанията на дадена кола във файла

	do {
		myFile.read((char*)&Owner, sizeof(CarOwner));

		if (myFile) {
			if (Owner.idCarNumber == 0) {
				popularCar[0] += 1;
			}
			if (Owner.idCarNumber == 1) {
				popularCar[1] += 1;
			}
			if (Owner.idCarNumber == 2) {
				popularCar[2] += 1;
			}
			if (Owner.idCarNumber == 3) {
				popularCar[3] += 1;
			}
		}

	} while (myFile);

	int temp = 0;
	int index = 0;

	// намиране на най-популярната кола
	for (int i = 0; i < 4; i++) {
		if (popularCar[i] > temp) {
			temp = popularCar[i];
			index = i;
		}
	}

	return index;
}

void addOwnerCarsToFile(const Car cars[]) {

	std::ofstream myTextFile("car-report.txt", std::ios::trunc);

	if (!myTextFile) {
		std::cerr << "Error!" << std::endl;
		return;
	}

	myTextFile << "The most popular car is: " << cars[mostPopularCar()].carName << std::endl;
	myTextFile << "The average horse power of all cars is: " << avrgCarsHorsePower(cars) << std::endl;

	int counterOwners = ownersAdded();

	char** ownersName = new char*[counterOwners]; // масив, в който се пазят имената на всички притежатели на коли

	for (int i = 0; i < counterOwners; i++) {
		ownersName[i] = new char[SIZE_NAME];
	}

	std::ifstream myFile("db-save.dat", std::ios::binary);

	CarOwner Owner;

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		std::exit;
	}

	int row = 0;
	bool isNameInOwnersName = false;

	do {
		myFile.read((char*)&Owner, sizeof(CarOwner));
		
		if (myFile) {
			isNameInOwnersName = false;

			for (int i = 0; i < counterOwners; i++) {
				// проверяване дали името на притежател на кола вече е в масива
				if (strcmp(Owner.carOwnerName, ownersName[i]) == 0) {
					isNameInOwnersName = true;
					break;
				}
			}
			// добавяне на името на притежател на кола в масива, ако то вече не е било записано
			if (isNameInOwnersName == false) {
				strcpy(ownersName[row], Owner.carOwnerName);
				row += 1;
			}
		}
	} while (myFile);

	int currentOwnerCarsHorsePower = 0;

	// пренасочване на поинтера за четене в началото на файла
	// тъй като след последното прочитане на файла, поинтера седи в края му
	myFile.clear();
	myFile.seekg(0, std::ios::beg);

	for (int i = 0; i < row; i++) {
		currentOwnerCarsHorsePower = 0;
		myFile.clear();
		myFile.seekg(0, std::ios::beg);
		do {
			myFile.read((char*)&Owner, sizeof(CarOwner));

			if (myFile) {
				// проверка дали името на притежател на кола се среща във файла
				// т.е дали един даден човек има повече от една кола и сумира конските сили на колите му
				if (strcmp(Owner.carOwnerName, ownersName[i]) == 0) {
					currentOwnerCarsHorsePower += cars[Owner.idCarNumber].carHorsePower;
				}
			}
		} while (myFile);
		myTextFile << ownersName[i] << ' ' << currentOwnerCarsHorsePower << std::endl;
	}

	myTextFile.close();
	myFile.close();
}

int ownersAdded() {
	int counterOwners = 0;

	std::ifstream myFile("db-save.dat", std::ios::binary);

	if (!myFile) {
		std::cerr << "Error!" << std::endl;
		std::exit;
	}

	CarOwner Owner;

	int counterBytes = 0;
	
	do {
		myFile.read((char*)&Owner, sizeof(CarOwner));

		if (myFile) {
			counterOwners += 1;
		}

	} while (myFile);

	myFile.close();

	return counterOwners;
}