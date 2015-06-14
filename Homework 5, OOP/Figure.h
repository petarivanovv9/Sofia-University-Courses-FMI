#pragma once

class Figure {
public:
	Figure();
	virtual ~Figure() = 0;
	
	virtual bool isPointInFigure(double, double) const = 0;
	virtual void print() const = 0;
};

