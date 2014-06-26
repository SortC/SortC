#include "TupleValue.h"
#include "ui_TupleValue.h"

TupleValue::TupleValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TupleValue)
{
    ui->setupUi(this);
}

TupleValue::~TupleValue()
{
    delete ui;
}
