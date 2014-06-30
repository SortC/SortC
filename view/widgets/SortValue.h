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
    enum Action {NONE, COMP, RIGHTINDEX, LEFTINDEX, SWAP, MARK, MIN, PIVOT, CPY, R_CPY};
    explicit SortValue(QWidget *parent = 0, int value = 0, int maxValue = 100, int arrayIndex = 0);
    ~SortValue();

    void setValue(int value);
    int getValue(){return value;}

    bool getValueVisible(){return valueVisible;}

    void setAction(Action action);
    void resizeValue();

    void showValue();
    void hideValue();

    void resizeEvent ( QResizeEvent * event );

private slots:

private:
    Ui::SortValue *ui;
    int arrayIndex;
    int value;
    int maxValue;
    QString styleSheetBuffer;
    Action currentAction;
    bool valueVisible;
};

#endif // SORTVALUE_H
