#include "Point.h"
#include "Shape.h"
#include <string>
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "OnePoint.h"
#include <iostream>
#include "Figure.h"
#include "Point.h"

static const int initListSize = 20;

void Figure::addShape(Polygon* s)
{
	if (!m_arr) 
	{
		m_arr = new Polygon*[initListSize]; 
		m_arrMaxSize = initListSize;
	}

	if (m_arrLength < m_arrMaxSize)
		m_arr[m_arrLength++] = s;
	else 
	{
		Polygon **temp = m_arr;
		m_arrMaxSize += 20;
		m_arr = new Polygon*[initListSize + 20];
		for (int i = 0; i < m_arrLength; i++)
			m_arr[i] = temp[i];
		m_arr[m_arrLength++] = s;
		delete[] temp;
		temp = nullptr;
	}
}

void Figure::getBoundingBox()
{
	BoundBox ret;
	double xMin = 0;
	double yMax = 0;
	double xMax = 0;
	double yMin = 0;

	for (int i = 0; i < m_arrLength; i++)
	{
		Polygon *s = m_arr[i];
		ret = s->getBoundingBox();
		if (ret.upperLeft.getY() > yMax)
			yMax = ret.upperLeft.getY();
		if (ret.upperLeft.getX() < xMin)
			xMin = ret.upperLeft.getX();
		if (ret.lowerRight.getY() < yMin)
			yMin = ret.lowerRight.getY();
		if (ret.upperLeft.getX() > xMax)
			xMax = ret.lowerRight.getX();
	}
	BoundBox finalReturn;
	Point upperL(xMin, yMax);
	Point lowerR(xMax, yMin);
	finalReturn.upperLeft = upperL;
	finalReturn.lowerRight = lowerR;

	std::cout << "(" << finalReturn.upperLeft.getX() << "," << finalReturn.upperLeft.getY() << ")" << " " << "(" << finalReturn.lowerRight.getX() << "," << finalReturn.lowerRight.getY() << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Figure& rhs)
{
	for (int i = 0; i < rhs.m_arrLength; i++) {
		const Polygon* s = rhs.m_arr[i];
		os <<  s->print() << std::endl;
	}
	return os;
}
