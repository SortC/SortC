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
    /**
     * @brief AlgorithmController
     *
     * Konstruktor.
     *
     * @param algo : Pointer auf einen konkreten Sortieralgorithmus
     */
    AlgorithmController(Algorithm* algo);

    /**
      * Dekonstruktor
      */
    ~AlgorithmController();

    /**
     * @brief setNextStep
     *
     * extrahiert den naechsten Schritt aus dem Algorithmus und setzt ihn als currentStep
     */
    void setNextStep();

    /**
     * @brief setPrevStep
     *
     * extrahiert den vorherigen Schritt aus dem Algorithmus und setzt ihn als currentStep
     */
    void setPrevStep();

    /**
     * @brief getCurrentStep
     *
     * Gibt Pointer auf den derzeitigen Schritt zurueck
     *
     * @return Step*
     */
    Step* getCurrentStep() const;

private:
    Algorithm* algo;
    Step* currentStep;
};

#endif // ALGORITHMCONTROLLER_H
