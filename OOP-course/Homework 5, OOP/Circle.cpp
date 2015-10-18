#include "Circle.h"

#include <iostream>

Circle::Circle() {
	std::cout << "[Entering Circle::Circle()]\n";
	this->xCenter = 0;
	this->yCenter = 0;
	this->radius = 0;
}

Circle::Circle(double xCenter, double yCenter, double radius) {
	std::cout << "[Entering Circle::Circle(double, double, double)]\n";
	this->xCenter = xCenter;
	this->yCenter = yCenter;
	this->radius = radius;
}

Circle::~Circle() {
	std::cout << "[Entering Circle::~Circle()]\n";
}

void Circle::print() const {
	std::cout << "A circle with center " 
		<< this->xCenter  << " " << this->yCenter
		<< std::endl;
	std::cout << "A circle with radius " << this->radius << std::endl;
}

bool Circle::isPointInFigure(double pointX, double pointY) const {
	return (pointX - this->xCenter)*(pointX - this->xCenter) + (pointY - this->yCenter)*(pointY - this->yCenter) <= this->radius * this->radius;
}
