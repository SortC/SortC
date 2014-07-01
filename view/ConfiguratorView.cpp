#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"


int ConfiguratorView::count = 0;

ConfiguratorView::ConfiguratorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfiguratorView)
{
    ui->setupUi(this);
    this->numberOfValues = ui->valueSlider->value();
    this->ownTuple = new int[maxNumbOfValues];
    for (int i = 0; i < maxNumbOfValues; i++){
        this->ownTuple[i] = 1;
    }

    this->ownValuesValid = false;
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
    int values[numberOfValues];
    if ( ui->radioButtonOwnValues->isChecked() )
    {
        for(int i = 0; i < numberOfValues; i++)
        {
            values[i] = ownTuple[i];
        }
    }
    else if ((ui->sortDierectionComboBox->currentIndex() == 0) && ui->sortCheckBox->isChecked())
    {
        for (int i = 0; i < numberOfValues; i++)
        {
            values[i] = i + 1;
        }
    }
    else if ((ui->sortDierectionComboBox->currentIndex() == 1) && ui->sortCheckBox->isChecked())
    {
        for (int i = 0; i < numberOfValues; i++)
        {
            values[i] = numberOfValues - i;
        }
    }
    else
    {
        srand(time(NULL));
        for (int i = 0; i < numberOfValues; i++)
        {
            values[i] = (rand() % maxRandomValue) + 1;
        }
    }

    if (count >= maxNumbOfOpenSortViews)
    {
        QMessageBox::information(this, tr("Fehler"), tr("Es können nur maximal zwei Sortierfenster gleichzeitig gestartet werden"));
    }
    else{
        SortView* sortView = new SortView(0, values , numberOfValues);
        sortView->show();
        sortViewtab[count] = sortView;
        count++;
    }
}


void ConfiguratorView::on_btnOwnValues_clicked()
{
    int numberOfValues = ui->valueSlider->value();

    otv = new OwnTupleView(this, ownTuple, numberOfValues);
    otv->show();
    this->hide();
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
       if(!ownValuesValid){
            ui->startBtn->setEnabled(false);
       }
    } else{
        on_radioButtonRandomValues_toggled(!checked);
    }
}

void ConfiguratorView::newOwnTuple()
{
    ownValuesValid = true;
    ui->startBtn->setEnabled(true);
}

void ConfiguratorView::on_valueSlider_valueChanged(int value)
{
    this->numberOfValues = value;
    ownValuesValid = false;
    if(ui->radioButtonOwnValues->isChecked())
        ui->startBtn->setEnabled(false);
}
