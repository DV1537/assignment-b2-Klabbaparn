#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "Point.h"
#include "Functions.h"

class Shape
{
public:
  virtual std::string getType() = 0; 
  virtual double getArea() = 0;
  virtual double getCircumference() = 0;
  virtual Point getPosition() = 0;
  //virtual double distance(shape s)
  //virtual bool isConvex() = 0;
  virtual ~Shape() {}
        

};

#endif // SHAPE_H