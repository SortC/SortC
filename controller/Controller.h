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

    AlgorithmController* bubbleSortCtrl;


private:
    int* startTuple;
    int numbOfValues;


};

#endif // CONTROLLER_H
