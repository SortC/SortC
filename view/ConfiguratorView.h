#ifndef CONFIGURATORVIEW_H
#define CONFIGURATORVIEW_H

#include <QMainWindow>

namespace Ui {
class ConfiguratorView;
}

class ConfiguratorView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConfiguratorView(QWidget *parent = 0);
    ~ConfiguratorView();

private slots:
    void on_startBtn_clicked();

private:
    Ui::ConfiguratorView *ui;
};

#endif // CONFIGURATORVIEW_H
