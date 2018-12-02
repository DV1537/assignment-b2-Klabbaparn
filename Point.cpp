#include <string>
#include <iostream>
#include "Point.h"

void Point::operator=(const Point &rhs)
{
    m_x = rhs.getX();
    m_y = rhs.getY();
}

