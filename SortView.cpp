#include "SortView.h"
#include "ui_SortView.h"
#include <QColorDialog>

#include "model/Step.h"

const int FACTOR = 10;

SortView::SortView(QWidget *parent, int* startTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::SortView){
    ui->setupUi(this);
    this->startTuple = new int[numbOfValues];

    btns = new QPushButton*[numbOfValues];
    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = startTuple[i];
        QPushButton *btn = new QPushButton();
        btn->setText(QString::number(startTuple[i]));
        btn->setAutoFillBackground(true);
        btn->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
        btn->setMinimumHeight(startTuple[i]*10);
        ui->horLayoutSorting->addWidget(btn);
        btns[i] = btn;
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
    handleStep();
}

void SortView::on_btnPrevStep_clicked()
{
    controller->getBubbleSortCtrl()->setPrevStep();
    handleStep();
}

void SortView::handleStep() {
    ui->lblExplanation->setText(QString::fromStdString(controller->getBubbleSortCtrl()->getCurrentStep()->toString()));
    ui->lcdNumActStep->display(controller->getBubbleSortCtrl()->getCurrentStep()->getNumber());
    for(int i = 0; i < numbOfValues; i++) {
        btns[i]->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255, 255, 255)");
    }
    int val1, val2;
    val1 = controller->getBubbleSortCtrl()->getCurrentStep()->getFirstValue();
    val2 = controller->getBubbleSortCtrl()->getCurrentStep()->getSecondValue();
    btns[val1]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");
    btns[val2]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");

    switch (controller->getBubbleSortCtrl()->getCurrentStep()->getOperation()) {
    case Step::COMP:
        break;
    case Step::SWAP:

        break;
    default:
        break;
    }
}
