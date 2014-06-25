#include "MergeSortWidget.h"

MergeSortWidget::MergeSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    displayValues = new SortValue*[numbOfValues];
    helpArray = new SortValue*[numbOfValues];
    SortValue* newValue;
    SortValue* tempValues;

    int max = 0;
    for (int i = 0; i < numbOfValues; i++){
        if(max < startTuple[i])
            max = startTuple[i];
    }

    for (int i = 0; i < numbOfValues; i++){
        newValue = new SortValue(0, startTuple[i], max);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }

    for (int i = 0; i <= numbOfValues; i++){
        tempValues = new SortValue(0, i-1, max);
        ui->horLayoutSorting->addWidget(tempValues,0,Qt::AlignBottom);
        helpArray[i] = tempValues;

    }

    this->url = QString("http://de.wikipedia.org/wiki/Mergesort");

    handleStep();
}

void MergeSortWidget::handleStep()
{
    bool isMarked;
    int val1, val2, buffer;
    int markedValues;

    BaseSortWidget::handleStep();

    if (isMarked != true || false)
    {
        isMarked = false;
    }
    else
    {
        if (isMarked == true)
        {
            for(int i = 0; i < markedValues; i++) {
                displayValues[i]->setAction(SortValue::MARK);
            }
        }
        else
        {
            for(int i = 0; i < numbOfValues; i++) {
                displayValues[i]->setAction(SortValue::NONE);
            }
        }
    }

    val1 = algoCtrl->getCurrentStep()->getFirstValue();
    val2 = algoCtrl->getCurrentStep()->getSecondValue();

    switch (algoCtrl->getCurrentStep()->getOperation()) {
    case Step::COMP:
        displayValues[val1]->setAction(SortValue::COMP);
        displayValues[val2]->setAction(SortValue::COMP);
        break;
    case Step::R_CPY:
        helpArray[val1+1]->setAction(SortValue::CPY);
        displayValues[val2]->setAction(SortValue::NONE);

        displayValues[val2]->setValue(helpArray[val1+1]->getValue());
        break;
    case Step::CPY:
        displayValues[val1]->setAction(SortValue::CPY);
        helpArray[val2+1]->setAction(SortValue::CPY);

        helpArray[val2+1]->setValue(displayValues[val1]->getValue());

        break;
    case Step::MARK:
        markedValues = val2-val1;
        for (int i = 0; i <= markedValues; i++)
        {
            displayValues[val1+i]->setAction(SortValue::MARK);
            displayValues[val2]->setAction(SortValue::MARK);
        }
        isMarked = true;

        break;
    case Step::END:
        ui->btnPlayPause->setChecked(false);
        ui->btnNextStep->setEnabled(false);
        ui->btnPlayPause->setEnabled(false);
        for (int i = 0; i <= numbOfValues-1; i++)
        {
            displayValues[val1]->setAction(SortValue::NONE);
            displayValues[val1+i]->setAction(SortValue::NONE);
        }
    default:
        break;
    }
}

void MergeSortWidget::on_btnReset_clicked(){
    BaseSortWidget::on_btnReset_clicked();

    for(int i = 0; i<numbOfValues; i++){
        displayValues[i]->setValue(startTuple[i]);
    }
    handleStep();
}
