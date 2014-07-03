#ifndef BUBBLESORTWIDGET_H
#define BUBBLESORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
#include "view/widgets/SortValue.h"

class BubbleSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief BubbleSortWidget
     *
     * Konstruktor fuer ein BubbleSort-Sortierfenster, erstellt Inhalt des Sortierbereichs
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit BubbleSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

    /**
      * Dekonstruktor
      */
    ~BubbleSortWidget();
signals:

public slots:
    void on_btnReset_clicked();

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum Auswerten eines Schrittes fuer BubbleSort
     */
    void handleStep();

    /**
     * @brief displayValues
     *
     * Array der Anzeigewerte-UI-Objekte
     */
    SortValue** displayValues;
};

#endif // BUBBLESORTWIDGET_H
