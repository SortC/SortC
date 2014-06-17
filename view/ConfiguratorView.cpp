#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"
#include "SortView.h"

ConfiguratorView::ConfiguratorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfiguratorView)
{
    ui->setupUi(this);
}



ConfiguratorView::~ConfiguratorView()
{
    delete ui;
}

void ConfiguratorView::on_startBtn_clicked()
{
    //qDebug("Value1 = %.4f", ui->valueSpinBox->value());
    //SortView* sortView = new SortView(0, 0 , ui->valueSpinBox->value());
    //sortView->show();
}
