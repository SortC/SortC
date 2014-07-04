#pragma once

#include "algorithm.h"

/**
 * @brief The InsertionSort class
 *
 * Konkrete InsertionSort-Klasse
 * Sortiert ein Array mittels InsertionSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class InsertionSort :
	public Algorithm
{
public:
    /**
     * @brief InsertionSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	InsertionSort(int* values, int numbOfValues);

    /**
     * @brief InsertionSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	InsertionSort(int numbOfValues);

    /**
      * Dekonstruktor
      */
	~InsertionSort(void);

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des InsertionSort. Sortiert das Array und erstellt Schritte
     */
    void sort();
};

