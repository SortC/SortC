#include "QuickSortWidget.h"

QuickSortWidget::QuickSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    displayValues = new SortValue*[numbOfValues];
    SortValue* newValue;
    int max = 0;
    for (int i = 0; i < numbOfValues; i++){
        if(max < startTuple[i])
            max = startTuple[i];
    }
    for (int i = 0; i < numbOfValues; i++){
        newValue = new SortValue(this, startTuple[i], max);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }

    this->url = QString("http://de.wikipedia.org/wiki/Quicksort");

    handleStep();
}

void QuickSortWidget::handleStep()
{
    BaseSortWidget::handleStep();

    for(int i = 0; i < numbOfValues; i++) {
        displayValues[i]->setAction(SortValue::NONE);
    }

    int val1, val2, buffer;

    val1 = algoCtrl->getCurrentStep()->getFirstValue();
    val2 = algoCtrl->getCurrentStep()->getSecondValue();

    switch (algoCtrl->getCurrentStep()->getOperation()) {
    case Step::COMP:
        displayValues[val1]->setAction(SortValue::COMP);
        displayValues[val2]->setAction(SortValue::COMP);
        break;
    case Step::SWAP:
        displayValues[val1]->setAction(SortValue::SWAP);
        displayValues[val2]->setAction(SortValue::SWAP);
        buffer = displayValues[val1]->getValue();
        displayValues[val1]->setValue(displayValues[val2]->getValue());
        displayValues[val2]->setValue(buffer);
        break;
    case Step::END:
        ui->btnPlayPause->setChecked(false);
        ui->btnNextStep->setEnabled(false);
        ui->btnPlayPause->setEnabled(false);
        break;
    case Step::MARK:
        for(int i = val1; i <= val2; i++){
            displayValues[i]->setAction(SortValue::MARK);
        }
        break;
    case Step::PIVOT:
        displayValues[val1]->setAction(SortValue::PIVOT);
    default:
        break;
    }
}
