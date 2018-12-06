#include "Triangle.h"
#include <cmath>
#include "Point.h"
#include <string>
#include <iostream>

std::string Triangle::getType()
{
    std::string myShape = "Triangle";
    return myShape;
}

double Triangle::getArea()
{
        double area = 0;
        area = fabs((m_p1.getX() * (m_p2.getY() - m_p3.getY()) + m_p2.getX() * (m_p3.getY() - m_p1.getY()) + m_p3.getX() * (m_p1.getY() - m_p2.getY()) / 2));
        if (area == 0)
            area = -1;
        return area;
    return area;
}

double Triangle::getCircumference()
{
    double triangleCircum = 0;
    triangleCircum = sqrt(pow(m_p1.getX() - m_p2.getX(),2)+pow(m_p1.getY() - m_p2.getY(),2)+pow(m_p2.getX() - m_p3.getX(),2)+pow(m_p2.getY() - m_p3.getY(),2)+pow(m_p3.getX() - m_p1.getX(),2)+pow(m_p3.getY() - m_p1.getY(),2));
    return triangleCircum;
}

Point Triangle::getPosition()
{
    double sumX, sumY;
    sumX = (m_p1.getX()+m_p2.getX()+m_p3.getX())/3; 
    sumY = (m_p1.getY()+m_p2.getY()+m_p3.getY())/3;
    Point centerPosition(sumX, sumY);
    return centerPosition;
}

std::ostream& operator<<(std::ostream& os, const Triangle& rhs)
{
        os << "(" << rhs.m_p1.getX() << "," << rhs.m_p1.getY() << ")" << " " << "(" << rhs.m_p2.getX() << "," << rhs.m_p2.getY() << ")" << " " << "(" << rhs.m_p3.getX() << "," << rhs.m_p3.getY() << ")"; 
return os;
}

void Triangle::operator=(const Triangle& rhs)
{
    m_p1 = rhs.m_p1;
    m_p2 = rhs.m_p2;
    m_p3 = rhs.m_p3;
}