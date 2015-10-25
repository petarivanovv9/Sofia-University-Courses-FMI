#pragma once

#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(double, double, double, double);
	//Rectangle(const Rectangle& other);
	//Rectangle& operator=(const Rectangle& other);
	virtual ~Rectangle();

	virtual bool isPointInFigure(double, double) const;
	virtual void print() const;
private:
	double aPointX;
	double aPointY;

	double cPointX;
	double cPointY;
};

