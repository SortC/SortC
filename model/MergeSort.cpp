#include "MergeSort.h"


MergeSort::MergeSort(int* values, int numbOfValues) :Algorithm(values,numbOfValues)
{
	this->helperArray = new int[numbOfValues];
}

MergeSort::MergeSort(int numbOfValues):Algorithm(numbOfValues)
{
	this->helperArray = new int[numbOfValues];
}

MergeSort::~MergeSort(void)
{
    delete helperArray;
}

void MergeSort::sort(){
	merge_sort(currentTuple,helperArray,0,numbOfValues-1);
    steps.push_back(new Step(0,0,Step::END,++numbOfSteps));
}

void MergeSort::merge_sort(int *a, int*b, int low, int high)
{
	int pivot;
	if(low<high)
	{
		pivot=(low+high)/2;
		merge_sort(a,b,low,pivot);
		merge_sort(a,b,pivot+1,high);
		merge(a,b,low,pivot,high);
	}
}

void MergeSort::merge(int *a, int *b, int low, int pivot, int high)
{
    Step* newStep = new Step(low,high,Step::MARK, ++numbOfSteps);
	steps.push_back(newStep);
	int h,i,j,k;
	h=low;
	i=low;
	j=pivot+1;

	while((h<=pivot)&&(j<=high))
	{
        newStep = new Step(h,j,Step::COMP, ++numbOfSteps);
		steps.push_back(newStep);
		if(a[h]<=a[j])
		{
            newStep = new Step(h,i,Step::CPY, ++numbOfSteps);
			steps.push_back(newStep);
			b[i]=a[h];
			h++;
		}
		else
		{
            newStep = new Step(j,i,Step::CPY, ++numbOfSteps);
			steps.push_back(newStep);
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>pivot)
	{
		for(k=j; k<=high; k++)
		{
            newStep = new Step(k,i,Step::CPY, ++numbOfSteps);
			steps.push_back(newStep);
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h; k<=pivot; k++)
		{
            newStep = new Step(k,i,Step::CPY, ++numbOfSteps);
			steps.push_back(newStep);
			b[i]=a[k];
			i++;
		}
	}
	for(k=low; k<=high; k++)
	{
        newStep = new Step(k,k,Step::R_CPY, ++numbOfSteps);
		steps.push_back(newStep);
		a[k]=b[k];
	}
}
