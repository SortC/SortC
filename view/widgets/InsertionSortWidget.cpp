#include "InsertionSortWidget.h"

InsertionSortWidget::InsertionSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    this->url = QString("http://de.wikipedia.org/wiki/Insertionsort");

    handleStep();
}

void InsertionSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
