#ifndef BASESORTWIDGET_H
#define BASESORTWIDGET_H

#include <QWidget>

namespace Ui {
class BaseSortWidget;
}

class BaseSortWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseSortWidget(QWidget *parent = 0);
    ~BaseSortWidget();

private:
    Ui::BaseSortWidget *ui;
};

#endif // BASESORTWIDGET_H
