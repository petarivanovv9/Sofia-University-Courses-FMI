#include "Triangle.h"

#include <iostream>

Triangle::Triangle() {
	std::cout << "[Entering Triangle::Triangle()]\n";

	this->aPointX = 0;
	this->aPointY = 0;

	this->bPointX = 0;
	this->bPointY = 0;

	this->cPointX = 0;
	this->cPointY = 0;
}

Triangle::Triangle(double aX, double aY, double bX, double bY, double cX, double cY) {
	std::cout << "[Entering Triangle::Triangle(double, double, double, double, double, double)]\n";
	this->aPointX = aX;
	this->aPointY = aY;

	this->bPointX = bX;
	this->bPointY = bY;

	this->cPointX = cX;
	this->cPointY = cY;
}

Triangle::~Triangle() {
	std::cout << "[Entering Triangle::~Triangle()]\n";
}

void Triangle::print() const {
	std::cout << "A Triangle"
		<< " with A:" << this->aPointX << " " << this->aPointY
		<< " with B:" << this->bPointX << " " << this->bPointY
		<< " with C:" << this->cPointX << " " << this->cPointY
		<< std::endl;
}

bool Triangle::isPointInFigure(double pointX, double pointY) const {
	double AB = (pointY - aPointY)*(bPointX - aPointX) - (pointX - aPointX)*(bPointY - aPointY);
	double CA = (pointY - cPointY)*(aPointX - cPointX) - (pointX - cPointX)*(aPointY - cPointY);
	double BC = (pointY - bPointY)*(cPointX - bPointX) - (pointX - bPointX)*(cPointY - bPointY);
	
	return AB*BC > 0 && BC*CA > 0;
}
