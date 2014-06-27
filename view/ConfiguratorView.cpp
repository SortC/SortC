#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"


int ConfiguratorView::count = 0;

ConfiguratorView::ConfiguratorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfiguratorView)
{
    ui->setupUi(this);
    this->numberOfValues = ui->valueSlider->value();

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
            zahlen[i] = i + 1;
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
        for (int i = 0; i < anzWerte; i++)
        {
            zahlen[i] = (rand() % maxValue) + 1;
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


void ConfiguratorView::on_btnOwnValues_clicked()
{
    int anzValues = ui->valueSlider->value();

    otv = new OwnTupleView(this, anzValues);
    otv->show();
}

void ConfiguratorView::on_radioButtonRandomValues_toggled(bool checked)
{
    ui->radioButtonOwnValues->setChecked(!checked);
    if (checked) {
        ui->btnOwnValues->setEnabled(false);
        ui->sortCheckBox->setEnabled(true);
        ui->startBtn->setEnabled(true);
    }
}

void ConfiguratorView::on_radioButtonOwnValues_toggled(bool checked)
{
    ui->radioButtonRandomValues->setChecked(!checked);
    if(checked) {
       ui->btnOwnValues->setEnabled(true);
       ui->sortCheckBox->setEnabled(false);
       ui->startBtn->setEnabled(false);
    } else{
        on_radioButtonRandomValues_toggled(!checked);
    }
}

void ConfiguratorView::newOwnTuple(int *ownTuple)
{
    this->ownTuple = ownTuple;

    for(int i = 0; i<numberOfValues; i++){
        std::cout << this->ownTuple[i] <<", ";
    }
    std::cout << std::endl;
}

void ConfiguratorView::on_valueSlider_valueChanged(int value)
{
    this->numberOfValues = value;
}
