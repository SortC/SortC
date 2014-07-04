#pragma once
#include "algorithm.h"

/**
 * @brief The BubbleSort class
 *
 * Konkrete BubbleSort-Klasse
 * Sortiert ein Array mittels BubbleSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class BubbleSort :
	public Algorithm
{
public:
    /**
     * @brief BubbleSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	BubbleSort(int* values, int numbOfValues);

    /**
     * @brief BubbleSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	BubbleSort(int numbOfValues);

    /**
      * Dekonstruktor
      */
    ~BubbleSort();

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des Bubblesort. Sortiert das Array und erstellt Schritte
     */
    void sort();
};
