#ifndef SORTVALUE_H
#define SORTVALUE_H

#include <QWidget>
#include <math.h>
#include <QResizeEvent>

namespace Ui {
class SortValue;
}

class SortValue : public QWidget
{
    Q_OBJECT

public:
    enum Action {NONE, COMP, SWAP, MARK, MIN, PIVOT, CPY};
    explicit SortValue(QWidget *parent = 0, int value = 0, int maxValue = 100);
    ~SortValue();

    void setValue(int value);
    int getValue(){return value;}
    void setAction(Action action);
    void resizeValue();
    void resizeEvent ( QResizeEvent * event );

private slots:

private:
    Ui::SortValue *ui;
    int value;
    int maxValue;
    Action currentAction;
};

#endif // SORTVALUE_H