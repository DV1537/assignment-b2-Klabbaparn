#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>

class Point 
{
  public:
    Point(double x, double y) : m_x(x), m_y(y) {}
    Point() : m_x(0), m_y(0) {}
    const double getX() const { return m_x; }
    const double getY() const { return m_y; }
    void operator=(const Point& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Point& rhs);

  private:
    double m_x;
    double m_y; 
};

#endif // POINT_H

