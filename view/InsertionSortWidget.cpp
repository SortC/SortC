#include "InsertionSortWidget.h"

InsertionSortWidget::InsertionSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    handleStep();
}

void InsertionSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
