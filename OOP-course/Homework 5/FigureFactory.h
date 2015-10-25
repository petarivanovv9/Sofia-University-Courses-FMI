#pragma once

#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

#include <fstream>

class FigureFactory {
public:
	FigureFactory();
	FigureFactory(const char*);
	~FigureFactory();
public:
	void openFile(const char*);
	void closeFile();
public:
	bool canCreate();
	Figure* createFigure();
private:
	Figure* readCircle();
	Figure* readRectangle();
	Figure* readTriangle();
private:
	std::ifstream inputFile;
	int line;
};

