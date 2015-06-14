#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle() {
	std::cout << "[Entering Rectangle::Rectangle()]\n";
}

Rectangle::Rectangle(double aX, double aY, double cX, double cY) {
	std::cout << "[Entering Rectangle::Rectangle(double, double, double, double)]\n";
	this->aPointX = aX;
	this->aPointY = aY;

	this->cPointX = cX;
	this->cPointY = cY;
}

Rectangle::~Rectangle() {
	std::cout << "[Entering Rectangle::~Rectangle()]\n";
}

void Rectangle::print() const {
	std::cout << "A Rectangle"
		<< " with A:" << this->aPointX << " " << this->aPointY
		<< " with C:" << this->cPointX << " " << this->cPointY
		<< std::endl;
}

bool Rectangle::isPointInFigure(double pointX, double pointY) const {
	return pointX >= this->aPointX && pointX <= this->cPointX && pointY <= this->cPointY && pointY >= this->aPointY;
}
