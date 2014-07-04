#include "Algorithm.h"

Algorithm::Algorithm(int* values, int numbOfValues) {
	this->currentTuple = new int[numbOfValues];
	this->startTuple = new int[numbOfValues];
	maxValue = 0;
	for (int i = 0; i < numbOfValues; i++)
	{
		this->currentTuple[i] = values[i];
		this->startTuple[i] = values[i];
		if(maxValue < values[i])
			maxValue = values[i];
	}
	this->numbOfValues = numbOfValues;
	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;
	this->isSorted = false;
}

Algorithm::Algorithm(int numbOfValues)
{
	this->numbOfValues = numbOfValues;
	this->currentTuple = new int[numbOfValues];
	this->startTuple = new int[numbOfValues];
    srand(time(NULL));
	maxValue = 100;
	for (int i = 0; i < numbOfValues; i++)
	{
		this->currentTuple[i] = rand() % maxValue;
		this->startTuple[i] = this->currentTuple[i];
	}

    this->numbOfCurrentStep = -1;
    this->numbOfSteps = 0;
	this->isSorted = false;
}

Algorithm::~Algorithm(void)
{
	for(int i = 0; i < numbOfSteps; i++){
		delete(steps[i]);
	}
    delete currentTuple;
    delete startTuple;
}

void Algorithm::sort()
{
}

void Algorithm::doSort(){
	if(!isSorted){
		sort();
		isSorted= true;
	}
}

Step* Algorithm::getNextStep() {
    doSort();
    if (numbOfCurrentStep < numbOfSteps -1)
    {
        return steps[++numbOfCurrentStep];
	}
    else if(numbOfCurrentStep < 0){
        return steps[++numbOfCurrentStep];
    }
	else
	{
		return NULL;
	}
}

Step* Algorithm::getPrevStep() {
    doSort();
    if (numbOfCurrentStep > 0)
    {
        return steps[--numbOfCurrentStep];
	}
    else if(numbOfCurrentStep == 0) {
        return steps[numbOfCurrentStep];
    }
	else
	{
		return NULL;
	}
}
