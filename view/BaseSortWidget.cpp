#include "BaseSortWidget.h"
#include "ui_BaseSortWidget.h"

BaseSortWidget::BaseSortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseSortWidget)
{
    ui->setupUi(this);
}

BaseSortWidget::~BaseSortWidget()
{
    delete ui;
}
