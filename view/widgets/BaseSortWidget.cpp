#include "BaseSortWidget.h"

BaseSortWidget::BaseSortWidget(QWidget *parent, AlgorithmController* algoCtrl, int* startTuple, int numbOfValues) :
    QWidget(parent),
    ui(new Ui::BaseSortWidget)
{
    this->parent = parent;
    this->algoCtrl = algoCtrl;
    this->startTuple = new int[numbOfValues];
    this->numbOfValues = numbOfValues;
    for(int i = 0; i < numbOfValues; i++){
        this->startTuple[i] = startTuple[i];
    }
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(on_btnNextStep_clicked()));
    ui->setupUi(this);
    this->interval = ui->intervalSpeedSlider->value();

    this->url = QString("http://www.wikipedia.de");
    this->infoViewOpen = false;
}

BaseSortWidget::~BaseSortWidget()
{
    delete timer;
    delete startTuple;
    delete ui;
}

void BaseSortWidget::on_btnNextStep_clicked()
{
    algoCtrl->setNextStep();
    if(!timer->isActive())
        ui->btnPrevStep->setEnabled(true);
    handleStep();
}

void BaseSortWidget::on_btnPrevStep_clicked()
{
    algoCtrl->setPrevStep();
    if(algoCtrl->getCurrentStep()->getNumber() == 1)
        ui->btnPrevStep->setEnabled(false);
    ui->btnNextStep->setEnabled(true);
    ui->btnPlayPause->setEnabled(true);
    handleStep();
}

void BaseSortWidget::handleStep(){
    ui->lblExplanation->setText(QString::fromStdString(algoCtrl->getCurrentStep()->toString()));
    ui->lcdNumActStep->display(algoCtrl->getCurrentStep()->getNumber());
}

void BaseSortWidget::on_btnPlayPause_toggled(bool checked)
{
    ui->btnNextStep->setEnabled(!checked);
    ui->btnPrevStep->setEnabled(!checked);
    ui->intervalSpeedSlider->setEnabled(!checked);
     ui->btnReset->setEnabled(!checked);

    QString play = "PLAY";
    QString pause = "PAUSE";

    if(checked){
        ui->btnPlayPause->setText(pause);
        timer->start(interval);
    }else{
        ui->btnPlayPause->setText(play);
        timer->stop();
    }
}

void BaseSortWidget::on_intervalSpeedSlider_sliderMoved(int position)
{
    interval = position;
}

void BaseSortWidget::on_pushButton_clicked()
{
    InfoView* infoView = new InfoView(0,this->url);
    infoView->show();
}

void BaseSortWidget::on_btnReset_clicked()
{
    while(algoCtrl->getCurrentStep()->getNumber() > 1) {
        algoCtrl->setPrevStep();
        QThread::msleep(1);
        handleStep();
    }
    ui->btnNextStep->setEnabled(true);
    ui->btnPlayPause->setEnabled(true);
    ui->btnPrevStep->setEnabled(false);
}
