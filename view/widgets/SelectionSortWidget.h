#ifndef SELECTIONSORTWIDGET_H
#define SELECTIONSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
#include "view/widgets/SortValue.h"

class SelectionSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief SelectionSortWidget
     *
     * Konstruktor fuer ein SelectionSort-Sortierfenster, erstellt Inhalt des Sortierbereichs
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit SelectionSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

    /**
      * Dekonstruktor
      */
    ~SelectionSortWidget();
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
     * Konkrete Funktion zum Auswerten eines Schrittes fuer SelectionSort
     */
    void handleStep();
    SortValue** displayValues;

};

#endif // SELECTIONSORTWIDGET_H
