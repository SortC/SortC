#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include "controller/AlgorithmController.h"
#include "ui_BaseSortWidget.h"
#include "view/InfoView.h"

namespace Ui {
class BaseSortWidget;
}

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

    bool infoViewOpen;

//Envents des UI
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
     * @brief on_btnPlayPause_toggled
     *
     * Wird beim Klicken des bttPlayPause ausgeloest, startet/stopt den Wiederholungsinterval
     *
     * @param checked: Status des Buttons (vergleichbar mit Checkbox.checked)
     */
    void on_btnPlayPause_toggled(bool checked);

    /**
     * @brief on_intervalSpeedSlider_sliderMoved
     *
     * Wird beim bewegen des intervalSpeedSlider ausgeloest, setzt die neue Intervallzeit
     *
     * @param position: Position des Sliders
     */
    void on_intervalSpeedSlider_sliderMoved(int position);

    void on_pushButton_clicked();

protected:
    /**
     * @brief handleStep
     *
     * Basisfunktion zum Auswerten eines Schrittes (setzt Beschreibung, etc.)
     */
    virtual void handleStep();

    QTimer* timer;  /**< Timer, regelt die Autoplayfunktion, ruft on_btnNextStep_clicked() nach Ablauf auf */
    QWidget *parent;
    Ui::BaseSortWidget *ui;
    AlgorithmController* algoCtrl; /**< Pointer auf den Algorithmuskontroller */
    int* startTuple;
    int numbOfValues;
    int interval; /**< Zeit des Timerintervalls in ms */
    QString url;
};

#endif // BASESORTWIDGET_H
