#include "SortView.h"
#include <QApplication>
#include "model/stdafx.h"
#include "model/BubbleSort.h"
#include "model/MergeSort.h"
#include "model/QuickSort.h"
#include "model/SelectionSort.h"
#include "model/InsertionSort.h"
#include "model/BucketSort.h"
#include "model/HeapSort.h"
#include "model/Step.h"
#include <iostream>
#include <ctime>
#include <typeinfo>
#include <iomanip>
#include <cstdlib>
//#include <random>


#define ANZWERTE 5
#define LINEWIDTH 40
const char FILLCHAR = '-';

using namespace std;



void printBuckets(queue<int> *buckets, int numbOfValues)
{
    cout << "print Buckets" << endl;
    cout << "| ";
    for ( int i = 0; i < numbOfValues; i++ )
    {
        if (buckets[i].size() == 0){
            cout << " | ";
        }
        if (buckets[i].size() == 1)
        {
            //cout << "A" << endl;
            cout << buckets[i].front() << " | ";
            buckets[i].pop();
        }
        if (buckets[i].size() > 1)
        {
            //cout << "B" << endl;
            while (!buckets[i].empty())
            {
                cout << buckets[i].front() << " ";
                buckets[i].pop();
            }
            cout << "| ";
        }
    }
}

/**
* Testet einen Algorithmus
* @param algo Algorithmus
* @param isBackwardSorted gibt an, ob die Zahlen umgekehrt sortiert sein sollen
*/
void testAlgorithm(Algorithm* algo) {
    cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl;
    cout << typeid(*algo).name() << endl << endl;

    clock_t begin = clock();

    algo->doSort();

    clock_t end = clock();

    cout << "Ausgangswerte: \t" ;
    int *startTuple = algo->getStartTuple();
    for (int i = 0; i < algo->getNumbOfValues(); i++)
    {
        cout << " | " << startTuple[i];
    }
    cout << " |" << endl;

    //BucketSort* buck = static_cast <BucketSort*> (algo);

    //printBuckets(buck->getFilledBuckets(), buck->getNumbOfValues());

    cout << "\nEndwerte: \t" ;
    int *endTupel = algo->getCurrentTuple();
    for (int i = 0; i < algo->getNumbOfValues(); i++)
    {
        cout << " | " << endTupel[i];
    }

    cout << " |" << endl << endl;

    double elapsed_secs = double(end - begin) ;
    cout <<"Passed time: "<< elapsed_secs << " milliseconds" << endl<< endl;

    // Ausgabe der Schritte
    Step* currStep = algo->getNextStep();
    cout <<left<< setfill(' ') <<setw(7) << "No." << setw(7)<< "Oper." << "Explanation" << endl;
    int counter[7];
    for(int i = 0; i < 7; i++){
        counter[i] = 0;
    }
    do{
        cout << currStep->toString();
        switch (currStep->getOperation())
        {
        case Step::SWAP:
            {
                counter[Step::SWAP]++;
                break;
            }
        case Step::COMP:
            {
                counter[Step::COMP]++;
                break;
            }
        case Step::MARK:
            {
                counter[Step::MARK]++;
                break;
            }
        case Step::PIVOT:
            {
                counter[Step::PIVOT]++;
                break;
            }
        case Step::CPY:
            {
                counter[Step::CPY]++;
                break;
            }
        case Step::R_CPY:
            {
                counter[Step::R_CPY]++;
                break;
            }
        case Step::MIN:
            {
                counter[Step::MIN]++;
                break;
            }
        default:
            break;
        }
        currStep = algo->getNextStep();
    }while(currStep != NULL);

    cout << "\nBenoetigte Schritte: " << algo->getNumbOfSteps()<<endl;
    cout << "Nach Typ: " << endl;
    cout << "MARK:\t" << counter[Step::MARK] << endl;
    cout << "COMP:\t" << counter[Step::COMP] << endl;
    cout << "SWAP:\t" << counter[Step::SWAP] << endl;
    cout << "PIVOT:\t" << counter[Step::PIVOT] << endl;
    cout << "CPY:\t" << counter[Step::CPY] << endl;
    cout << "R_CPY:\t" << counter[Step::R_CPY] << endl;
    cout << "MIN:\t" << counter[Step::MIN] << endl;
    cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl << endl<< endl;
    delete algo;
}

int main(int argc, char *argv[])
{
    cout << "Testreihe mit " << ANZWERTE << " Werten" << endl;
    cout << setw(LINEWIDTH) << setfill(FILLCHAR) << endl;

    // Test des BubbleSort
    //testAlgorithm(new BubbleSort(ANZWERTE));
    int zahlen[ANZWERTE];

    for (int i = 0 ; i<ANZWERTE;i++){
        zahlen[i] = ANZWERTE - i;
    }
    zahlen[3]= zahlen[1];
    const int width = 50;
    cout << setw(width) << setfill('#') << "" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Beginne Testreihe 1" << "#" << endl;
    cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Testfaelle:" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  1. Klasse: Algorithm" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    a. Konstruktor mit vord. Tupel" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    b. getNextStep() - Methode" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  2. Klasse: Erben von Algorithm" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    a. sort() - Methode" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    b. Sortierung doppelter Werte" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  3. Klasse: Step" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    a. toString() - Methode" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    b. Konstruktoren" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    c. Attribute" << "#" << endl;
    cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
    cout << setw(width) << setfill('#')<<"" << endl;
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new MergeSort(zahlen,ANZWERTE));
    testAlgorithm(new QuickSort(zahlen,ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new SelectionSort(zahlen,ANZWERTE));
    testAlgorithm(new InsertionSort(zahlen,ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new BubbleSort(zahlen,ANZWERTE));
    testAlgorithm(new BucketSort(zahlen,ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new HeapSort(zahlen, ANZWERTE));


    cout << setw(width) << setfill('#') << "" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Ende von Testreihe 1" << "#" << endl;
    cout << setw(width) << setfill('#') << "" << endl;
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    cout << setw(width) << setfill('#') << "" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Beginne Testreihe 2" << "#" << endl;
    cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Testfaelle:" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  1. Klasse: Algorithm" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#    a. Konstruktor mit Zufallswerten" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  2. Klasse: Erben von Algorithm (WIE ZUVOR)" << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  3. Klasse: Step (WIE ZUVOR)" << "#" << endl;
    cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
    cout << setw(width) << setfill('#')<<"" << endl;
        cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new MergeSort(ANZWERTE));
    testAlgorithm(new QuickSort(ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new SelectionSort(ANZWERTE));
    testAlgorithm(new InsertionSort(ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new BubbleSort(ANZWERTE));
    testAlgorithm(new BucketSort(ANZWERTE));
    cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;

    testAlgorithm(new HeapSort(ANZWERTE));

        cout << setw(width) << setfill('#') << "" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Ende von Testreihe 2" << "#" << endl;
    cout << setw(width) << setfill('#') << "" <<"\n" << endl;

    cout << setw(width) << setfill('#') << "" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  Alle Tests abgeschlossen" << "#" << endl;
    cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
    cout << left <<setfill(' ') << setw(width-1) <<"#  E N D E" << "#" << endl;
    cout << setw(width) << setfill('#') << "" << endl;

    QApplication a(argc, argv);
    SortView w;
    w.show();

    return a.exec();
}
