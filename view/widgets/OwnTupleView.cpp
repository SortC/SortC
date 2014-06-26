#include "OwnTupleView.h"
#include "ui_OwnTupleView.h"

OwnTupleView::OwnTupleView(QWidget *parent, int anzValues) :
    QMainWindow(parent),
    ui(new Ui::OwnTupleView)
{
    ui->setupUi(this);
    boxes = new QSpinBox*[anzValues];
    labels = new QLabel*[anzValues];
    bool isAnzEven;
    int anzElementsPerLine = anzValues;
    int anzElementsGesamt = anzValues;

    if(anzValues > 17) {
    if(anzValues % 2 == 0){
        anzElementsPerLine = anzValues / 2;
        isAnzEven = true;
        }
        else {
            anzElementsPerLine = anzValues / 2  + 1;
            isAnzEven = false;
            anzElementsGesamt = anzElementsPerLine * 2;
        }
    }

    for(int i = 0; i < anzElementsGesamt; i++){
        QSpinBox *sbox = new QSpinBox(this);
        sbox->setMaximum(99);
        sbox->setMinimum(1);
        sbox->setValue(1);
        boxes[i] = sbox;

        QLabel *lbl = new QLabel(this);
        lbl->setText(QString::number(i));
        labels[i]= lbl;

        if(i >= anzElementsPerLine) { // 2. Zeile einführen
            if(!isAnzEven && i == anzElementsGesamt -1 ) {  // dann letztes Element unsichtbar
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
}

OwnTupleView::~OwnTupleView()
{
    delete ui;
}

QSpinBox **OwnTupleView::getBoxes() const
{
    return boxes;
}

void OwnTupleView::on_btnFinish_clicked()
{

    ui->btnFinish->installEventFilter(this->parent());
}


