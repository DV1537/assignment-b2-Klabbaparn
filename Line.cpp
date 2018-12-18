#include <cmath>
#include "Point.h"
#include "Line.h"
#include <string>
#include <iostream>
#include <sstream>

std::string Line::getType() const
{
    std::string myShape = "Line";
    return myShape;
}

double Line::getArea()
{
        double area = -1;
    return area;
}

double Line::getCircumference()
{
    double lineCircum = 0;
    lineCircum = sqrt(pow(m_p1.getX() - m_p2.getX(),2)+pow(m_p1.getY() - m_p2.getY(),2));
    return lineCircum;
}

Point Line::getPosition()
{
    double sumX, sumY;
    sumX = (m_p1.getX()+m_p2.getX())/2; 
    sumY = (m_p1.getY()+m_p2.getY())/2;
    Point centerPosition(sumX, sumY);
    return centerPosition;
}

std::ostream& operator<<(std::ostream& os, const Line& rhs)
{
    os << "(" << rhs.m_p1.getX() << "," << rhs.m_p1.getY() << ")" << " " << "(" << rhs.m_p2.getX() << "," << rhs.m_p2.getY() << ")"; 
    return os;  
}

void Line::operator=(const Line& rhs)
{
    m_p1 = rhs.m_p1;
    m_p2 = rhs.m_p2;
}

std::string Line::print() const
{
	std::string s = getType();
	std::stringstream ss;
	ss << s;
	ss << "my extra information about this line: " << m_p1.getX();

	return ss.str();
}



