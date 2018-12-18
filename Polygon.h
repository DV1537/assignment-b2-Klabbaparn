#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Shape.h"
#include <string>

class Polygon : public Shape
{
public:
	Polygon(Point q[], int count) : m_a(q), m_c(count) {}
  Polygon() : m_a(nullptr), m_c(0) {}
  ~Polygon() { delete[] m_a;}
  const Point getArray() const { return *m_a; }
  const int getCount() const { return m_c; }
  std::string getType() const;
  double getArea();
  double getCircumference();
  Point getPosition();
  bool isConvex();
  BoundBox getBoundingBox();
  std::string print() const;
  Polygon::Polygon(const Polygon &obj); //Copy-constructor
  Polygon operator+(const Point &rhs); //Adds one coordinate to the polygon
  Polygon operator+(const Polygon &rhs); //Adds two shapes toghter
  void operator=(const Polygon& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Polygon& rhs);

private:
  Point* m_a = nullptr;
  int m_c = 0;
};

#endif // POLYGON_H