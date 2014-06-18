#include "SelectionSort.h"


SelectionSort::SelectionSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{
}

SelectionSort::SelectionSort(int numbOfValues) : Algorithm(numbOfValues) 
{
}


SelectionSort::~SelectionSort(void)
{
}

void SelectionSort::sort()
{
	int i, j, tmp, min;
	Step* newStep;

	for( i = 0; i < numbOfValues - 1; i++)
	{
        newStep = new Step(i, 0, Step::MIN, ++numbOfSteps);
		steps.push_back(newStep);
		min = i;

		for( j = i+1; j < numbOfValues; j++)
		{
            newStep = new Step(min,j, Step::COMP, ++numbOfSteps);
			steps.push_back(newStep);
			if( currentTuple[j] < currentTuple[min])
			{
                steps.push_back(new Step(j, 0, Step::MIN, ++numbOfSteps));
				min = j;
			}
		}
		if(i != min){
            newStep = new Step(i, min, Step::SWAP, ++numbOfSteps);
			steps.push_back(newStep);
			tmp = currentTuple[min];
			currentTuple[min] = currentTuple[i];
			currentTuple[i] = tmp;
		}
	}
    steps.push_back(new Step(0,0,Step::END,++numbOfSteps));
}
