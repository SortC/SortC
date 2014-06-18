#include "MergeSortWidget.h"

MergeSortWidget::MergeSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    handleStep();
}

void MergeSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
