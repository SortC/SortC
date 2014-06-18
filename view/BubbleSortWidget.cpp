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
