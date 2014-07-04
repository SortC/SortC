#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "AlgorithmController.h"
#include "model/BubbleSort.h"
#include "model/SelectionSort.h"
#include "model/InsertionSort.h"
#include "model/MergeSort.h"
#include "model/QuickSort.h"
#include "model/HeapSort.h"
#include "model/BucketSort.h"
#include <cstdlib>

/**
 * @brief The Controller class
 * Diese Klasse stellt alle Sortierverfahren zur Verfügung. Dabei ist sie lediglich
 * ein Container für mehrere AlgorithmController Objekte. Durch die Container-Funktion
 * kann von außen über jedes registrierte Sortierverfahren verfügt werden ohne einzelne
 * Controller-Klassen instanziieren zu müssen
 */
class Controller
{
public:
    /**
     * @brief Controller Konstruktor analog zu Algorithm für vordefiniertes Zahlentupel
     * @param startTuple   vordefiniertes Zahlentupel
     * @param numbOfValues Anzahl der Werte
     */
    Controller(int *startTuple, int numbOfValues);

    /**
     * @brief Controller Konstruktor analog zu Algorithm für zufälliges Zahlentupel
     * @param numbOfValues Anzahl der Werte
     */
    Controller(int numbOfValues);

    /**
      * Dekonstruktor
      */
    ~Controller();

    /**
     * @brief get*SortCtrl
     * Getter-Methoden der einzelnen AlgorithmController
     */
    AlgorithmController* getBubbleSortCtrl() const {return bubbleSortCtrl;}
    AlgorithmController* getSelectionSortCtrl() const{return selectionSortCtrl;}
    AlgorithmController* getInsertionSortCtrl() const{return insertionSortCtrl;}
    AlgorithmController* getMergeSortCtrl() const{return mergeSortCtrl;}
    AlgorithmController* getQuickSortCtrl() const{return quickSortCtrl;}
    AlgorithmController* getHeapSortCtrl() const{return heapSortCtrl;}
    AlgorithmController* getBucketSortCtrl() const{return bucketSortCtrl;}

private:
    int* startTuple;
    int numbOfValues;
    AlgorithmController* bubbleSortCtrl;
    AlgorithmController* selectionSortCtrl;
    AlgorithmController* insertionSortCtrl;
    AlgorithmController* mergeSortCtrl;
    AlgorithmController* quickSortCtrl;
    AlgorithmController* heapSortCtrl;
    AlgorithmController* bucketSortCtrl;
};

#endif // CONTROLLER_H
