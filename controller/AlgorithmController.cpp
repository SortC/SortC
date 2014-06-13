#include "AlgorithmController.h"

AlgorithmController::AlgorithmController(Algorithm* algo)
{
    this->algo = algo;
}

AlgorithmController::~AlgorithmController()
{
    delete algo;
}


void AlgorithmController::setNextStep()
{
    Step* buffer = algo->getNextStep();
    if(buffer){
        currentStep = buffer;
    }
}


void AlgorithmController::setPrevStep()
{
    Step* buffer = algo->getPrevStep();
    if(buffer){
        currentStep = buffer;
    }
}

Step* AlgorithmController::getCurrentStep() const
{
    return currentStep;
}
