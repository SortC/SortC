#include "SortView.h"
#include "ui_SortView.h"
#include <QColorDialog>
#include <QString>
#include "ConfiguratorView.h"



const int FACTOR = 10;

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
    addTabs();
}

void SortView::closeEvent(QCloseEvent *event)
{
        ConfiguratorView cV(0);
        cV.decrementCount();
}

SortView::~SortView()
{
    delete ui;
}

void SortView::addTabs(){
    ui->tabWidget->clear();
    QWidget* bsWidget = new BubbleSortWidget(ui->tabWidget, controller->getBubbleSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(bsWidget ,QString("BubbleSort"));

    QWidget* isWidget = new InsertionSortWidget(ui->tabWidget, controller->getInsertionSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(isWidget ,QString("InsertionSort"));

    QWidget* ssWidget = new SelectionSortWidget(ui->tabWidget, controller->getSelectionSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(ssWidget ,QString("SelectionSort"));

    QWidget* qsWidget = new QuickSortWidget(ui->tabWidget, controller->getQuickSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(qsWidget ,QString("QuickSort"));

    QWidget* msWidget = new MergeSortWidget(ui->tabWidget, controller->getMergeSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(msWidget ,QString("MergeSort"));

    QWidget* hsWidget = new EmptySortWidget(ui->tabWidget, controller->getHeapSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(hsWidget ,QString("HeapSort"));

    QWidget* bucksWidget = new EmptySortWidget(ui->tabWidget, controller->getBucketSortCtrl(),startTuple,numbOfValues);
    ui->tabWidget->addTab(bucksWidget ,QString("BucketSort"));
}
