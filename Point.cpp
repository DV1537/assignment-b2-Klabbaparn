#include <string>
#include <iostream>
#include "Point.h"

void Point::operator=(const Point& rhs)
{
    m_x = rhs.getX();
    m_y = rhs.getY();
}

std::ostream& operator<<(std::ostream& os, const Point& rhs)
{
    os << "(" << rhs.getX() << "," << rhs.getY() << ")"; 
    return os;  
}
