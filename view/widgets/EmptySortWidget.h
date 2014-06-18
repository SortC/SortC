#ifndef EMPTYSORTWIDGET_H
#define EMPTYSORTWIDGET_H

#include "view/widgets/BaseSortWidget.h"

class EmptySortWidget : public BaseSortWidget
{
    Q_OBJECT
public:
    explicit EmptySortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);

signals:

public slots:

private:
    void handleStep();

};

#endif // EMPTYSORTWIDGET_H
