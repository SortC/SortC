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
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ebf4fd, stop: 0.5 #bed2e6); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case COMP:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #c0c7f9, stop: 0.5 #697dfa); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case SWAP:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #d4f8d0, stop: 0.5 #75ff69); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case MARK:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f9f6ea, stop: 0.5 #ede2c0); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case MIN:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f9d9d9, stop: 0.5 #fc6060); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case PIVOT:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f9d9d9, stop: 0.5 #fc6060); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case CPY:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #e3a8f2, stop: 0.5 #c000f0); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case RIGHTINDEX:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f9d9d9, stop: 0.5 #fc6060); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case LEFTINDEX:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #e3a8f2, stop: 0.5 #c000f0); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
            break;
        case R_CPY:
            styleSheetBuffer = "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #f4f8cd, stop: 0.5 #eaff00); border-style: outset; border-width: 0px; border-color: black; border-radius: 5px;";
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
