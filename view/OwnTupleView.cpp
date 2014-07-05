#include "OwnTupleView.h"
#include "ui_OwnTupleView.h"

OwnTupleView::OwnTupleView(QWidget *parent, int* ownTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::OwnTupleView)
{
    ui->setupUi(this);
    this->numbOfValues = numbOfValues;
    valueBoxes = new QSpinBox*[numbOfValues];
    labels = new QLabel*[numbOfValues];

    bool isNumbEven = false;
    int numbOfElementsPerLine = numbOfValues;

    if(numbOfValues > 17) {
        if(numbOfValues % 2 == 0){
            numbOfElementsPerLine = numbOfValues / 2;
            isNumbEven = true;
        } else {
            numbOfElementsPerLine = numbOfValues / 2  + 1;
            isNumbEven = false;
            //numbOfElements = numbOfElementsPerLine * 2;
        }
    }
    this->placeHolderWidgets = new QWidget*[2];
    placeHolderWidgets[0] = NULL;
    placeHolderWidgets[1] = NULL;
    for(int i = 0; i < numbOfValues; i++){
        QSpinBox *sbox = new QSpinBox(this);
        sbox->setMaximum(maxValue);
        sbox->setMinimum(minValue);
        sbox->setAlignment(Qt::AlignCenter);
        sbox->setValue(ownTuple[i]);
        valueBoxes[i] = sbox;

        QLabel *lbl = new QLabel(this);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setText("[" + QString::number(i) + "]");
        labels[i]= lbl;

        if(i >= numbOfElementsPerLine) { // 2. Zeile einführen
            if(!isNumbEven && i == numbOfValues -1 ) {
                ui->horizontalLayoutValues2->addWidget(sbox);
                ui->horizontalLayoutLabels2->addWidget(lbl);

                //Platzhalter im Layout
                placeHolderWidgets[0] = new QWidget(this);
                placeHolderWidgets[1] = new QWidget(this);
                ui->horizontalLayoutValues2->addWidget(placeHolderWidgets[0]);
                ui->horizontalLayoutLabels2->addWidget(placeHolderWidgets[1]);
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

    this->ownTuple = ownTuple;
    this->parent = parent;

    // Verbindet das ownTupleUpdated() signal mit dem newOwnTuple()-Slot des Elternobjekts
    connect(this, SIGNAL(ownTupleUpdated()), parent, SLOT(newOwnTuple()));
}

OwnTupleView::~OwnTupleView()
{
    for(int i = 0; i < numbOfValues; i++){
        delete labels[i];
        delete valueBoxes[i];
    }
    delete valueBoxes;
    delete labels;
    delete placeHolderWidgets[0];
    delete placeHolderWidgets[1];
    delete placeHolderWidgets;
    delete ui;
}

void OwnTupleView::on_btnFinish_clicked()
{
    for(int i = 0; i < numbOfValues; i++){
        ownTuple[i] = valueBoxes[i]->value();
    }
    emit ownTupleUpdated();
    this->close();
    deleteLater();
}

void OwnTupleView::closeEvent(QCloseEvent *event)
{
    parentWidget()->show();
    event->accept();
    deleteLater();
}

