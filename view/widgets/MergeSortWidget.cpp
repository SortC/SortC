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
        newValue = new SortValue(0, startTuple[i], max, i);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }

    for (int i = 0; i < numbOfValues; i++){
        tempValues = new SortValue(0, max, max, i);
        ui->horizontalLayout_4->addWidget(tempValues,0,Qt::AlignBottom);

        helpArray[i] = tempValues;
        //helpArray[i]->setMaximumHeight(max);
        helpArray[i]->setStyleSheet("background-color: white");
    }

    this->url = QString("http://de.wikipedia.org/wiki/Mergesort");

    handleStep();
}

void MergeSortWidget::handleStep()
{
    bool isMarked;
    int val1, val2;
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
            int i = 0;
            for(i = 0; i < markedValues; i++) {
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
        helpArray[val1]->setAction(SortValue::NONE);
        helpArray[val2]->setAction(SortValue::NONE);
        displayValues[val1]->setAction(SortValue::COMP);
        displayValues[val2]->setAction(SortValue::COMP);
        break;
    case Step::R_CPY:
        helpArray[val1]->setAction(SortValue::R_CPY);
        displayValues[val2]->setAction(SortValue::NONE);
        if(directionForward){
            displayValues[val2]->setValue(helpArray[val1]->getValue());
            //helpArray[val1]->hideValue();
        } else {
            helpArray[val1]->setValue(displayValues[val2]->getValue());
            //helpArray[val2]->setAction(SortValue::NONE);
            //helpArray[val1]->showValue();
        }
        break;
    case Step::CPY:
        displayValues[val1]->setAction(SortValue::CPY);
        helpArray[val2]->setAction(SortValue::CPY);
        if(directionForward){
            helpArray[val2]->setValue(displayValues[val1]->getValue());
            //helpArray[val2]->showValue();
        } else {
            displayValues[val1]->setValue(helpArray[val2]->getValue());

        }
        break;
    case Step::MARK:

        for (int j = 0; j < numbOfValues; j++)
        {
            helpArray[j]->setAction(SortValue::NONE);
        }

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
        for (int i = 0; i < numbOfValues; i++)
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

    int max = 0;
    for (int i = 0; i < numbOfValues; i++){
        if(max < startTuple[i])
            max = startTuple[i];
    }

    for(int i = 0; i<numbOfValues; i++){
        displayValues[i]->setValue(startTuple[i]);
        displayValues[i]->setAction(SortValue::NONE);
    }

    for(int i = 0; i < numbOfValues; i++){
        helpArray[i]->setValue(max);
        helpArray[i]->setStyleSheet("background-color: white");
        //helpArray[i]->setAction(SortValue::NONE);
    }
    handleStep();
}
