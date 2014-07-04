#pragma once

#include "algorithm.h"

/**
 * @brief The MergeSort class
 *
 * Konkrete MergeSort-Klasse
 * Sortiert ein Array mittels MergeSort und dokumentiert das Vorgehen in einzelnen Schritten
 */
class MergeSort :
	public Algorithm
{
public:
    /**
     * @brief MergeSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	MergeSort(int* values, int numbOfValues);

    /**
     * @brief MergeSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	MergeSort(int numbOfValues);

    /**
      * Dekonstruktor
      */
	~MergeSort();

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des MergeSort. Sortiert das Array und erstellt Schritte
     */
	void sort();
protected:
    /**< Hilfsfunktionen des MergeSort*/
	void merge(int *a, int *b, int low, int pivot, int high);
	void merge_sort(int *a, int*b, int low, int high);
	int* helperArray;
};

