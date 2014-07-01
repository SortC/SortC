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

    this->directionForward = true;
    this->url = QString("http://www.wikipedia.de");
}

BaseSortWidget::~BaseSortWidget()
{
    delete timer;
    delete startTuple;
    delete ui;
}

void BaseSortWidget::on_btnNextStep_clicked()
{
    if(!directionForward){
        handleStep();
        directionForward = true;
    }
    algoCtrl->setNextStep();
    if(!timer->isActive()){
        ui->btnPrevStep->setEnabled(true);
        ui->btnReset->setEnabled(true);
    }
    handleStep();
}

void BaseSortWidget::on_btnPrevStep_clicked()
{
    if(directionForward){
        handleStep();
        directionForward = false;
    }
    algoCtrl->setPrevStep();
    if(algoCtrl->getCurrentStep()->getNumber() == 1){
        ui->btnPrevStep->setEnabled(false);
        ui->btnReset->setEnabled(false);
    }
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
    ui->btnPlayPause->setChecked(checked);
    ui->btnNextStep->setEnabled(!checked);
    ui->btnPrevStep->setEnabled(!checked);
    ui->intervalSpeedSlider->setEnabled(!checked);
    ui->btnReset->setEnabled(!checked);

    if(checked){
        ui->btnPlayPause->setIcon(QIcon(":/view/icons/pause.png"));
        timer->start(interval);
    }else{
        ui->btnPlayPause->setIcon(QIcon(":/view/icons/play.png"));
        timer->stop();
        if(algoCtrl->getCurrentStep()->getNumber() == 1){
            ui->btnPrevStep->setEnabled(false);
            ui->btnReset->setEnabled(false);
        }
    }
}

void BaseSortWidget::on_intervalSpeedSlider_sliderMoved(int position)
{
    interval = position;
}

void BaseSortWidget::on_btnReset_clicked()
{
    while(algoCtrl->getCurrentStep()->getNumber() > 1) {
        algoCtrl->setPrevStep();
    }

    ui->btnReset->setEnabled(false);
    ui->btnNextStep->setEnabled(true);
    ui->btnPlayPause->setEnabled(true);
    ui->btnPrevStep->setEnabled(false);
}

void BaseSortWidget::on_infoButton_clicked()
{
    QDesktopServices::openUrl(QUrl(this->url));
}
