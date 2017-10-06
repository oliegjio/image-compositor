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
        void resetButtonClicked();

        void bigSearchReturnPressed();
        void bigSearchButtonClicked();
        void bigApplyButtonClicked();

        void bottomSearchReturnPressed();

        void topSearchReturnPressed();
        void topSearchButtonClicked();
        void topApplyButtonClicked();
        
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
        
        QPushButton *topSearchButton;
        QPushButton *topApplyButton;
        QLineEdit *topSearch;
        QHBoxLayout *topSearchLayout;

        QPushButton *bottomApplyButton;
        QPushButton *bottomSearchButton;
        QLineEdit *bottomSearch;
        QHBoxLayout *bottomSearchLayout;

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
