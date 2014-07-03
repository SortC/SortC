#ifndef QUICKSORTWIDGET_H
#define QUICKSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
#include "view/widgets/SortValue.h"

class QuickSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief QuickSortWidget
     *
     * Konstruktor fuer ein QuickSort-Sortierfenster
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit QuickSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

    ~QuickSortWidget();
signals:

public slots:
    void on_btnReset_clicked();

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum Auswerten eines Schrittes fuer QuickSort
     */
    void handleStep();

    SortValue** displayValues;
};

#endif // QUICKSORTWIDGET_H
