#ifndef CONFIGURATORVIEW_H
#define CONFIGURATORVIEW_H

#include <QMainWindow>
#include "SortView.h"

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

private:
    Ui::ConfiguratorView *ui;
    SortView* sortViewtab[2];
    static int count;
};

#endif // CONFIGURATORVIEW_H
