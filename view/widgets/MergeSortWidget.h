#ifndef MERGESORTWIDGET_H
#define MERGESORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"

class MergeSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief MergeSortWidget
     *
     * Konstruktor fuer ein MergeSort-Sortierfenster
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit MergeSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum Auswerten eines Schrittes fuer MergeSort
     */
    void handleStep();

};

#endif // MERGESORTWIDGET_H