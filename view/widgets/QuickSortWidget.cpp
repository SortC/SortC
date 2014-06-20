#include "QuickSortWidget.h"

QuickSortWidget::QuickSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    this->url = QString("http://de.wikipedia.org/wiki/Quicksort");

    handleStep();
}

void QuickSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
