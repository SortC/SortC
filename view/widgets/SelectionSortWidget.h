#ifndef SELECTIONSORTWIDGET_H
#define SELECTIONSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"

class SelectionSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit SelectionSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();
    QPushButton** displayValues;

};

#endif // SELECTIONSORTWIDGET_H
