#include "SortValue.h"
#include "ui_SortValue.h"

SortValue::SortValue(QWidget *parent, int value, int maxValue, int arrayIndex) :
    QWidget(parent),
    ui(new Ui::SortValue)
{
    ui->setupUi(this);
    this->maxValue = maxValue;
    this->value = value;
    this->arrayIndex = arrayIndex;
    ui->valueLabel->setText(QString::number(value));
    ui->arrayLabel->setText("[" + QString::number(arrayIndex) + "]");
    valueVisible = true;
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
            styleSheetBuffer = "background-color: rgb(190, 210, 230); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case COMP:
            styleSheetBuffer = "background-color: rgb(105, 125, 250); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case SWAP:
            styleSheetBuffer = "background-color: rgb(117, 255, 105); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case MARK:
            styleSheetBuffer = "background-color: rgb(237, 226, 192); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case MIN:
            styleSheetBuffer = "background-color: rgb(252, 96, 96); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case PIVOT:
            styleSheetBuffer = "background-color: rgb(252, 96, 96); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case CPY:
            styleSheetBuffer = "background-color: rgb(192, 0, 240); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        case R_CPY:
            styleSheetBuffer = "background-color: rgb(234, 255, 0); border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;";
            break;
        }
        currentAction = action;
        if(valueVisible){
            ui->valueFrame->setStyleSheet(styleSheetBuffer);
        }
    }
}

void SortValue::resizeValue()
{
    int currentSpace = ui->Container->height() - 40;
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

void SortValue::showValue()
{
    if(!valueVisible){
        ui->valueFrame->setStyleSheet(styleSheetBuffer);
        ui->valueLabel->show();
        valueVisible = true;
    }
}

void SortValue::hideValue()
{
    if(valueVisible){
        ui->valueFrame->setStyleSheet("background: transparent; border: 1px solid transparent;");
        ui->valueLabel->hide();
        valueVisible = false;
    }
}
