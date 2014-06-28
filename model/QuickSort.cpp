#include "QuickSort.h"


QuickSort::QuickSort(int* values, int numberOfValues) : Algorithm(values, numberOfValues)
{
}


QuickSort::QuickSort(int numberOfValues) : Algorithm(numberOfValues)
{
}

void QuickSort::sort(){
	int left = 0;
	int right = numbOfValues-1;

	if(left >= right)
		return; // Invalid index range

	vector<std::pair<int, int> > list;
	list.push_back(pair<int, int>(left, right));

	while(list.size() != 0)
	{
		left = list.back().first;
		right = list.back().second;
		list.pop_back();

        steps.push_back(new Step(left,right,Step::MARK,++numbOfSteps));
		int pivot = partition(currentTuple, left, right);   
        steps.push_back(new Step(pivot,0,Step::PIVOT,++numbOfSteps));

        //stringstream buffer;
        //buffer << "Pruefe ob Pivot   [" << pivot <<"] > "<< 1 ;
//        steps.push_back(new Step(pivot,1,Step::COMP, ++numbOfSteps/*, buffer.str()*/ ));
		if(pivot > 1)
			list.push_back(std::pair<int, int>(left, pivot - 1));

        //buffer << "Pruefe ob Pivot   [" << pivot + 1 <<"] > "<< 1 ;
  //      steps.push_back(new Step(pivot + 1, right ,Step::COMP, ++numbOfSteps/*, buffer.str()*/ ));
		if(pivot + 1 < right)
			list.push_back(std::pair<int, int>(pivot + 1, right));
	}
    steps.push_back(new Step(0,0,Step::END,++numbOfSteps));
}

int QuickSort::partition(int a[], int left, int right)
{
	int pivot = a[left];
	int pivotStelle = left;

	while (true)
	{

		while (a[left] < pivot){
			stringstream buffer;
            buffer << "Pruefe ob \tPivot[" << pivotStelle <<"]  < LZ[" << left << "]" ;
            steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));
			left++;
		}

		while (a[right] > pivot){
			stringstream buffer;
            buffer << "Pruefe ob \tPivot[" << pivotStelle <<"]  > RZ[" << right <<"]" ;
            steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));
			right--;
		}

        stringstream buffer;
        buffer << "Pruefe ob \tLZ   [" << left << "]  < RZ[" << right << "]" ;
        steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));

		if (left < right)
		{

            steps.push_back(new Step(left, right,Step::SWAP, ++numbOfSteps));
			int temp = a[right];
			a[right] = a[left];
			a[left] = temp;
			left++;

		}
		else 
		{
            //stringstream buffer;
           // buffer << "Setze Pivot auf\t      [" << right << "]" ;
            //steps.push_back(new Step(right, 0, Step::PIVOT, ++numbOfSteps, buffer.str() ));
			return right;
		}
	}
}
