#pragma once

#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(double, double, double, double, double, double);
	//Triangle(const Triangle& other);
	//Triangle& operator=(const Triangle& other);
	virtual ~Triangle();

	virtual bool isPointInFigure(double, double) const;
	virtual void print() const;
private:
	double aPointX;
	double aPointY;

	double bPointX;
	double bPointY;
	
	double cPointX;
	double cPointY;
};

