#ifndef CONFIGURATORVIEW_H
#define CONFIGURATORVIEW_H

#include <QMainWindow>
#include "SortView.h"
#include "widgets/OwnTupleView.h"
#include <qmessagebox.h>
#include <cstdlib>
#include <time.h>

const int maxValue = 100;

namespace Ui {
class ConfiguratorView;
}

class ConfiguratorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfiguratorView(QWidget *parent = 0);
    ~ConfiguratorView();

    void decrementCount();



private slots:
    void on_startBtn_clicked();

    void on_btnOwnValues_clicked();

    void on_radioButtonRandomValues_toggled(bool checked);

    void on_radioButtonOwnValues_toggled(bool checked);



protected:
  bool eventFilter(QObject *qobj, QEvent *qev);

private:
    OwnTupleView *otv;
    Ui::ConfiguratorView *ui;
    SortView* sortViewtab[2];
    static int count;
};

#endif // CONFIGURATORVIEW_H
