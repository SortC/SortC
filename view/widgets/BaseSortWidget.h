#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <QThread>
#include <QDesktopServices>
#include <QUrl>
#include "controller/AlgorithmController.h"
#include "ui_BaseSortWidget.h"

namespace Ui {
class BaseSortWidget;
}
/**
 * @brief The BaseSortWidget class
 *
 * Basisklasse fuer alle SortWidgets, regelt die fuer alle SortWidgets identischen ButtonEvents.
 * Implementiert den statischen Teil der GUI
 */
class BaseSortWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief BaseSortWidget
     *
     * Konstruktor fuer die Basis des Sortierfensters
     *
     * @param parent: Elternobjekt in der UI-Hierarchie
     * @param algoCtrl: Pointer auf dem diesem Fenster zugewiesenen Controller
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit BaseSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

    /**
      * Dekonstruktor
      */
    ~BaseSortWidget();

public slots:
    /**
     * @brief on_btnPlayPause_toggled
     *
     * Wird beim Klicken des btnPlayPause ausgeloest, startet/stopt den Wiederholungsinterval
     *
     * @param checked: Status des Buttons (vergleichbar mit Checkbox.checked)
     */
    void on_btnPlayPause_toggled(bool checked);

protected slots:
    /**
     * @brief on_btnReset_clicked
     *
     * Wird beim Klicken des btnReset ausgeloest. Setzt den aktuellen Schritt auf den Anfang.
     * Muss von den Unterklassen reimplementiert werden, da BaseSortWidget keinen Zugriff auf
     * den dynamischen Teil der GUI der Unterklassen hat
     */
    virtual void on_btnReset_clicked();

private slots:
    /**
     * @brief on_btnPrevStep_clicked
     *
     * Event, wird ausgeloest beim Klicken des btnPrevStep
     */
    void on_btnPrevStep_clicked();

    /**
     * @brief on_btnNextStep_clicked
     *
     * Event, wird ausgeloest beim Klicken des btnNextStep
     */
    void on_btnNextStep_clicked();

    /**
     * @brief on_intervalSpeedSlider_sliderMoved
     *
     * Wird beim bewegen des intervalSpeedSlider ausgeloest, setzt die neue Intervallzeit
     *
     * @param position: Position des Sliders
     */
    void on_intervalSpeedSlider_sliderMoved(int position);

    /**
     * @brief on_infoButton_clicked
     *
     * Wird beim Klicken des infoButton ausgeloest. Oeffnet die URL der jeweiligen
     * Unterklasse im defaultBrowser des Betriebssystems
     */
    void on_infoButton_clicked();

protected:
    /**
     * @brief handleStep
     *
     * Basisfunktion zum Auswerten eines Schrittes (setzt im BaseSortWidget lediglich
     * Schrittnummer und Beschreibung. Wird in den Unterklassen erweitert)
     */
    virtual void handleStep();

    QWidget *parent;
    Ui::BaseSortWidget *ui;
    QTimer* timer;  /**< Timer, regelt die Autoplayfunktion, ruft on_btnNextStep_clicked() nach Ablauf auf */
    AlgorithmController* algoCtrl; /**< Pointer auf den Algorithmuskontroller */

    /**< Anfangstupel und Anzahl der Werte*/
    int* startTuple;
    int numbOfValues;    

    int interval; /**< Zeit des Timerintervalls in ms */

    /**
     * Zielurl zu zusatzinfos zum jeweiligen Sortierverfahren, wird in den Unterklassen
     * fuer das jeweilige Verfahren neu gesetzt
     */
    QString url;

    /**
     * Zur korrekten Interpretation der Schritte im zusammenhang mit der Ablaufrichtung
     * Wird benoetigt, da sich das vorgehen manscher Schritte in abhaengigkeit der
     * Ablaufrichtung aendert (z.B. CPY und R_CPY)
     */
    bool directionForward;
};

#endif // BASESORTWIDGET_H
