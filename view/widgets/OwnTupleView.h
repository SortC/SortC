#ifndef OWNTUPLEVIEW_H
#define OWNTUPLEVIEW_H

#include <QMainWindow>
#include <qspinbox.h>
#include <qlabel.h>
#include "ui_OwnTupleView.h"

namespace Ui {
class OwnTupleView;
}

class OwnTupleView : public QMainWindow
{
    Q_OBJECT

public:
    explicit OwnTupleView(QWidget *parent = 0, int numbOfValues = 0);
    ~OwnTupleView();

signals:
    void ownTupleCreated(int* i);

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
