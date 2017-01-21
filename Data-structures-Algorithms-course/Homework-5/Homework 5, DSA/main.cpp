///
///  main.cpp : Defines the entry point for the console application.
///  Homework 5
///
///  Created by Petar Ivanov with #45121.
///


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>


///
/// Print people with the largest number of connections with other people
///
void getPeopleWithMaxConnections(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &peopleNames);

///
/// Print groups with the largest number of connections with other groups
///
void getGroupsWithMaxConnections(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &groupNames);

///
/// Print people with the largest number of closeness centrality
///
void getPeopleWithHighestClosenessCentrality(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &peopleNames);


int main() {

	std::ifstream fin;
	fin.open("stat.csv");
	if (!fin.is_open()){
		std::cerr << "Failed to open file.";
		return 1;
	}

	std::vector<std::string> groupNames;
	std::vector<std::string> peopleNames;
	std::vector<std::vector<int>> peopleGroupAttendance;

	std::string item;
	int counter = 0;
	
	for (std::string line; getline(fin, line); ) {
		std::istringstream in(line);

		while (getline(in, item, ',') && counter == 0) {
			groupNames.push_back(item);
		}

		if (counter > 0) {
			peopleNames.push_back(item);
			std::vector<int> currentLineNumbers;

			while (getline(in, item, ',')) {
				currentLineNumbers.push_back(atoi(item.c_str()));
			}
			peopleGroupAttendance.push_back(currentLineNumbers);
		}

		counter++;
	}

	///
	/// Print people with the largest number of connections with other people
	///
	getPeopleWithMaxConnections(peopleGroupAttendance.size(), peopleGroupAttendance.at(0).size(), peopleGroupAttendance, peopleNames);


	///
	/// Print groups with the largest number of connections with other groups
	///
	getGroupsWithMaxConnections(peopleGroupAttendance.size(), peopleGroupAttendance.at(0).size(), peopleGroupAttendance, groupNames);


	///
	/// Print people with the largest number of closeness centrality
	///
	getPeopleWithHighestClosenessCentrality(peopleGroupAttendance.size(), peopleGroupAttendance.at(0).size(), peopleGroupAttendance, peopleNames);

	return 0;
}

void getPeopleWithMaxConnections(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &peopleNames) {
	int** transposePeopleGroupAttendance = new (std::nothrow) int*[cols];
	for (int i = 0; i < cols; i++) {
		transposePeopleGroupAttendance[i] = new (std::nothrow) int[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposePeopleGroupAttendance[j][i] = peopleGroupAttendance.at(i).at(j);
		}
	}

	int** people_by_people_matrix = new (std::nothrow) int*[rows];
	for (int i = 0; i < rows; i++) {
		people_by_people_matrix[i] = new (std::nothrow) int[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			people_by_people_matrix[i][j] = 0;
		}
	}

	int max_number = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			for (int k = 0; k < cols; ++k) {
				people_by_people_matrix[i][j] += peopleGroupAttendance.at(i).at(k) * transposePeopleGroupAttendance[k][j];
			}
			if (max_number < people_by_people_matrix[i][j] && j < i) {
				max_number = people_by_people_matrix[i][j];
			}
		}
	}

	std::cout << "People with the largest number of connections with other people: " << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (people_by_people_matrix[i][j] == max_number && i < j) {
				std::cout << peopleNames.at(i) << "<------>" << peopleNames.at(j) << std::endl;
			}
		}
	}
	std::cout << std::endl;

	///
	/// delete transposePeopleGroupAttendance matrix
	///
	for (int i = 0; i < cols; i++) {
		delete[] transposePeopleGroupAttendance[i];
	}
	delete[] transposePeopleGroupAttendance;

	///
	/// delete people_by_people_matrix
	///
	for (int i = 0; i < rows; i++) {
		delete[] people_by_people_matrix[i];
	}
	delete[] people_by_people_matrix;
}


void getGroupsWithMaxConnections(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &groupNames) {
	int** transposePeopleGroupAttendance = new (std::nothrow) int*[cols];
	for (int i = 0; i < cols; i++) {
		transposePeopleGroupAttendance[i] = new (std::nothrow) int[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposePeopleGroupAttendance[j][i] = peopleGroupAttendance.at(i).at(j);
		}
	}

	int** groups_by_groups_matrix = new (std::nothrow) int*[cols];
	for (int i = 0; i < cols; i++) {
		groups_by_groups_matrix[i] = new (std::nothrow) int[cols];
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < cols; j++) {
			groups_by_groups_matrix[i][j] = 0;
		}
	}

	int max_number = 0;

	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < cols; ++j) {
			for (int k = 0; k < rows; ++k) {
				groups_by_groups_matrix[i][j] += transposePeopleGroupAttendance[i][k] * peopleGroupAttendance.at(k).at(j);
			}
			if (max_number < groups_by_groups_matrix[i][j] && i != j) {
				max_number = groups_by_groups_matrix[i][j];
			}
		}
	}

	std::cout << "Groups with the largest number of connections with other groups: " << std::endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < cols; j++) {
			//std::cout << groups_by_groups_matrix[i][j] << " ";
			if (groups_by_groups_matrix[i][j] == max_number && i != j) {
				std::cout << groupNames.at(i + 1) << std::endl;
			}
		}
		//std::cout << std::endl;
	}
	std::cout << std::endl;

	///
	/// delete transposePeopleGroupAttendance matrix
	///
	for (int i = 0; i < cols; i++) {
		delete[] transposePeopleGroupAttendance[i];
	}
	delete[] transposePeopleGroupAttendance;

	///
	/// delete groups_by_groups_matrix
	///
	for (int i = 0; i < cols; i++) {
		delete[] groups_by_groups_matrix[i];
	}
	delete[] groups_by_groups_matrix;
}


void getPeopleWithHighestClosenessCentrality(int rows, int cols, std::vector<std::vector<int>> &peopleGroupAttendance, std::vector<std::string> &peopleNames) {
	int** transposePeopleGroupAttendance = new (std::nothrow) int*[cols];
	for (int i = 0; i < cols; i++) {
		transposePeopleGroupAttendance[i] = new (std::nothrow) int[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposePeopleGroupAttendance[j][i] = peopleGroupAttendance.at(i).at(j);
		}
	}

	int** people_by_people_matrix = new (std::nothrow) int*[rows];
	for (int i = 0; i < rows; i++) {
		people_by_people_matrix[i] = new (std::nothrow) int[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			people_by_people_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			for (int k = 0; k < cols; ++k) {
				people_by_people_matrix[i][j] += peopleGroupAttendance.at(i).at(k) * transposePeopleGroupAttendance[k][j];
			}
		}
	}

	int min_number = people_by_people_matrix[0][0];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < rows; ++j) {
			for (int k = 0; k < rows; ++k) {
				if ((people_by_people_matrix[j][i] * people_by_people_matrix[i][k] != 0) != (j != k)) {
					if (i != j && i != k && j != k && (people_by_people_matrix[j][i] + people_by_people_matrix[i][k] < people_by_people_matrix[j][k])) {
						people_by_people_matrix[j][k] = people_by_people_matrix[j][i] + people_by_people_matrix[i][k];
					}
				}
			}
		}
	}

	int sum = 0;
	int max_sum = 0;
	int max_row = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < rows; j++) {
			sum += people_by_people_matrix[i][j];
		}
		if (max_sum < sum) {
			max_sum = sum;
			max_row = i;
		}
	}

	std::cout << "People with the largest number of closeness centrality: " << std::endl;
	std::cout << peopleNames.at(max_row) << std::endl;
	std::cout << std::endl;

	//std::cout << min_number << std::endl;

	//for (int i = 0; i < rows; i++) {
	//	for (int j = 0; j < rows; j++) {
	//		if (people_by_people_matrix[i][j] == min_number && i < j) {
	//			std::cout << peopleNames.at(i) << std::endl;
	//		}
	//	}
	//}
	//std::cout << std::endl;


	///
	/// delete transposePeopleGroupAttendance matrix
	///
	for (int i = 0; i < cols; i++) {
		delete[] transposePeopleGroupAttendance[i];
	}
	delete[] transposePeopleGroupAttendance;

	///
	/// delete people_by_people_matrix
	///
	for (int i = 0; i < rows; i++) {
		delete[] people_by_people_matrix[i];
	}
	delete[] people_by_people_matrix;	
}