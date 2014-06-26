#ifndef TUPLEVALUE_H
#define TUPLEVALUE_H

#include <QWidget>

namespace Ui {
class TupleValue;
}

class TupleValue : public QWidget
{
    Q_OBJECT

public:
    explicit TupleValue(QWidget *parent = 0);
    ~TupleValue();

private:
    Ui::TupleValue *ui;
};

#endif // TUPLEVALUE_H
