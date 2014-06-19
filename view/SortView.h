#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QHBoxLayout>
#include "ui_SortView.h"
#include "controller/Controller.h"
#include "view/widgets/BubbleSortWidget.h"
#include "view/widgets/SelectionSortWidget.h"
#include "view/widgets/InsertionSortWidget.h"
#include "view/widgets/MergeSortWidget.h"
#include "view/widgets/QuickSortWidget.h"
#include <qmessagebox.h>
#include <QCloseEvent>

//toDo entfernen, wird nur als dummy benutzt
#include "view/widgets/EmptySortWidget.h"

namespace Ui {
class SortView;
}

class SortView : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief SortView
     *
     * Konstruktor des SortView-Fensters
     *
     * @param parent: Elternobjekt, wenn 0 wird ein neues Fenster erstellt
     * @param startTuple: Array von Startwerten
     * @param numbOfValues: Anzahl der Startwerte
     */
    explicit SortView(QWidget *parent = 0, int* startTuple = NULL , int numbOfValues = 0);

    /**
      * Dekonstrukror
      */
    ~SortView();

    /**
     * @brief closeEvent
     *
     *
     *
     * @param event
     */
    void closeEvent(QCloseEvent *event);
private:
    /**
     * @brief addTabs
     *
     * Erstellt Tabs und fuegt sie in den Tabview ein
     */
    void addTabs();

    Controller *controller; /**< Pointer auf den allgemeinen Controller */
    Ui::SortView *ui;       /**< Pointer auf die SortUI */
    int* startTuple;
    int numbOfValues;
};

#endif // SORTVIEW_H
