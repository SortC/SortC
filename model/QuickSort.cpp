#include "QuickSort.h"


QuickSort::QuickSort(int* values, int numberOfValues) : Algorithm(values, numberOfValues)
{
}


QuickSort::QuickSort(int numberOfValues) : Algorithm(numberOfValues)
{
}

QuickSort::~QuickSort(){

}

void QuickSort::sort(){
         //System.Collections.Stack stack = new System.Collections.Stack();

    int pivot;
     std::stack<int> stack;
         int pivotIndex = 0;
         int leftIndex = pivotIndex + 1;
         int rightIndex = this->numbOfValues - 1;


         stack.push(pivotIndex);//Push always with left and right
         stack.push(rightIndex);

         int leftIndexOfSubSet, rightIndexOfSubset;

         while (stack.size() > 0)
         {


             rightIndexOfSubset = stack.top() ;
             stack.pop();//pop always with right and left

             leftIndexOfSubSet = stack.top() ;
             stack.pop();


             leftIndex = leftIndexOfSubSet + 1;

             pivotIndex = leftIndexOfSubSet;

             rightIndex = rightIndexOfSubset;

             //steps.push_back(new Step(leftIndex, 0,Step::LEFTINDEX,++numbOfSteps));
             steps.push_back(new Step(pivotIndex, 0 , Step::PIVOT, ++numbOfSteps));
             //steps.push_back(new Step(rightIndex, 0,Step::RIGHTINDEX,++numbOfSteps ));
            steps.push_back(new Step(leftIndex +1, rightIndex+1 , Step::MARK, ++numbOfSteps));
             pivot = this->currentTuple[pivotIndex];

             if (leftIndex > rightIndex)
                 continue;

             while (leftIndex < rightIndex)
             {

                 while ((leftIndex < rightIndex) && (this->currentTuple[leftIndex] <= pivot)){
                     stringstream buffer;
                     buffer << "Pruefe ob linker Zeiger [" << leftIndex <<"] <= rechter Zeiger ["<< rightIndex << "]" ;
                     steps.push_back(new Step(leftIndex, rightIndex,Step::COMP,++numbOfSteps, buffer.str() ));

                     leftIndex++;	//increment right to find the greater
                 }
             //element than the pivot

                 while ((leftIndex <= rightIndex) && (this->currentTuple[rightIndex] >= pivot))
                     rightIndex--;//decrement right to find the

                 //smaller element than the pivot
                 stringstream buffer;
                 buffer << "Pruefe ob rechter Zeiger [" << rightIndex <<"] >= linker Zeiger ["<< leftIndex << "]" ;
                 steps.push_back(new Step(rightIndex, leftIndex,Step::COMP,++numbOfSteps, buffer.str() ));
                 if (rightIndex >= leftIndex) {  //if right index is
                     //greater then only swap
                     //SwapElement(ref input, leftIndex, rightIndex);
                     steps.push_back(new Step(rightIndex, leftIndex,Step::SWAP,++numbOfSteps));
                     int temp1 = currentTuple[leftIndex];
                     currentTuple[leftIndex] = currentTuple[rightIndex];        // #
                     currentTuple[rightIndex] = temp1;
                 }
             }

             stringstream buffer2;
             buffer2 << "Pruefe ob Pivot [" << pivotIndex <<"] > rechter Zeiger ["<< rightIndex << "]" ;
             steps.push_back(new Step(pivotIndex, rightIndex,Step::COMP,++numbOfSteps, buffer2.str() ));
             if (pivotIndex <= rightIndex)
                 if( currentTuple[pivotIndex] > currentTuple[rightIndex]) {
                     steps.push_back(new Step(pivotIndex, rightIndex,Step::SWAP,++numbOfSteps));
                     int temp2 = this->currentTuple[pivotIndex];
                     this->currentTuple[pivotIndex] = currentTuple[rightIndex];
                     this->currentTuple[rightIndex] = temp2;
                 }

             if (leftIndexOfSubSet < rightIndex)
             {
                 stack.push(leftIndexOfSubSet);
                 stack.push(rightIndex - 1);
             }

             if (rightIndexOfSubset > rightIndex)
             {
                 stack.push(rightIndex + 1);
                 stack.push(rightIndexOfSubset);
             }
         }
          steps.push_back(new Step(pivotIndex, rightIndex,Step::END,++numbOfSteps));
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
            //steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));
			left++;
		}

		while (a[right] > pivot){
			stringstream buffer;
            buffer << "Pruefe ob \tPivot[" << pivotStelle <<"]  > RZ[" << right <<"]" ;
           // steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));
			right--;
		}

        stringstream buffer;
        buffer << "Pruefe ob \tLZ   [" << left << "]  < RZ[" << right << "]" ;
        //steps.push_back(new Step(pivotStelle, left,Step::COMP, ++numbOfSteps, buffer.str() ));

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
