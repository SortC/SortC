#include "ConfiguratorView.h"
#include "ui_ConfiguratorView.h"

ConfiguratorView::ConfiguratorView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfiguratorView)
{
    ui->setupUi(this);
}

ConfiguratorView::~ConfiguratorView()
{
    delete ui;
}
