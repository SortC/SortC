#include "InsertionSortWidget.h"

InsertionSortWidget::InsertionSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    displayValues = new SortValue*[numbOfValues];
    SortValue* newValue;

    for (int i = 0; i < numbOfValues; i++){
        newValue = new SortValue(0,startTuple[i]);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }

    this->url = QString("http://de.wikipedia.org/wiki/Insertionsort");

    ui->horLayoutSorting->update();
    handleStep();
}

void InsertionSortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}
