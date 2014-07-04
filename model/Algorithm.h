#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "model/Step.h"

using namespace std;
/**
  * @brief The Algorithm class
  *
  * Abstrakte Basisklasse jedes Sortieralgorithmus. Standardisiert Basisfunktionen fuer die Bedienung.
  */
class Algorithm
{
public:

	/**
     * Konstruktor fuer voreingestellte Zahlenfolgen
     * @param startTuple vordefiniertes Zahlentupel
     */
	Algorithm(int* values, int numbOfValues);

	/**
     * Konstruktor fuer zufaellige Zahlenfolge
     * @param anzValues Anzahl zu sortierender Werte
     */
	Algorithm(int numbOfValues);

	/**
     * Destruktor
     */
    virtual ~Algorithm();

	/** 
     * Startet die Sortierung
     */
	void doSort();

	/** 
     * Gibt Pointer auf den naechsten Schritt aus der Sortierung zurueck
     * Gibt NULL zurueck, fall kein naechster Schritt existiert
     */
	Step* getNextStep();

	/** 
     * Gibt Pointer auf den vorherigen Schritt aus der Sortierung zurueck
     * Gibt NULL zurueck, fall kein vorheriger Schritt existiert
     */
	Step* getPrevStep();

	/**
     * Getter-Funktionen
     */
    int* getCurrentTuple(){ return currentTuple; }
    int* getStartTuple(){ return startTuple; }
    int getNumbOfCurrentStep(){ return numbOfCurrentStep; }
    int getNumbOfSteps(){ return numbOfSteps; }
    int getNumbOfValues(){ return numbOfValues; }

protected:
    /**
      * @brief sort
      *
      * Kernfunktion der Klasse, sortiert das startTuple und fuellt steps mit den einzelnen Schritten.
      * Muss in allen Unterklassen neu deklariert werden.
      */
    virtual void sort() = 0;

    int maxValue;
	bool isSorted;
	int* startTuple;
	int* currentTuple;
	vector<Step*> steps;
	int numbOfValues;
	int numbOfSteps;
	int numbOfCurrentStep;
};

