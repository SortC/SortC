#include "Controller.h"


Controller::Controller(int *startTuple, int numbOfValues) {
    this->startTuple = startTuple;
    this->numbOfValues = numbOfValues;

    this->bubbleSortCtrl = new AlgorithmController(new BubbleSort(startTuple, numbOfValues));
}

Controller::Controller(int numbOfValues) {
    this->numbOfValues = numbOfValues;
    // TODO: Zufallszahlen generieren

}
