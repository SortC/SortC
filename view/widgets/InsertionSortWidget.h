#ifndef INSERTIONSORTWIDGET_H
#define INSERTIONSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
#include "view/widgets/SortValue.h"

class InsertionSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief InsertionSortWidget
     *
     * Konstruktor fuer ein InsertionSort-Sortierfenster
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit InsertionSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

    /**
      * Dekonstruktor
      */
    ~InsertionSortWidget();
signals:

public slots:
    void on_btnReset_clicked();

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum Auswerten eines Schrittes fuer InsertionSort
     */
    void handleStep();
    SortValue** displayValues;
};

#endif // INSERTIONSORTWIDGET_H
