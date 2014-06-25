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
    this->currentAction = NONE;
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
            ui->valueFrame->setStyleSheet("background-color: red; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case COMP:
            ui->valueFrame->setStyleSheet("background-color: blue; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case SWAP:
            ui->valueFrame->setStyleSheet("background-color: green; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case MARK:
            ui->valueFrame->setStyleSheet("background-color: cyan; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case MIN:
            ui->valueFrame->setStyleSheet("background-color: yellow; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case PIVOT:
            ui->valueFrame->setStyleSheet("background-color: purple; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
            break;
        case CPY:
            ui->valueFrame->setStyleSheet("background-color: white; border-style: outset; border-width: 2px; border-color: black; border-radius: 5px;");
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
