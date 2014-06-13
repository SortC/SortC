#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QMainWindow>

namespace Ui {
class SortView;
}

class SortView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortView(QWidget *parent = 0);
    ~SortView();

private:
    Ui::SortView *ui;
};

#endif // SORTVIEW_H
