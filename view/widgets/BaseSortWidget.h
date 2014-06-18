#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QTimer>
#include "controller/AlgorithmController.h"
#include "ui_BaseSortWidget.h"

namespace Ui {
class BaseSortWidget;
}

class BaseSortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseSortWidget(QWidget *parent = 0, AlgorithmController* algoCtrl = NULL, int* startTuple = NULL , int numbOfValues = 0);
    ~BaseSortWidget();

private slots:
    void on_btnPrevStep_clicked();
    void on_btnNextStep_clicked();
    void on_btnPlayPause_toggled(bool checked);
    void on_intervalSpeedSlider_sliderMoved(int position);

protected:
    virtual void handleStep();

    int interval;

    QTimer* timer;
    QWidget *parent;
    AlgorithmController* algoCtrl;
    int* startTuple;
    int numbOfValues;
    Ui::BaseSortWidget *ui;
};

#endif // BASESORTWIDGET_H
