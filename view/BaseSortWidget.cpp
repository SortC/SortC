#include "BaseSortWidget.h"
#include "ui_BaseSortWidget.h"

BaseSortWidget::BaseSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    QWidget(parent),
    ui(new Ui::BaseSortWidget)
{
    this->parent = parent;
    this->algoCtrl = algoCtrl;
    this->startTuple = startTuple;
    this->numbOfValues = numbOfValues;
    ui->setupUi(this);
}

BaseSortWidget::~BaseSortWidget()
{
    delete ui;
}

void BaseSortWidget::on_btnNextStep_clicked()
{
    //parent->controller->getBubbleSortCtrl()->setNextStep();
    //handleStep();
}

void BaseSortWidget::on_btnPrevStep_clicked()
{
    //parent->controller->getBubbleSortCtrl()->setPrevStep();
    //handleStep();
}
