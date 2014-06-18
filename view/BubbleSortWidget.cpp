#include "BubbleSortWidget.h"

BubbleSortWidget::BubbleSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    displayValues = new QPushButton*[numbOfValues];
    QPushButton* newValue;

    for (int i = 0; i < numbOfValues; i++){
        newValue = new QPushButton();
        newValue->setText(QString::number(startTuple[i]));
        newValue->setAutoFillBackground(true);
        newValue->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
        newValue->setMinimumHeight(startTuple[i]*4);
        ui->horLayoutSorting->addWidget(newValue,0,Qt::AlignBottom);
        displayValues[i] = newValue;
    }
}

void BubbleSortWidget::handleStep(){
    BaseSortWidget::handleStep();
    for(int i = 0; i < numbOfValues; i++) {
        displayValues[i]->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
    }
    int val1, val2;

    val1 = algoCtrl->getCurrentStep()->getFirstValue();
    val2 = algoCtrl->getCurrentStep()->getSecondValue();

    QString tempText = displayValues[val1]->text();
    int tempHeight = displayValues[val1]->size().height();

    switch (algoCtrl->getCurrentStep()->getOperation()) {
    case Step::COMP:
        displayValues[val1]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");
        displayValues[val2]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");

        break;
    case Step::SWAP:
        displayValues[val1]->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(255, 255, 255)");
        displayValues[val2]->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(255, 255, 255)");

        displayValues[val1]->setMinimumHeight(displayValues[val2]->size().height());
        displayValues[val2]->setMinimumHeight(tempHeight);
        displayValues[val1]->setText(displayValues[val2]->text());
        displayValues[val2]->setText(tempText);

        break;
    default:
        break;
    }
}
