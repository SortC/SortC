#include "SortValue.h"
#include "ui_SortValue.h"

SortValue::SortValue(QWidget *parent, int value, int maxValue) :
    QWidget(parent),
    ui(new Ui::SortValue)
{
    ui->setupUi(this);
    this->maxValue = maxValue;
    this->value = value;
    ui->valueLabel->setText(QString::number(value));
    this->setAction(NONE);
}

SortValue::~SortValue()
{
    delete ui;
}

void SortValue::setValue(int value)
{
    this->value = value;

    ui->valueLabel->setText(QString::number(value));

    resizeValue();
}

void SortValue::setAction(Action action)
{
    if(action != currentAction)
    {
        switch (action)
        {
        case NONE:
            ui->valueFrame->setStyleSheet("background-color: rgb(190, 210, 230); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case COMP:
            ui->valueFrame->setStyleSheet("background-color: rgb(105, 125, 250); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case SWAP:
            ui->valueFrame->setStyleSheet("background-color: rgb(117, 255, 105); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case MARK:
            ui->valueFrame->setStyleSheet("background-color: rgb(237, 226, 192); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case MIN:
            ui->valueFrame->setStyleSheet("background-color: rgb(252, 96, 96); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case PIVOT:
            ui->valueFrame->setStyleSheet("background-color: rgb(252, 96, 96); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case CPY:
            ui->valueFrame->setStyleSheet("background-color: rgb(192, 0, 240); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case R_CPY:
            ui->valueFrame->setStyleSheet("background-color: rgb(234, 255, 0); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        }
        currentAction = action;
    }
}

void SortValue::resizeValue()
{
    int currentSpace = ui->Container->height() - 30;
    if(currentSpace >= 0){
        currentSpace = (int)round((currentSpace * value) / maxValue);
        ui->valueFrame->setMinimumHeight(currentSpace);
        ui->valueFrame->setMaximumHeight(currentSpace);
    }
}

void SortValue::resizeEvent(QResizeEvent* event)
{
    resizeValue();
    event->accept();
}
