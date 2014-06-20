#ifndef INFOVIEW_H
#define INFOVIEW_H

#include <QMainWindow>

namespace Ui {
class InfoView;
}

class InfoView : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoView(QWidget *parent = 0, QString url = "about:blank");
    ~InfoView();

private:
    Ui::InfoView *ui;
    QString url;
};

#endif // INFOVIEW_H
