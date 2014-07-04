#pragma once

#include "algorithm.h"
#include <stack>

/**
 * @brief The QuickSort class
 *
 * Konkrete QuickSort-Klasse
 * Sortiert ein Array mittels QuickSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class QuickSort :
	public Algorithm
{
public:
    /**
     * @brief QuickSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	QuickSort(int* values, int numberOfValues);

    /**
     * @brief QuickSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	QuickSort(int numberOfValues);

    /**
      * Dekonstruktor
      */
    ~QuickSort();

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des QuickSort. Sortiert das Array und erstellt Schritte
     */
    void sort();

private:
	/**
     * Hilfsfunktion
	 * erzeugt eine Teilliste
	 */
	int partition(int a[], int left, int right);
};

