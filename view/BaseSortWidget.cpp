#include "BaseSortWidget.h"

BaseSortWidget::BaseSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    QWidget(parent),
    ui(new Ui::BaseSortWidget)
{
    this->parent = parent;
    this->algoCtrl = algoCtrl;
    this->startTuple = new int[numbOfValues];
    this->numbOfValues = numbOfValues;
    for(int i = 0; i < numbOfValues; i++){
        this->startTuple[i] = startTuple[i];
    }
    ui->setupUi(this);
}

BaseSortWidget::~BaseSortWidget()
{
    delete startTuple;
    delete ui;
}

void BaseSortWidget::on_btnNextStep_clicked()
{
    algoCtrl->setNextStep();
    handleStep();
}

void BaseSortWidget::on_btnPrevStep_clicked()
{
    algoCtrl->setPrevStep();
    handleStep();
}

void BaseSortWidget::handleStep(){

}
