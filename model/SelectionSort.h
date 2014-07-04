#pragma once

#include "algorithm.h"

/**
 * @brief The SelectionSort class
 *
 * Konkrete SelectionSort-Klasse
 * Sortiert ein Array mittels SelectionSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class SelectionSort :
	public Algorithm
{
public:
    /**
     * @brief SelectionSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	SelectionSort(int* values, int numbOfValues);

    /**
     * @brief SelectionSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	SelectionSort(int numbOfValues);

    /**
      * Dekonstruktor
      */
	~SelectionSort(void);

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des SelectionSort. Sortiert das Array und erstellt Schritte
     */
    void sort();
};

