#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QString>
#include "ui_SortView.h"
#include "controller/Controller.h"
#include "view/widgets/BubbleSortWidget.h"
#include "view/widgets/SelectionSortWidget.h"
#include "view/widgets/InsertionSortWidget.h"
#include "view/widgets/MergeSortWidget.h"
#include "view/widgets/QuickSortWidget.h"

//Wird als Platzhalter fuer noch nicht implementierte SortWidgets benutzt
#include "view/widgets/EmptySortWidget.h"

namespace Ui {
class SortView;
}

/**
 * @brief The SortView class
 *
 * Basis des Sortierfensters. Liefert ein Fenster mit einem leeren Tabview.
 * In diesen werden dann die einzelnen SortWidgets eingefuegt.
 */
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
     * Wird beim Schliessen des SortView aufgerufen, reduziert den SortViewCounter des ConfiguratorViews
     *
     * @param event
     */
    void closeEvent(QCloseEvent *event);
private slots:

    /**
     * @brief on_tabWidget_currentChanged
     *
     * wird beim wechseln des Tabs aufgerufen, zum stoppen des autoplays
     */
    void on_tabWidget_currentChanged();

private:
    /**
     * @brief createTabs
     *
     * Erstellt Tabsobjekte (Konkrete Kindobjekte der Klasse BaseSortWidget)
     */
    void createTabs();

    /**
     * @brief addTabs
     *
     * Fuegt erstellte Tabsobjekte in den Tabview ein
     */
    void addTabs();

    Controller *controller; /**< Pointer auf den allgemeinen Controller */
    Ui::SortView *ui;       /**< Pointer auf die SortUI */

    /**< Pointer auf die einzelnen SortWidgets/Tabs */
    BubbleSortWidget* bsWidget;
    InsertionSortWidget* isWidget;
    SelectionSortWidget* ssWidget;
    QuickSortWidget* qsWidget;
    MergeSortWidget* msWidget;
    EmptySortWidget* hsWidget;
    EmptySortWidget* bucksWidget;

    /**< Anfangstupel und Anzahl der Werte*/
    int* startTuple;
    int numbOfValues;
};

#endif // SORTVIEW_H
