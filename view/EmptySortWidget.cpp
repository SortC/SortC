#include "EmptySortWidget.h"

EmptySortWidget::EmptySortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    handleStep();
}

void EmptySortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
