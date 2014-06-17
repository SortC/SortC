#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QHBoxLayout>
#include "ui_SortView.h"
#include "controller/Controller.h"
#include "view/BaseSortWidget.h"

namespace Ui {
class SortView;
}

class SortView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortView(QWidget *parent = 0, int* startTuple = NULL , int numbOfValues = 0);

    ~SortView();

private:
    //void handleStep();
    void addTabs();

    Controller *controller;
    Ui::SortView *ui;
    int* startTuple;
    int numbOfValues;
};

#endif // SORTVIEW_H
