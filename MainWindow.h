#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralImage.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QLineEdit>
#include <QFileDialog>
#include <QResizeEvent>
#include <QHBoxLayout>
#include <QFrame>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>
#include <iostream>

class CentralImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots:
        void handleBigSearchReturn();
        void handleSearchButtonBig();
        void handleApplyButtonBig();
    private:
        QPushButton *resetButton;
        QString bigImagePath;
        QPushButton *searchButtonBig;
        QPushButton *applyButtonBig;
        QPushButton *searchButtonSmall;
        QPushButton *applyButtonSmall;
        QSize *initialSize;
        QWidget *interfaceArea;
        QVBoxLayout *mainLayout;
        QHBoxLayout *bottomLayout;
        QLabel *bigImage;
        CentralImage *smallImage;
        QLineEdit *bigSearch;
        QLineEdit *smallSearch;
    public:
        QHBoxLayout *centralLayout;
        MainWindow();
    protected:
        void paintEvent(QPaintEvent *event);
};

#endif
