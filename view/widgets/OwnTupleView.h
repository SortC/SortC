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
    explicit OwnTupleView(QWidget *parent = 0, int anzValues = 0);
    ~OwnTupleView();

    QSpinBox **getBoxes() const;

private slots:
    void on_btnFinish_clicked();

private:
    Ui::OwnTupleView *ui;
    QSpinBox** boxes;
    QLabel** labels;
};

#endif // OWNTUPLEVIEW_H
