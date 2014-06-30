#include "BubbleSort.h"

BubbleSort::BubbleSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{

}

BubbleSort::BubbleSort(int numbOfValues) : Algorithm(numbOfValues) 
{

}


BubbleSort::~BubbleSort(void)
{

}

void BubbleSort::sort()
{ 
	int tmp = 0;
	Step* newStep;
	for (int i = 0; i < numbOfValues - 1; ++i)
	{
		for (int j = 0; j < numbOfValues - i - 1; ++j)
		{
            newStep = new Step(j,j+1, Step::COMP, ++numbOfSteps);
			steps.push_back(newStep);
			if (currentTuple[j] > currentTuple[j + 1])
			{
                newStep = new Step(j,j+1, Step::SWAP, ++numbOfSteps);
				steps.push_back(newStep);
				tmp = currentTuple[j];
				currentTuple[j] = currentTuple[j + 1];
				currentTuple[j + 1] = tmp;
			}
		}
    }

    steps.push_back(new Step(0,0,Step::END,++numbOfSteps));
}
