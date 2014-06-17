#include "SortView.h"
#include "ui_SortView.h"
#include <QColorDialog>



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
        btn->setMinimumHeight(startTuple[i]*4);
        ui->horLayoutSorting->addWidget(btn,0,Qt::AlignBottom);
        btns[i] = btn;
    }
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

    QString tempText = btns[val1]->text();
    int tempHeight = btns[val1]->size().height();

    switch (controller->getBubbleSortCtrl()->getCurrentStep()->getOperation()) {
    case Step::COMP:
        btns[val1]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");
        btns[val2]->setStyleSheet("background-color: rgb(0, 0, 255); color: rgb(255, 255, 255)");

        break;
    case Step::SWAP:
        btns[val1]->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(255, 255, 255)");
        btns[val2]->setStyleSheet("background-color: rgb(0, 255, 0); color: rgb(255, 255, 255)");

        btns[val1]->setMinimumHeight(btns[val2]->size().height());
        btns[val2]->setMinimumHeight(tempHeight);
        btns[val1]->setText(btns[val2]->text());
        btns[val2]->setText(tempText);

        break;
    default:
        break;
    }
}
