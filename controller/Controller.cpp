#include "Controller.h"
#include <iostream>


Controller::Controller(int *startTuple, int numbOfValues) {
    this->startTuple = new int[numbOfValues];
    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = startTuple[i];
    }

    this->numbOfValues = numbOfValues;
    this->bubbleSortCtrl = new AlgorithmController(new BubbleSort(startTuple, numbOfValues));
    this->selectionSortCtrl = new AlgorithmController(new SelectionSort(startTuple,numbOfValues));
    this->insertionSortCtrl = new AlgorithmController(new InsertionSort(startTuple,numbOfValues));
    this->mergeSortCtrl = new AlgorithmController(new MergeSort(startTuple,numbOfValues));
    this->quickSortCtrl = new AlgorithmController(new QuickSort(startTuple,numbOfValues));
    this->bucketSortCtrl = new AlgorithmController(new BucketSort(startTuple,numbOfValues));
    this->heapSortCtrl = new AlgorithmController(new HeapSort(startTuple,numbOfValues));
}

Controller::Controller(int numbOfValues) {
    this->numbOfValues = numbOfValues;
    srand(time(NULL));
    int maxValue = 100;
    this->startTuple = new int[numbOfValues];
    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = rand() % maxValue;
    }

    this->bubbleSortCtrl = new AlgorithmController(new BubbleSort(startTuple, numbOfValues));
    this->selectionSortCtrl = new AlgorithmController(new SelectionSort(startTuple,numbOfValues));
    this->insertionSortCtrl = new AlgorithmController(new InsertionSort(startTuple,numbOfValues));
    this->mergeSortCtrl = new AlgorithmController(new MergeSort(startTuple,numbOfValues));
    this->quickSortCtrl = new AlgorithmController(new QuickSort(startTuple,numbOfValues));
    this->bucketSortCtrl = new AlgorithmController(new BucketSort(startTuple,numbOfValues));
    this->heapSortCtrl = new AlgorithmController(new HeapSort(startTuple,numbOfValues));
}


