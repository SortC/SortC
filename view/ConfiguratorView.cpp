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
    int anzWerte = ui->valueSlider->value();

    //qDebug("Value1 = %d", anzWerte);
    int zahlen[anzWerte];

    for (int i = 0 ; i<anzWerte; i++)
    {
        zahlen[i] = anzWerte - i;
    }
    zahlen[3]= zahlen[1];

    SortView* sortView = new SortView(0, zahlen , anzWerte);
    sortView->show();
}
