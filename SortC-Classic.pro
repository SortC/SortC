#-------------------------------------------------
#
# Project created by QtCreator 2014-06-13T10:44:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SortC-Classic
TEMPLATE = app


SOURCES += main.cpp\
    view/SortView.cpp \
    model/Algorithm.cpp \
    model/BubbleSort.cpp \
    model/BucketSort.cpp \
    model/HeapSort.cpp \
    model/InsertionSort.cpp \
    model/MergeSort.cpp \
    model/QuickSort.cpp \
    model/SelectionSort.cpp \
    model/stdafx.cpp \
    model/Step.cpp \
    controller/Controller.cpp \
    controller/AlgorithmController.cpp \
    view/ConfiguratorView.cpp \
    view/BaseSortWidget.cpp \
    view/BubbleSortWidget.cpp \
    view/EmptySortWidget.cpp \
    view/SelectionSortwidget.cpp \
    view/InsertionSortWidget.cpp \
    view/MergeSortWidget.cpp \
    view/QuickSortWidget.cpp

HEADERS  += view/SortView.h \
    model/Algorithm.h \
    model/BubbleSort.h \
    model/BucketSort.h \
    model/HeapSort.h \
    model/InsertionSort.h \
    model/MergeSort.h \
    model/QuickSort.h \
    model/SelectionSort.h \
    model/stdafx.h \
    model/Step.h \
    model/targetver.h \
    controller/Controller.h \
    controller/AlgorithmController.h \
    view/ConfiguratorView.h \
    view/BaseSortWidget.h \
    view/BubbleSortWidget.h \
    view/EmptySortWidget.h \
    view/SelectionSortWidget.h \
    view/InsertionSortWidget.h \
    view/MergeSortWidget.h \
    view/QuickSortWidget.h

FORMS    += view/SortView.ui \
    view/ConfiguratorView.ui \
    view/BaseSortWidget.ui
