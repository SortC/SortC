#ifndef OWNTUPLEVIEW_H
#define OWNTUPLEVIEW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>
#include <QCloseEvent>

#include "ui_OwnTupleView.h"

const int maxValue = 100;
const int minValue = 1;

namespace Ui {
class OwnTupleView;
}

/**
 * @brief The OwnTupleView class
 *
 * Stellt UI zum Eingeben eigener Werte zur Verfuegung
 */
class OwnTupleView : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief OwnTupleView
     *
     * Konstruktor
     *
     * @param parent: Pointer auf das Elternobjekt
     * @param ownTuple: Array mit bisher eingegebenen Werten
     * @param numbOfValues: Anzahl der einzulesenden Werte
     */
    explicit OwnTupleView(QWidget *parent = 0, int* ownTuple = NULL, int numbOfValues = 0);

    /**
      * Dekonstruktor
      */
    ~OwnTupleView();

    /**
     * @brief closeEvent
     *
     * wird beim schiessen des OwnTupleView aufgerufen
     * setzt das ElternUI wieder sichtbar
     *
     * @param event
     */
    void closeEvent(QCloseEvent *event);

signals:
    /**
     * @brief ownTupleUpdated
     *
     * Signal, wird getriggert wenn das Eingegebene Tupel geaendert wurde
     */
    void ownTupleUpdated();

private slots:
    /**
     * @brief on_btnFinish_clicked
     *
     * wird beim Klicken auf den btnFinish ausgeloesst, triggert ownTupleUpdated(), schliesst den OwnTupleView
     */
    void on_btnFinish_clicked();

private:
    Ui::OwnTupleView *ui;
    QWidget* parent;
    QSpinBox** valueBoxes; /**< Array der Spinboxes, je eine Spinbox pro Arraystelle*/
    QLabel** labels; /**< Labels zur Beschriftung der einzelnen Spinboxes*/
    int numbOfValues; /**< Anzahl der Werte*/
    int * ownTuple; /**< Array der Werte*/
};

#endif // OWNTUPLEVIEW_H
