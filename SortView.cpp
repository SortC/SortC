#include "SortView.h"
#include "ui_SortView.h"

SortView::SortView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortView)
{
    ui->setupUi(this);
}

SortView::~SortView()
{
    delete ui;
}
