#pragma once

#include "algorithm.h"

/**
 * @brief The HeapSort class
 *
 * Konkrete HeapSort-Klasse
 * Sortiert ein Array mittels HeapSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class HeapSort :
	public Algorithm
{
public:
    /**
     * @brief HeapSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	HeapSort(int* values, int numbOfValues);

    /**
     * @brief HeapSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	HeapSort(int numbOfValues);

    /**
      * Destruktor
      */
	~HeapSort(void);

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des HeapSort. Sortiert das Array und erstellt Schritte
     */
    void sort();

private:
    /**< Hilfsfunktionen des HeapSort*/
	void shiftRight(int low, int high);
	void heapify(int low);
};

