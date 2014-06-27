#include "OwnTupleView.h"
#include "ui_OwnTupleView.h"

OwnTupleView::OwnTupleView(QWidget *parent, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::OwnTupleView)
{
    ui->setupUi(this);
    this->numbOfValues = numbOfValues;
    valueBoxes = new QSpinBox*[numbOfValues];
    labels = new QLabel*[numbOfValues];
    bool isNumbEven;
    int numbOfElementsPerLine = numbOfValues;
    int numbOfElements = numbOfValues;

    if(numbOfValues > 17) {
    if(numbOfValues % 2 == 0){
        numbOfElementsPerLine = numbOfValues / 2;
        isNumbEven = true;
        }
        else {
            numbOfElementsPerLine = numbOfValues / 2  + 1;
            isNumbEven = false;
            numbOfElements = numbOfElementsPerLine * 2;
        }
    }

    for(int i = 0; i < numbOfElements; i++){
        QSpinBox *sbox = new QSpinBox(this);
        sbox->setMaximum(99);
        sbox->setMinimum(1);
        sbox->setValue(1);
        valueBoxes[i] = sbox;

        QLabel *lbl = new QLabel(this);
        lbl->setText(QString::number(i));
        labels[i]= lbl;

        if(i >= numbOfElementsPerLine) { // 2. Zeile einführen
            if(!isNumbEven && i == numbOfElements -1 ) {  // dann letztes Element unsichtbar
                sbox->setEnabled(false);
                lbl->setEnabled(false);
                ui->horizontalLayoutValues2->addWidget(sbox);
                ui->horizontalLayoutLabels2->addWidget(lbl);
            }
            else{
                ui->horizontalLayoutValues2->addWidget(sbox);
                ui->horizontalLayoutLabels2->addWidget(lbl);
            }
        }
        else {
            ui->horizontalLayoutValues->addWidget(sbox);
            ui->horizontalLayoutLabels->addWidget(lbl);
        }
    }
    ownTuple = new int[numbOfValues];
    this->parent = parent;
    connect(this, SIGNAL(ownTupleCreated(int*)), parent, SLOT(newOwnTuple(int*)));
}

OwnTupleView::~OwnTupleView()
{
    delete ui;
}

void OwnTupleView::on_btnFinish_clicked()
{
    for(int i = 0; i < numbOfValues; i++){
        ownTuple[i] = valueBoxes[i]->value();
    }
    emit ownTupleCreated(ownTuple);
}


