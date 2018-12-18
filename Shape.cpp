#include <cmath>
#include "Point.h"
#include "Shape.h"

double Shape::distance(Shape& s)
{
    double distance = abs(sqrt(pow(this->getPosition().getX() - s.getPosition().getX(), 2) + pow(this->getPosition().getY() - s.getPosition().getY(),2)));
    return distance;
}

bool Shape::isConvex()
{
	return true;
}