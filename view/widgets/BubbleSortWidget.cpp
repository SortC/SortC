#include "BubbleSortWidget.h"

BubbleSortWidget::BubbleSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    displayValues = new SortValue*[numbOfValues];
    SortValue* newValue;

    for (int i = 0; i < numbOfValues; i++){
        newValue = new SortValue(this, startTuple[i]);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }

    this->url = QString("http://de.wikipedia.org/wiki/Bubblesort");

    handleStep();
}

void BubbleSortWidget::handleStep(){
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
    default:
        break;
    }
}
