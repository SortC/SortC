#ifndef OWNTUPLEVIEW_H
#define OWNTUPLEVIEW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>
#include <QCloseEvent>

#include "ui_OwnTupleView.h"

const int maxValue = 999;
const int minValue = 1;

namespace Ui {
class OwnTupleView;
}

class OwnTupleView : public QMainWindow
{
    Q_OBJECT

public:
    explicit OwnTupleView(QWidget *parent = 0, int* ownTuple = NULL, int numbOfValues = 0);
    ~OwnTupleView();

    void closeEvent(QCloseEvent *event);

signals:
    void ownTupleUpdated();

private slots:
    void on_btnFinish_clicked();

private:
    Ui::OwnTupleView *ui;
    int numbOfValues;
    QSpinBox** valueBoxes;
    QLabel** labels;
    QWidget* parent;
    int * ownTuple;
};

#endif // OWNTUPLEVIEW_H
