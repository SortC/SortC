#include "SortView.h"
#include "ui_SortView.h"

SortView::SortView(QWidget *parent, int* startTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::SortView){
    ui->setupUi(this);
    this->startTuple = new int[numbOfValues];

    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = startTuple[i];
        QLabel *btn = new QLabel();
        //QRect *rect = new QRect();
        btn->setMinimumHeight(startTuple[i]*10);
        //*rect->setMinimumHeight(startTuple[i]*10);
        ui->horLayoutSorting->addWidget(btn);
    }
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
    ui->lcdNumActStep->display(controller->getBubbleSortCtrl()->getCurrentStep()->getNumber());
}

void SortView::on_btnPrevStep_clicked()
{
    controller->getBubbleSortCtrl()->setPrevStep();
    ui->lblExplanation->setText(QString::fromStdString(controller->getBubbleSortCtrl()->getCurrentStep()->toString()));
    ui->lcdNumActStep->display(controller->getBubbleSortCtrl()->getCurrentStep()->getNumber());
}
