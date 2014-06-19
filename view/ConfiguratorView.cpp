#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"


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

    int zahlen[anzWerte];

    QString itemText = ui->sortDierectionComboBox->currentText();

    if (itemText.compare(ui->sortDierectionComboBox->itemText(1)) && ui->sortCheckBox->isChecked())
    {
        for (int i = 0; i < anzWerte; i++)
        {
            zahlen[i] = i;
        }
    }
    else if (itemText.compare(ui->sortDierectionComboBox->itemText(2)) && ui->sortCheckBox->isChecked())
    {
        for (int i = 0; i < anzWerte; i++)
        {
            zahlen[i] = anzWerte - i;
        }
    }
    else
    {
        srand(time(NULL));
        int maxValue = 100;

        for (int i = 0; i < anzWerte; i++)
        {
            zahlen[i] = rand() % maxValue;
        }
    }

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
