#ifndef BUBBLESORTWIDGET_H
#define BUBBLESORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"
#include <QPushButton>

class BubbleSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit BubbleSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();
    QPushButton** displayValues;
};

#endif // BUBBLESORTWIDGET_H
