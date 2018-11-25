#ifndef ONEPOINT_H
#define ONEPOINT_H
#include "Point.h"
#include "Shape.h"
#include <string>

class OnePoint : public Shape
{

public:
  OnePoint(Point q) : m_p1(q) {}
  OnePoint() : m_p1(0, 0) {}
  std::string getType();
  double getArea();
  double getCircumference();
  Point getPosition();

private:
  Point m_p1;
};

#endif // ONEPOINT_H