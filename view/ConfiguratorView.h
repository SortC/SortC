#ifndef CONFIGURATORVIEW_H
#define CONFIGURATORVIEW_H

#include <QMainWindow>
#include "SortView.h"
#include "OwnTupleView.h"
#include <qmessagebox.h>
#include <cstdlib>
#include <time.h>

const int maxRandomValue = 100;
const int maxNumbOfValues = 35;
const int maxNumbOfOpenSortViews = 2;

namespace Ui {
class ConfiguratorView;
}
/**
 * @brief The ConfiguratorView class
 *
 * Stellt UI zum Konfigurieren von SortViews zur Verfuegung
 */
class ConfiguratorView : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief ConfiguratorView
     *
     * Konstruktor
     *
     * @param parent: Elternobjekt, in der Regel 0
     */
    explicit ConfiguratorView(QWidget *parent = 0);
    ~ConfiguratorView();

    /**
     * @brief decrementCount
     *
     * Zur Begrenzung der offen SortViews, wird beim schliessen eines SortViews aufgerufen
     */
    void decrementCount();

public slots:
    /**
     * @brief newOwnTuple
     *
     * Wird vom OwnTupleView ausgeloest, falls neue Werte bestaetigt wurden
     */
    void newOwnTuple();

private slots:    
    /**
     * @brief on_startBtn_clicked
     *
     * Wird beim klicken der startBtn aufgerufen.
     * Startet, falls Maximale Anzahl der SortViews nicht erreicht ein SortView mit der aktuellen Konfiguration,
     * gibt eine Fehlermeldung falls nicht
     */
    void on_startBtn_clicked();

    /**
     * @brief on_btnOwnValues_clicked
     *
     * wird beim klicken des btnOwnValues aufgerufen. Startet OwnTupleView zum einlesen eigener Werte
     */
    void on_btnOwnValues_clicked();

    /**
     * @brief on_radioButtonRandomValues_toggled
     *
     * Wird beim klicken des radioButtonRandomValues aufgerufen.
     * Gibt entsprechende Optionen im UI fuer den Benutzer frei
     *
     * @param checked: Status des radioButtons
     */
    void on_radioButtonRandomValues_toggled(bool checked);


    /**
     * @brief on_radioButtonOwnValues_toggled
     *
     * Wird beim klicken des radioButtonOwnValues aufgerufen.
     * Gibt entsprechende Optionen im UI fuer den Benutzer frei
     *
     * @param checked: Status des radioButtons
     */
    void on_radioButtonOwnValues_toggled(bool checked);

    /**
     * @brief on_valueSlider_valueChanged
     *
     * Wird bei einer Wertaenderung des valueSlider aufgerufen
     * Setzt numbOfValues
     * Sperrt entsprechende UI-Elemente fuer den Benutzer
     *
     * @param value
     */
    void on_valueSlider_valueChanged(int value);

private:
    Ui::ConfiguratorView *ui;
    OwnTupleView *otv; /**< Pointer auf den aktuellen OwnTupleView*/
    SortView* sortViewtab[2]; /**< Pointer auf die SortViews*/
    static int count; /**< counter der aktiven SortViews*/
    int numberOfValues; /**< Anzahl der Werte*/
    int* ownTuple; /**< Array der eigenen Werte*/

    /**
     * Zulaessigkeit de eigenen Werte, verfaellt wenn sich die Anzahl
     * der Werte nach der Werteeingabe aendert
     */
    bool ownValuesValid;
};

#endif // CONFIGURATORVIEW_H
