#include "AlgorithmController.h"

AlgorithmController::AlgorithmController(Algorithm* algo)
{
    this->algo = algo;
}

AlgorithmController::~AlgorithmController()
{
    //delete algo;
}


void AlgorithmController::setNextStep()
{
    currentStep = algo->getNextStep();
}


void AlgorithmController::setPrevStep()
{
     currentStep = algo->getPrevStep();
}

Step* AlgorithmController::getCurrentStep() const
{
    return currentStep;
}
