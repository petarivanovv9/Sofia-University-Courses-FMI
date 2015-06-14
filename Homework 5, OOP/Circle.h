#pragma once

#include "Figure.h"

class Circle : public Figure {
public:
	Circle();
	Circle(double, double, double);
	//Circle(const Circle& other);
	//Circle& operator=(const Circle& other);
	virtual ~Circle();

	virtual bool isPointInFigure(double, double) const;
	virtual void print() const;
private:
	double xCenter;
	double yCenter;
	double radius;
};

