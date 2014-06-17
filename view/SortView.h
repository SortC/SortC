#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QMainWindow>
#include <QPushButton>
#include "ui_SortView.h"
#include "controller/Controller.h"

namespace Ui {
class SortView;
}

class SortView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortView(QWidget *parent = 0, int* startTuple = NULL , int numbOfValues = 0);

    ~SortView();

private slots:
    void on_btnPrevStep_clicked();
    void on_btnNextStep_clicked();

private:
    void handleStep();

    QPushButton **btns;
    Controller *controller;
    Ui::SortView *ui;
    int* startTuple;
    int numbOfValues;
};

#endif // SORTVIEW_H
