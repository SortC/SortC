#ifndef INSERTIONSORTWIDGET_H
#define INSERTIONSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"

class InsertionSortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit InsertionSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();

};

#endif // INSERTIONSORTWIDGET_H
