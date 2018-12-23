#include "Functions.h"


bool hasValidChars(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != '+' && s[i] != '-')
            return false;
    }
    return true;
}

int countOfChar(std::string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;
    return count;
}

void sort(DistPoly arr[], int low, int high)
{
	if (low < high)
	{
	int partitionIndex = partition(arr, low, high);

	sort(arr, low, partitionIndex - 1);
	sort(arr, partitionIndex + 1, high);
	}
}

int partition(DistPoly arr[], int low, int high)
{
	double pivot = arr[high].distance;

	int i = (low - 1);
		for(int j = low; j <= high - 1; j++)
		{
			if (arr[j].distance <= pivot)
			{
				i++;
				swap(&arr[i].distance, &arr[j].distance);
			}
		}
		swap(&arr[i + 1].distance, &arr[high].distance);
		return (i + 1);
}

void swap(double *a, double *b) {
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
};
