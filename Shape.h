#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "Point.h"
#include "Functions.h"

struct BoundBox 
{
	Point upperLeft;
	Point lowerRight;
};

class Shape
{
public:
  Shape() {}
  virtual ~Shape() {}
  virtual std::string getType() const = 0;
  virtual double getArea() = 0;
  virtual double getCircumference() = 0;
  virtual Point getPosition() = 0;
  virtual std::string print() const = 0;
  double distance(Shape& s);
  bool isConvex();

private:
	Shape(const Shape& rhs);
};

#endif // SHAPE_H