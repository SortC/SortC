#include "InfoView.h"
#include "ui_InfoView.h"

InfoView::InfoView(QWidget *parent, QString url) :
    QMainWindow(parent),
    ui(new Ui::InfoView)
{
    ui->setupUi(this);
    this->url = url;

    ui->webView->load(QUrl(url));
}

InfoView::~InfoView()
{
    delete ui;
}
