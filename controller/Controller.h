#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "AlgorithmController.h"
#include "model/BubbleSort.h"
#include "model/SelectionSort.h"
#include "model/InsertionSort.h"
#include "model/MergeSort.h"
#include "model/QuickSort.h"
#include "model/HeapSort.h"
#include "model/BucketSort.h"
#include <cstdlib>
#include <time.h>

class Controller
{
public:
    Controller(int *startTuple, int numbOfValues);
    Controller(int numbOfValues);

    AlgorithmController* getBubbleSortCtrl() const {return bubbleSortCtrl;}
    AlgorithmController* getSelectionSortCtrl() const{return selectionSortCtrl;}
    AlgorithmController* getInsertionSortCtrl() const{return insertionSortCtrl;}
    AlgorithmController* getMergeSortCtrl() const{return mergeSortCtrl;}
    AlgorithmController* getQuickSortCtrl() const{return quickSortCtrl;}
    AlgorithmController* getHeapSortCtrl() const{return heapSortCtrl;}
    AlgorithmController* getBucketSortCtrl() const{return bucketSortCtrl;}

private:
    int* startTuple;
    int numbOfValues;
    AlgorithmController* bubbleSortCtrl;
    AlgorithmController* selectionSortCtrl;
    AlgorithmController* insertionSortCtrl;
    AlgorithmController* mergeSortCtrl;
    AlgorithmController* quickSortCtrl;
    AlgorithmController* heapSortCtrl;
    AlgorithmController* bucketSortCtrl;
};

#endif // CONTROLLER_H
