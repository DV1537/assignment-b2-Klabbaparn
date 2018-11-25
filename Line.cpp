#include <cmath>
#include "Point.h"
#include "Line.h"
#include <string>

std::string Line::getType()
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