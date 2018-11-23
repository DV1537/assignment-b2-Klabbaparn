#include "Triangle.h"
#include <cmath>
#include "Point.h"

double Triangle::getArea()
{
        double area = 0;
        area = abs((m_p1.getX() * (m_p2.getY() - m_p3.getY()) + m_p2.getX() * (m_p3.getY() - m_p1.getY()) + m_p3.getX() * (m_p1.getY() - m_p2.getY()) / 2));
        if (area == 0)
            area = -1;
        return area;
    return area;
}

double Triangle::getCircumreference()
{
    double triangleCircum = 0;
    triangleCircum = sqrt(pow(m_p1.getX() - m_p2.getX(),2)+pow(m_p1.getY() - m_p2.getY(),2)+pow(m_p2.getX() - m_p3.getX(),2)+pow(m_p2.getY() - m_p3.getY(),2)+pow(m_p3.getX() - m_p1.getX(),2)+pow(m_p3.getY() - m_p1.getY(),2));
    return triangleCircum;
}

Point Triangle::position()
{
    double sumX, sumY;
    sumX = (m_p1.getX()+m_p2.getX()+m_p3.getX())/3; 
    sumY = (m_p1.getY()+m_p2.getY()+m_p3.getY())/3;
    Point centerPosition(sumX, sumY);
    return centerPosition;
}