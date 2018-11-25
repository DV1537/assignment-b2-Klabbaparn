#include "Polygon.h"
#include <cmath>
#include "Point.h"
#include <string>

std::string Polygon::getType()
{
    std::string myShape = "Polygon";
    return myShape;
}
double Polygon::getArea()
{
    int vertices = m_c / 2;
    double area = 0;
    int j = (vertices - 1);
    for (int i = 0; i < vertices; i++)
    {
        area += (m_a[j].getX() + m_a[i].getX()) * (m_a[j].getY() - m_a[i].getY());
        j = i;
    }
    if (area == 0)
        area = -1;
    else
        return area / 2;
    return area;
}

double Polygon::getCircumference()
{
    double PolyCircum = 0;
    int vertices = m_c / 2;
    int j = vertices - 1;
    for (int i = 0; i < vertices; i++)
    {
        PolyCircum += sqrt(pow(m_a[i].getX() - m_a[j].getX(), 2) + pow(m_a[i].getY() - m_a[j].getY(), 2));
        j = i;
    }
    return PolyCircum;
}

Point Polygon::getPosition() //I know this is off by a few, working on the correct one below
{
    double sumX = 0;
    double sumY = 0;
    int vertices = m_c / 2;
    for (int i = 0; i < vertices; i++)
    {
        sumX += (m_a[i].getX()) / vertices;
        sumY += (m_a[i].getY()) / vertices;
    }
    Point centerPosition(sumX, sumY);
    return centerPosition;
}


/*Point Polygon::getPosition()
{
    double sumX = 0;
    double sumY = 0;
    int vertices = m_c/2;
    for(int i = 0; i < m_c-1; ++i)
    {
        sumX += (m_a[i].getX()+m_a[i+1].getX()) * (m_a[i].getX()*m_a[i+1].getY()-m_a[i+1].getX() * m_a[i].getY());
    }
    sumX = sumX/(6 * Polygon::getArea());
    Point centerPosition(sumX, sumX);
    return centerPosition;
}*/