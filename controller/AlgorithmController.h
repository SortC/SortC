#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "model/Algorithm.h"
/**
 * @brief The AlgorithmController class
 * Diese Klasse abstrahiert die Funktionalität eines von Algorithm
 * abgeleiteten Sortieralgorithmus. Damit trennt sie die Visualisierung
 * von der Logik.
 */
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
