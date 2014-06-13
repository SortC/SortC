#include "SortView.h"
#include "ui_SortView.h"

SortView::SortView(QWidget *parent, int* startTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::SortView)
{
    this->startTuple = new int[numbOfValues];
    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = startTuple[i];
    }
    ui->setupUi(this);
    this->startTuple = startTuple;
    this->numbOfValues = numbOfValues;
    controller = new Controller(startTuple, numbOfValues);
}

SortView::~SortView()
{
    delete ui;
}

void SortView::on_btnNextStep_clicked()
{
    controller->getBubbleSortCtrl()->setNextStep();
    ui->lblExplanation->setText(QString::fromStdString(controller->getBubbleSortCtrl()->getCurrentStep()->toString()));

}

void SortView::on_btnPrevStep_clicked()
{
    controller->getBubbleSortCtrl()->setPrevStep();
    ui->lblExplanation->setText(QString::fromStdString(controller->getBubbleSortCtrl()->getCurrentStep()->toString()));
}
