#ifndef MERGESORTWIDGET_H
#define MERGESORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"

class MergeSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit MergeSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();

};

#endif // MERGESORTWIDGET_H
