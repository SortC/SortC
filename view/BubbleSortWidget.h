#ifndef BUBBLESORTWIDGET_H
#define BUBBLESORTWIDGET_H

#include "view/BaseSortWidget.h"

class BubbleSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit BubbleSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

};

#endif // BUBBLESORTWIDGET_H
