#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>

class Point
{
  public:
    Point(double x, double y) : m_x(x), m_y(y) {}
    Point() : m_x(0), m_y(0) {}
    double getX() const { return m_x; }
    double getY() const { return m_y; }


  private:
    double m_x;
    double m_y;
    
};

#endif // POINT_H

