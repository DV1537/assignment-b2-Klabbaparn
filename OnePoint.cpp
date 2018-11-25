#include <cmath>
#include "Point.h"
#include "OnePoint.h"
#include <string>

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