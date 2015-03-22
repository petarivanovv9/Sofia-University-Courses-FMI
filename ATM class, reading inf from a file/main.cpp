#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>

using namespace std;

// read users and the inf about them from a file

class ATM {
private:
	double amountOfMoney;
	char* bankName;
	char* ID;

public:
	ATM(double, char*, char*);
	void withdrawMoney(char*, double);
	void checkAmount(char*);
	void print();
};

ATM::ATM(double amountOfMoney, char* bankName, char* ID) {
	this->amountOfMoney = amountOfMoney;
	this->bankName = new char[100];
	this->bankName = bankName;
	this->ID = new char[100];
	this->ID = ID;
}

void ATM::checkAmount(char* userID) {
	ifstream myFile;
	myFile.open("ATM.txt", ios::in);

	if (!myFile.is_open()) {
		cerr << "Error! Can't open the file!" << "\n";
	}

	char userAmount[10] = "";
	char* fileContent = new char[100];

	char c = '*';

	// get the position of the reading pointer
	// start position in the file
	int startPos = myFile.tellg();

	while (c != '#') {
		myFile.get(c);
	}
	// last position in the file
	int endPos = myFile.tellg();

	myFile.seekg(startPos);
	myFile.getline(fileContent, endPos - startPos);
	myFile.close();

	char* start = fileContent;
	char* startUser = userID;
	bool foundUser = false;

	while (*fileContent && !foundUser) {
		while (*fileContent && *fileContent != *userID) {
			fileContent++;
		}
		// go throut the fileContent in order to find the specific user ID
		while (*fileContent && *userID && *fileContent == *userID) {
			fileContent++;
			userID++;
		}

		if (*userID) {
			userID = startUser;
		}
		else {
			if (*fileContent == '-') {
				fileContent++;
				foundUser = true;
				int counter = 0;
				// get the user's amout of money
				while (*fileContent && *fileContent != ',') {
					userAmount[counter] = *fileContent;
					counter++;
					fileContent++;
				}

				userAmount[counter] = '\0';
			}
		}

		userID = startUser;
		
		if (*fileContent) {
			fileContent++;
		}
	}
	
	if (strlen(userAmount) == 0) {
		cout << "ID not found!" << endl;
	}
	else {
		cout << "Your balance is: " << userAmount << endl;
	}

}

void ATM::print() {
	cout << "Amount of money: " << amountOfMoney << endl;
	cout << "Name of bank: " << bankName << endl;
	cout << "ID of ATM: " << ID << endl;
}

void ATM::withdrawMoney(char* ID, double amount) {
	fstream myFile;
	myFile.open("ATM.txt");

	if (!myFile.is_open()) {
		cerr << "Error! Can't open the file!" << "\n";
	}

	char* text = new char[100];
	char c = '*';

	int startPos = myFile.tellg(); // start of the file

	while (c != '#') {
		myFile.get(c);
	}

	int endPos = myFile.tellg(); // end of the file

	myFile.seekg(startPos);
	myFile.getline(text, endPos); // get the line from the file and save it into the text char array
	myFile.close();

	int counter = 0; // we will use this variable as an index
	char* start = ID; // copy the pointer in order to iterate with ID value
	int startAmount = 0;
	char idAmount[10] = "";
	int idAmountCounter = 0;
	bool done = false;

	while (text[counter] != '\0' && !done) {
		while (text[counter] != '\0' && text[counter] != *ID) {
			counter++;
		}
		// going through the text in order to find the specific user ID
		while (text[counter] != '\0' && *ID && text[counter] == *ID) {
			counter++;
			ID++;
		}
		if (*ID) {
			ID = start;
			while (text[counter] != '\0' && text[counter] != ',') {
				counter++;
			}
		}
		else {
			counter++;
			startAmount = counter;
			// get the amount of money of the user
			while (text[counter] != '\0' && text[counter] != ',') {	
				idAmount[idAmountCounter] = text[counter];
				idAmountCounter++;
				counter++;
			}
			idAmount[idAmountCounter] = '\0';
			done = true;
		}
		if (text[counter] != '\0') {
			counter++;
		}
	}
	if (strlen(idAmount) == 0) {
		cout << "ID not found!" << endl;
	}
	else {
		int firstAmount = strlen(idAmount);
		double idSum = atof(idAmount); // convert the char array into a number(integer)
		if (idSum < amount) {
			cout << "You do not have that kind of money!" << endl;
		}
		else { // withdraw money
			amountOfMoney -= amount;
			idSum -= amount;
			itoa(idSum, idAmount, 10);  // convert the integer number into char array
			
			int secondAmount = strlen(idAmount);

			if (firstAmount > secondAmount) {
				secondAmount = firstAmount;
			}
			// change user's money after withdrawing
			myFile.open("ATM.txt");
			myFile.seekg(startAmount);
			myFile.write(idAmount, secondAmount);
			myFile.close();
		}
	}
	
}

int main() {
	
	ATM	random(20000, "PeshoBank", "9999");
	int answer = 0;
	char id[10];

	cout << "Enter your ID: ";
	cin.getline(id, 10);

	cout << "1. Check your balance." << endl
		<< "2. Withdraw money." << endl
		<< "3. Show ATM values." << endl
		<< "0. Exit." << endl;

	do {
		cout << "Enter your choice: ";
		cin >> answer;

		switch (answer) {
			case 1: {
				random.checkAmount(id);
				break;
			}
			case 2: {
				double amount = 0;
				cout << "Enter the amount of money you wish to take: ";
				cin >> amount;
				random.withdrawMoney(id, amount);
				break;
			}
			case 3: {
				random.print();
			}
		}
	} while (answer != 0);

	return 0;
}