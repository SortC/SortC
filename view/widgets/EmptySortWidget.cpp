#include "EmptySortWidget.h"

EmptySortWidget::EmptySortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    BaseSortWidget(parent, algoCtrl, startTuple, numbOfValues)
{
    imageContainer = new QLabel;
    QPixmap image = QPixmap("://view/icons/construction.png", 0, Qt::AutoColor);
    imageContainer->setPixmap(image);
    ui->horLayoutSorting->addWidget(imageContainer,0,Qt::AlignCenter);
    handleStep();
}

EmptySortWidget::~EmptySortWidget(){
    delete imageContainer;
}

void EmptySortWidget::handleStep()
{
    BaseSortWidget::handleStep();
}

void EmptySortWidget::on_btnReset_clicked(){
    BaseSortWidget::on_btnReset_clicked();
    handleStep();
}
