#include "SortView.h"
#include "ui_SortView.h"

SortView::SortView(QWidget *parent, int* startTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::SortView)
{
    ui->setupUi(this);
    this->startTuple = startTuple;
    this->numbOfValues = numbOfValues;
    controller = new Controller(startTuple, numbOfValues);
}

SortView::~SortView()
{
    delete ui;
}
