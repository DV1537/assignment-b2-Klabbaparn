#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "Functions.h"
#include "Shape.h"
#include <sstream>
#include "Point.h" 
#include "Triangle.h"
#include <iomanip>
#include "Figure.h"
#include "Line.h"
#include "OnePoint.h" //This is the point-shape
#include "Polygon.h"

int main(int argc, const char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
    f.clear();
    f.seekg(0); //Rewind the file

	int coordCount = 0, j = 0, m = 0, lineCount = 0;
	double x = 0, y = 0;
	int shapeCount = 0;
	std::string line;
	while (std::getline(f, line))
		lineCount++;
	f.clear();
	f.seekg(0);
	Polygon *arrayOfShapes = new Polygon[lineCount];
	while (std::getline(f, line))
	{
		Point *arrayOfCoords = new Point[count];
		std::istringstream iss(line);
		{
			while (iss >> x >> y)
			{
				Point p(x, y);
				arrayOfCoords[j++] = p;
				coordCount++;
			}
			Polygon poly(arrayOfCoords, coordCount);
			arrayOfShapes[m++] = poly;
			shapeCount++;
			coordCount = 0;
			j = 0;
		}
	}

    f.close(); //Close file
	
	Figure Figgy;
	Figgy.addShape(&arrayOfShapes[0]); 
	Figgy.addShape(&arrayOfShapes[1]);
	Figgy.addShape(&arrayOfShapes[2]);
	Figgy.addShape(&arrayOfShapes[3]);
	Figgy.addShape(&arrayOfShapes[4]);
	Figgy.addShape(&arrayOfShapes[5]);
	Figgy.addShape(&arrayOfShapes[6]);
	Figgy.addShape(&arrayOfShapes[7]);
	
	int NrOfShapesToGet = 3;
	Figgy.getClosest(&arrayOfShapes[0], NrOfShapesToGet);
	
	delete[] arrayOfShapes;
	arrayOfShapes = nullptr;

    return 0;
}  