#pragma once

#include "algorithm.h"
#include <queue>

/**
 * @brief The BucketSort class
 *
 * Konkrete BucketSort-Klasse
 * Sortiert ein Array mittels BucketSort. Erstell derzeit noch keine Schritte
 */
class BucketSort :
	public Algorithm
{
public:
    /**
     * @brief BucketSort
     *
     * Konstruktor fuer ein fertiges Array
     *
     * @param values : Zu Sortierendes Array
     * @param numbOfValues : Anzahl der Werte
     */
	BucketSort(int* values, int numbOfValues);

    /**
     * @brief BubbleSort
     *
     * Konstruktor fuer Zufallswerte. Erstellt Anhand der Werte-Anzahl ein zufaelliges Array.
     *
     * @param numbOfValues : Anzahl der Werte
     */
	BucketSort(int numbOfValues);

    /**
      * Dekonstruktor
      */
	~BucketSort(void);

    /**
     * @brief sort
     *
     * Konkrete Sortierfunktion des Bubblesort. Sortiert das Array, erstellt noch keine Schritte
     */
    void sort();

    /**
     * @brief getFilledBuckets
     *
     * gibt die fertig gefuellten Buckets zurueck
     *
     * @return
     */
    queue<int>* getFilledBuckets(){return filledBuckets;}
protected:
    /**
     * @brief hash
     *
     * liefert Nummer des Buckets fuer einen Wert
     *
     * @param n
     * @return
     */
    int hash(int n);

    /**
     * @brief doInsertionSortForBucket
     *
     * Sortiert einzelne Buckets mittels InsertionSort
     *
     * @param input
     * @param len
     */
	void doInsertionSortForBucket(int* input, int len);
	queue<int> *buckets;
	queue<int> *filledBuckets;
};

