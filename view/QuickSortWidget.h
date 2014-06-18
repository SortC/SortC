#ifndef QUICKSORTWIDGET_H
#define QUICKSORTWIDGET_H

#include "view/BaseSortWidget.h"

class QuickSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit QuickSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();


};

#endif // QUICKSORTWIDGET_H
