#include <iostream>
#include <vector>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

#include "Figure.h"
#include "FigureFactory.h"

typedef std::vector<Figure*> FIGVECTOR;

int main() {

	//Circle circle_1(0.0, 0.0, 2.0);
	//Rectangle rectancle_1(-1, -1, 2, 2);
	//Triangle triangle_1(0, 0, 2, 1, 1, 4);

	//double point_1_x = 1.1;
	//double point_1_y = 1.9;

	//if (circle_1.isPointInFigure(point_1_x, point_1_y)) {
	//	std::cout << "The point is in the circle" << std::endl;
	//}
	//else {
	//	std::cout << "The point is not in the circle" << std::endl;
	//}

	//if (rectancle_1.isPointInFigure(point_1_x, point_1_y)) {
	//	std::cout << "The point is in the rectangle" << std::endl;
	//}
	//else {
	//	std::cout << "The point is not in the rectangle" << std::endl;
	//}

	//if (triangle_1.isPointInFigure(point_1_x, point_1_y)) {
	//	std::cout << "The point is in the triangle" << std::endl;
	//}
	//else {
	//	std::cout << "The point is not in the triangle" << std::endl;
	//}


	FIGVECTOR figures;
	
	// Name of the figure input file 
	const char* fileName = "figure_input.txt";

	FigureFactory pFactory(fileName);

	Figure* pFigure = NULL;

	do {
		try {
			pFigure = pFactory.createFigure();

			if (pFigure)
				figures.push_back(pFigure);
		}
		catch (std::bad_alloc& e) {
			std::cerr << "ERROR: Allocation failed! Reason: " << e.what() << "\n";
			break;
		}
		catch (std::exception& e) {
			std::cerr << "ERROR: Operation failed! Reason: " << e.what() << std::endl;
		}
	} while (pFactory.canCreate() && pFigure);


	double point_1_x = 1.1;
	double point_1_y = 0.9;

	for (int i = 0; i < figures.size(); i++) {
		//print the coordinates of the figure
		figures.at(i)->print();

		//check is the point in the figure
		bool result = figures.at(i)->isPointInFigure(point_1_x, point_1_y);

		if (result) {
			std::cout << "The point is in the figure" << std::endl;
		}
		else {
			std::cout << "The point is not in the figure" << std::endl;
		}
	}


	for (int i = 0; i < figures.size(); i++) {
		delete figures.at(i);
	}

	return 0;
}