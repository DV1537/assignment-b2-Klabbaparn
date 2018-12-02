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
  ~Polygon() {delete[] m_a;}
  std::string getType();
  double getArea();
  double getCircumference();
  Point getPosition();
  bool isConvex();
  Polygon operator+(const Point &rhs);

private:
  Point* m_a = nullptr;
  int m_c = 0;
};

#endif // POLYGON_H