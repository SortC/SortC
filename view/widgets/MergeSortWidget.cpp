#include "MergeSortWidget.h"

MergeSortWidget::MergeSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    this->url = QString("http://de.wikipedia.org/wiki/Mergesort");

    handleStep();
}

void MergeSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}

void MergeSortWidget::on_btnReset_clicked(){
    BaseSortWidget::on_btnReset_clicked();

    handleStep();
}
