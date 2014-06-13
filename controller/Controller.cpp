#include "Controller.h"


Controller::Controller(int *startTuple, int numbOfValues) {
    this->startTuple = startTuple;
    this->numbOfValues = numbOfValues;

    this->bubbleSortCtrl = new AlgorithmController(new BubbleSort(startTuple, numbOfValues));
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
}
