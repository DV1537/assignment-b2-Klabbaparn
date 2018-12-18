#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include "Shape.h"
#include <string>

class Line : public Shape
{

public:
  Line(Point q, Point w) : m_p1(q), m_p2(w) {}
  Line() : m_p1(0, 0), m_p2(0, 0){}
  std::string getType() const;
  double getArea();
  double getCircumference();
  Point getPosition();
  std::string print() const;
  friend std::ostream& operator<<(std::ostream& os, const Line& rhs);
  void operator=(const Line& rhs);

private:
  Point m_p1;
  Point m_p2;
};

#endif // LINE_H