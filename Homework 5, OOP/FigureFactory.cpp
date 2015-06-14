#include "FigureFactory.h"

#include <iostream>


FigureFactory::FigureFactory() {
	this->line = 0;
}

FigureFactory::FigureFactory(const char* fileName) {
	openFile(fileName);
	line = 1;
}

FigureFactory::~FigureFactory() {
	closeFile();
}

void FigureFactory::openFile(const char* fileName) {
	this->inputFile.open(fileName);
	line = 1;
}

void FigureFactory::closeFile() {
	this->inputFile.close();
}

bool FigureFactory::canCreate() {
	return this->inputFile.is_open() && this->inputFile.good();
}

Figure* FigureFactory::createFigure() {
	char figureType[100];

	this->inputFile >> figureType;

	if (!this->inputFile)
		return NULL;

	if (strcmp(figureType, "circle") == 0) {
		double xCenter;
		double yCenter;
		double radius;
		this->inputFile >> xCenter;
		this->inputFile >> yCenter;
		this->inputFile >> radius;

		if (!this->inputFile) {
			char message[100];
			sprintf_s(message, 100, "Error on line %u while reading circle data!", line);
			throw std::exception(message);
		}

		line++;

		return new Circle(xCenter, yCenter, radius);
	}
	else if (strcmp(figureType, "rect") == 0) {
		double aPointX, aPointY;
		double cPointX, cPointY;

		this->inputFile >> aPointX;
		this->inputFile >> aPointY;
		this->inputFile >> cPointX;
		this->inputFile >> cPointY;

		if (!this->inputFile) {
			char message[100];
			sprintf_s(message, 100, "Error on line %u while reading circle data!", line);
			throw std::exception(message);
		}

		line++;

		return new Rectangle(aPointX, aPointY, cPointX, cPointY);
	}
	else if (strcmp(figureType, "triangle") == 0) {
		double aPointX, aPointY;
		double bPointX, bPointY;
		double cPointX, cPointY;

		this->inputFile >> aPointX;
		this->inputFile >> aPointY;
		this->inputFile >> bPointX;
		this->inputFile >> bPointY;
		this->inputFile >> cPointX;
		this->inputFile >> cPointY;

		if (!this->inputFile) {
			char message[100];
			sprintf_s(message, 100, "Error on line %u while reading circle data!", line);
			throw std::exception(message);
		}

		line++;

		return new Triangle(aPointX, aPointY, bPointX, bPointY, cPointX, cPointY);
	}
	else {
		char message[130];
		sprintf_s(message, 130, "Unknown figure type \"%s\"", figureType);
		throw std::exception(message);
	}
}
