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
        void handleBigSearchButtonClicked();
        void handleBigApplyButtonClicked();

        void handleSmallBottomSearchReturnPressed();

        void handleSmallTopSearchReturnPressed();
        void handleSmallTopSearchButtonClicked();
        void handleSmallTopApplyButtonClicked();
    private:
        QSize *initialSize;
        QWidget *interfaceArea;

        QVBoxLayout *mainLayout;

        QPushButton *resetButton;
        QPushButton *bigSearchButton;
        QPushButton *bigApplyButton;
        QString bigImagePath;
        QLabel *bigImage;
        QLineEdit *bigSearch;

        QSpacerItem *spacerTopLayout;
        QSpacerItem *spacerMiddleLayout;
        void addSpacerItems();
        
        QPushButton *smallTopSearchButton;
        QPushButton *smallTopApplyButton;
        QLineEdit *smallTopSearch;
        QHBoxLayout *searchTopLayout;

        QPushButton *smallBottomApplyButton;
        QPushButton *smallBottomSearchButton;
        QLineEdit *smallBottomSearch;
        QHBoxLayout *searchBottomLayout;

        void imageToTopLayout(QString path);
        void imageToMiddleLayout(QString path);

        CentralImage *smallImage;
    public:
        QHBoxLayout *topLayout;
        QHBoxLayout *middleLayout;
        QVBoxLayout *bottomLayout;
        MainWindow();
    protected:
        void paintEvent(QPaintEvent *event);
};

#endif
