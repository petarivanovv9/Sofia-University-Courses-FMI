#pragma once

#include "Figure.h"

class Group : public Figure {
public:
	Group();
	//Group(const Group& other);
	//Group& operator=(const Group& other);
	~Group();
private:
	Figure** figures;
	int numberFigures;
};

