#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H
#include "model/Algorithm.h"
class AlgorithmController
{
public:
    AlgorithmController(Algorithm* algo);
    ~AlgorithmController();

    void setNextStep();
    void setPrevStep();

    Step* getCurrentStep() const;

private:
    Algorithm* algo;
    Step* currentStep;
};

#endif // ALGORITHMCONTROLLER_H
