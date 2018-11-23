#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "Point.h"
#include "Functions.h"

class Shape
{
public:
  std::string getType();
  virtual double getArea() = 0;
  virtual double getCircumreference() = 0;
  Point position();
        /*bool isConvex();*/
};

#endif // SHAPE_H