#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"
#include "Shape.h"
#include <string>
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "OnePoint.h"
#include <iostream>

class Figure
{
public:
	Figure() {};
	~Figure() { delete[] m_arr; };
	void addShape(Polygon* s);
	void getBoundingBox();
	friend std::ostream& operator<<(std::ostream& os, const Figure& rhs);

private:
	Polygon **m_arr = nullptr;
	int m_arrLength = 0;
	int m_arrMaxSize = 0;
};

#endif // FIGURE_H