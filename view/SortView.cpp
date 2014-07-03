#include "SortView.h"
#include "ConfiguratorView.h"

SortView::SortView(QWidget *parent, int* startTuple, int numbOfValues) :
    QMainWindow(parent),
    ui(new Ui::SortView){
    ui->setupUi(this);
    this->startTuple = new int[numbOfValues];

    for (int i = 0; i < numbOfValues; i++)
    {
        this->startTuple[i] = startTuple[i];
    }

    this->numbOfValues = numbOfValues;
    controller = new Controller(startTuple, numbOfValues);

    createTabs();
    addTabs();
}

SortView::~SortView()
{
    ui->tabWidget->clear();
    delete bsWidget;
    delete isWidget;
    delete ssWidget;
    delete qsWidget;
    delete msWidget;
    delete hsWidget;
    delete bucksWidget;
    delete ui;
}

void SortView::closeEvent(QCloseEvent *event)
{
        ConfiguratorView cV(0);
        cV.decrementCount();
        event->accept();
        deleteLater();
}

void SortView::createTabs()
{
    bsWidget = new BubbleSortWidget(ui->tabWidget, controller->getBubbleSortCtrl(),startTuple,numbOfValues);
    isWidget = new InsertionSortWidget(ui->tabWidget, controller->getInsertionSortCtrl(),startTuple,numbOfValues);
    ssWidget = new SelectionSortWidget(ui->tabWidget, controller->getSelectionSortCtrl(),startTuple,numbOfValues);
    qsWidget = new QuickSortWidget(ui->tabWidget, controller->getQuickSortCtrl(),startTuple,numbOfValues);
    msWidget = new MergeSortWidget(ui->tabWidget, controller->getMergeSortCtrl(),startTuple,numbOfValues);
    hsWidget = new EmptySortWidget(ui->tabWidget, controller->getHeapSortCtrl(),startTuple,numbOfValues);
    bucksWidget = new EmptySortWidget(ui->tabWidget, controller->getBucketSortCtrl(),startTuple,numbOfValues);
}

void SortView::addTabs(){
    ui->tabWidget->clear();

    ui->tabWidget->addTab(bsWidget ,QString("BubbleSort"));
    ui->tabWidget->addTab(isWidget ,QString("InsertionSort"));
    ui->tabWidget->addTab(ssWidget ,QString("SelectionSort"));
    ui->tabWidget->addTab(qsWidget ,QString("QuickSort"));
    ui->tabWidget->addTab(msWidget ,QString("MergeSort"));
    ui->tabWidget->addTab(hsWidget ,QString("HeapSort"));
    ui->tabWidget->addTab(bucksWidget ,QString("BucketSort"));
}

void SortView::on_tabWidget_currentChanged()
{
    bsWidget->on_btnPlayPause_toggled(false);
    isWidget->on_btnPlayPause_toggled(false);
    ssWidget->on_btnPlayPause_toggled(false);
    qsWidget->on_btnPlayPause_toggled(false);
    msWidget->on_btnPlayPause_toggled(false);
    bucksWidget->on_btnPlayPause_toggled(false);
    hsWidget->on_btnPlayPause_toggled(false);
}
