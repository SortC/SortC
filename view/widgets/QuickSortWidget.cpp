#include "QuickSortWidget.h"

QuickSortWidget::QuickSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    handleStep();
}

void QuickSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
