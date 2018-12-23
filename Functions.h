#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include "Shape.h"
#include "Figure.h"

struct DistPoly 
{
	double distance;
	Polygon* ptr;
};

bool hasValidChars(std::string s);
int countOfChar(std::string s, char c);
void sort(DistPoly arr[], int low, int high);
int partition(DistPoly arr[], int low, int high);
void swap(double *a, double *b);
#endif // !FUNCTIONS_H