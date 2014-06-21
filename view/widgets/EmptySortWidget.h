#ifndef EMPTYSORTWIDGET_H
#define EMPTYSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
/**
 * @brief The EmptySortWidget class
 *
 * Erzeugt einen leeren SortTab, wird nur als Platzhalter verwendet
 */
class EmptySortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    /**
     * @brief EmptySortWidget
     *
     * Konstruktor fuer ein leeres Sortierfenster
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit EmptySortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    /**
     * @brief handleStep
     *
     * Konkrete Funktion zum auswerten eines Schrittes, hier nur als Dummy
     */
    void handleStep();

};

#endif // EMPTYSORTWIDGET_H