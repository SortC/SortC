#ifndef MERGESORTWIDGET_H
#define MERGESORTWIDGET_H

#include <QResizeEvent>
#include "view/widgets/BaseSortWidget.h"
#include "view/widgets/SortValue.h"

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

    /**
      * Dekonstruktor
      */
    ~MergeSortWidget();

    /**
     * @brief resizeEvent
     *
     * wird bei einer Groessenaenderung aufgerufen, setzt Minimalgroesse der Layouts neu.
     *
     * @param event
     */
    void resizeEvent ( QResizeEvent * event );
signals:

public slots:
    /**
     * @brief on_btnReset_clicked
     *
     * wirb beim klicken des btnReset ausgeloest. Setzt UI-elemente auf ihren Ausgangswert zurueck.
     * ruft on_btnReset_clicked() der Oberklasse (BaseSortWidget) auf.
     */
    void on_btnReset_clicked();

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum Auswerten eines Schrittes fuer MergeSort
     */
    void handleStep();
    SortValue** displayValues;
    SortValue** helpArray;
};

#endif // MERGESORTWIDGET_H
