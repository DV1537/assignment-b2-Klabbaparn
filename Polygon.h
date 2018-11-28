#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Shape.h"
#include <string>

class Polygon : public Shape
{
public:
  Polygon(Point q[], int count) : m_a(q), m_c(count) {}
  Polygon() : m_a(0), m_c(0) {}
  std::string getType();
  double getArea();
  double getCircumference();
  Point getPosition();
  bool isConvex();

private:
  Point* m_a;
  int m_c;
};

#endif // POLYGON_H