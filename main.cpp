#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "Functions.h"
#include "Shape.h"
#include "Point.h" //Vital class. Almost everything runs through this
#include "Triangle.h"
#include <iomanip>
#include "Line.h"
#include "OnePoint.h" //This is the point-shape
#include "Polygon.h"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Wrong amount of arguments"; //fail-checking
        return 0;
    }

    int count = 0;
    std::string stringOfNumbers;
    std::ifstream f(argv[1]);
    if (!f.is_open())
    {
        std::cout << "File failed to open!" << std::endl; //fail-checking
        exit(EXIT_FAILURE);
    }
    while (f >> stringOfNumbers)
    {
        if (countOfChar(stringOfNumbers, '.') > 1 || //Check if string doesn't contain more than 1 dot.
            countOfChar(stringOfNumbers, '-') > 1 || //Check if string doesn't contain more than one subtraction
            countOfChar(stringOfNumbers, '+') > 1 || //Checks if string doesn't contain more than one addition
            !hasValidChars(stringOfNumbers))         //Checks that the strings only contains numbers
        {
            std::cout << "File is corrupt" << std::endl;
            return (EXIT_FAILURE);
        }
        count++;
    }
    if (count % 2 != 0)
    {
        std::cout << "File is missing a coordinate" << std::endl;
        return (EXIT_FAILURE);
    }
    count = count / 2;
    Point *arrayOfCoords = new Point[count]; //Allocate a dynamic memory array
    f.clear();
    f.seekg(0); //Rewind the file

    int j = 0;
    double x = 0;
    double y = 0;
    while (f >> x >> y)
    {
        Point p(x, y);
        arrayOfCoords[j] = p;
        j++;
    }
    f.close(); //Close file

    OnePoint myOnePoint(arrayOfCoords[0]);
    Line myLine(arrayOfCoords[0], arrayOfCoords[1]);
    Triangle myTriangle(arrayOfCoords[0], arrayOfCoords[1], arrayOfCoords[2]);
    Polygon myPolygon(arrayOfCoords, count);

    if (count > 3)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << "Shape is a " << myPolygon.getType() << std::endl;
        std::cout << "Area is " << myPolygon.getArea() << std::endl;
        std::cout << "Circumference is " << myPolygon.getCircumference() << std::endl;
        std::cout << "Centerposition is (" << myPolygon.getPosition().getX() << ", " << myPolygon.getPosition().getY() << ")" << std::endl;
        if(!myPolygon.isConvex())
        std::cout << "The polygon is concave" << std::endl;
        else
        std::cout << "The polygon is convex" << std::endl;
    }
    if (count == 3)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << "Shape is a " << myTriangle.getType() << std::endl;
        std::cout << "Area is " << myTriangle.getArea() << std::endl;
        std::cout << "Circumference is " << myTriangle.getCircumference() << std::endl;
        std::cout << "Centerposition is (" << myTriangle.getPosition().getX() << ", " << myTriangle.getPosition().getY() << ")" << std::endl;
    }
    if (count == 2)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << "Shape is a " << myLine.getType() << std::endl;
        std::cout << "Area is " << myLine.getArea() << std::endl;
        std::cout << "Circumference is " << myLine.getCircumference() << std::endl;
        std::cout << "Centerposition is (" << myLine.getPosition().getX() << ", " << myLine.getPosition().getY() << ")" << std::endl;
    }
    if (count == 1)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << "Shape is a " << myOnePoint.getType() << std::endl;
        std::cout << "Area is " << myOnePoint.getArea() << std::endl;
        std::cout << "Circumference is " << myOnePoint.getCircumference() << std::endl;
        std::cout << "Centerposition is (" << myOnePoint.getPosition().getX() << ", " << myOnePoint.getPosition().getY() << ")" << std::endl;
    }
    return 0;
}