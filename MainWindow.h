#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralImage.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QLineEdit>
#include <QFileDialog>
#include <QResizeEvent>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>

class CentralImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots:
        void handleResetButtonClicked();
        void handleBigSearchReturnPressed();
        void handleSearchButtonBigClicked();
        void handleApplyButtonBigClicked();
        void handleSmallTopSearchReturnPressed();
        void handleSmallBottomSearchReturnPressed();
        void handleSmallTopSearchButtonClicked();
        void handleSmallTopApplyButtonClicked();
    private:
        QPushButton *resetButton;
        QString bigImagePath;
        QPushButton *searchButtonBig;
        QPushButton *applyButtonBig;
        QPushButton *smallTopSearchButton;
        QPushButton *smallTopApplyButton;
        QPushButton *smallBottomApplyButton;
        QPushButton *smallBottomSearchButton;
        QSpacerItem *spacerTopLayout;
        QSpacerItem *spacerMiddleLayout;
        QSize *initialSize;
        QWidget *interfaceArea;
        QVBoxLayout *mainLayout;
        QHBoxLayout *searchBottomLayout;
        QHBoxLayout *searchTopLayout;
        QLabel *bigImage;
        CentralImage *smallImage;
        QLineEdit *bigSearch;
        QLineEdit *smallTopSearch;
        QLineEdit *smallBottomSearch;
    public:
        QHBoxLayout *topLayout;
        QHBoxLayout *middleLayout;
        QVBoxLayout *bottomLayout;
        MainWindow();
    protected:
        void paintEvent(QPaintEvent *event);
};

#endif
