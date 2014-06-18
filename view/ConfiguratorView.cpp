#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"
#include <qmessagebox.h>

int ConfiguratorView::count = 0;

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

void ConfiguratorView::decrementCount()
{
    count--;
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

    if (count >= 2)
    {
        QMessageBox::information(this, tr("Fehler"), tr("Es können nur maximal zwei Sortierfenster gestartet werden"));
    }

    else{
        SortView* sortView = new SortView(0, zahlen , anzWerte);
        sortView->show();
        sortViewtab[count] = sortView;
        count++;
    }
}
