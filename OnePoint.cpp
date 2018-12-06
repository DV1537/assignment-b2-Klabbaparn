#include <cmath>
#include "Point.h"
#include "OnePoint.h"
#include <string>
#include <iostream>

std::string OnePoint::getType()
{
    std::string myShape = "Point";
    return myShape;
}

double OnePoint::getArea()
{
        double area = -1;
    return area;
}

double OnePoint::getCircumference()
{
    double OnePointCircum = 0;
    return OnePointCircum;
}

Point OnePoint::getPosition()
{
    double sumX, sumY;
    sumX = m_p1.getX(); 
    sumY = m_p1.getY();
    Point centerPosition(sumX, sumY);
    return centerPosition;
}

std::ostream& operator<<(std::ostream& os, const OnePoint& rhs)
{
    os << "(" << rhs.m_p1.getX() << "," << rhs.m_p1.getY() << ")"; 
    return os; 
}

void OnePoint::operator=(const OnePoint& rhs)
{
    m_p1 = rhs.m_p1;
}