#include "Polygon.h"
#include <cmath>
#include "Point.h"
#include <string>
#include <iostream>
#include <sstream>

Polygon::Polygon(const Polygon &obj) {
	m_c = obj.m_c;
	this->m_a = new Point[obj.m_c];
	for (int i = 0; i < obj.m_c; i++)
		this->m_a[i] = obj.m_a[i];
}

std::string Polygon::getType() const
{
    std::string myShape = "Polygon";
    return myShape;
}
double Polygon::getArea()
{
    int vertices = m_c;
    double area = 0.0;
    int j = (vertices - 1);
    for (int i = 0; i < vertices; i++)
    {
        area += (m_a[j].getX() + m_a[i].getX()) * (m_a[j].getY() - m_a[i].getY());
        j = i;
    }
    if (area == 0 || !isConvex())
        area = -1;
    else
        return area = fabs(area / 2.0);
    return area;
}

double Polygon::getCircumference()
{
    double PolyCircum = 0;
    int vertices = m_c;
    int j = vertices - 1;
    for (int i = 0; i < vertices; i++)
    {
        PolyCircum += sqrt(pow(m_a[i].getX() - m_a[j].getX(), 2) + pow(m_a[i].getY() - m_a[j].getY(), 2));
        j = i;
    }
    return PolyCircum;
}

Point Polygon::getPosition()
{
    double sumX = 0;
    double sumY = 0;
    int vertices = m_c;
    for (int i = 0; i < vertices; i++)
    {
        sumX += (m_a[i].getX()) / vertices;
        sumY += (m_a[i].getY()) / vertices;
    }
    Point centerPosition(sumX, sumY);
    return centerPosition;
}

bool Polygon::isConvex()
{
    int size = (m_c - 2);
    double *crossproduct = new double[size];
    double dix1, diy1, dix2, diy2;

    for (int i = 0; i < size; i++)
    {
        dix1 = m_a[i + 1].getX() - m_a[i].getX();
        diy1 = m_a[i + 1].getY() - m_a[i].getY();
        dix2 = m_a[i + 2].getX() - m_a[i + 1].getX();
        diy2 = m_a[i + 2].getY() - m_a[i + 1].getY();
        crossproduct[i] = (dix1 * diy2 - diy1 * dix2);
    }

    bool sumPos = false;
    bool sumNeg = false;

    for (int i = 0; i < size; i++)
    {
        if (crossproduct[i] > 0)
            sumPos = true;
        else
            sumNeg = true;
    }
    delete[] crossproduct;
    crossproduct = nullptr;

    if (sumPos && sumNeg)
        return false;
    else
        return true;
}

Polygon Polygon::operator+(const Point& rhs)
{
    const int count = this->m_c + 1;
    Point *newArray = new Point[count];
    for (int j = 0; j < m_c; j++)
        newArray[j] = this->m_a[j];
    newArray[count - 1] = rhs;

    return Polygon(newArray, count);
}

Polygon Polygon::operator+(const Polygon& rhs)
{
    const int size = this->m_c + rhs.m_c;
    Point *temp = new Point[size];
    for (int i = 0; i < this->m_c; i++)
        temp[i] = this->m_a[i];
    for (int j = this->m_c; j < size; j++)
        temp[j] = rhs.m_a[j-this->m_c];
    Polygon p(temp, size);
    return p;
}

std::ostream& operator<<(std::ostream& os, const Polygon& rhs)
{
	os << rhs.print();
    return os;
}

void Polygon::operator=(const Polygon &rhs)
{
	m_c = rhs.m_c;
	m_a = new Point[rhs.m_c];
	for (int k = 0; k < rhs.m_c; k++)
		m_a[k] = rhs.m_a[k];
}

std::string Polygon::print() const
{
	std::stringstream ss;
	for (int i = 0; i < m_c; i++)
		ss << "(" << m_a[i].getX() << "," << m_a[i].getY() << ") ";

	return ss.str();
}

BoundBox Polygon::getBoundingBox()
{
	double xMin = m_a[0].getX();
	double yMax = m_a[0].getY();
	double xMax = m_a[0].getX();
	double yMin = m_a[0].getY();
	
	for (int i = 0; i < m_c; i++)
	{
		if (xMax < m_a[i].getX())
			xMax = m_a[i].getX();
		if (xMin > m_a[i].getX())
			xMin = m_a[i].getX();
		if (yMax < m_a[i].getY())
			yMax = m_a[i].getY();
		if (yMin > m_a[i].getY())
			yMin = m_a[i].getY();
	}
	
	BoundBox bb;
	Point upperL(xMin, yMax);
	Point lowerR(xMax, yMin);
	bb.upperLeft = upperL;
	bb.lowerRight = lowerR;

	return bb;
}