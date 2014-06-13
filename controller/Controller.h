#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "AlgorithmController.h"
#include "model/BubbleSort.h"
#include <cstdlib>
#include <time.h>

class Controller
{
public:
    Controller(int *startTuple, int numbOfValues);
    Controller(int numbOfValues);
    AlgorithmController *getBubbleSortCtrl() const;

private:
    int* startTuple;
    int numbOfValues;
    AlgorithmController* bubbleSortCtrl;
};

#endif // CONTROLLER_H
