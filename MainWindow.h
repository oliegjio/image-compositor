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
#include <QDebug>
#include <QDirIterator>

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
        void bottomApplyButtonClicked();
        void bottomSearchButtonClicked();

        void topSearchButtonClicked();
        void topHandleButtonAndSearch();
        
    private:
        QSize *initialSize;
        QWidget *interfaceArea;

        QRegExp extensions;

        QVBoxLayout *mainLayout;

        QPushButton *resetButton;
        QPushButton *bigSearchButton;
        QPushButton *bigApplyButton;
        QString bigImagePath;
        QLabel *bigImage;
        QLineEdit *bigSearch;

        QSpacerItem *spacerTopLayout;
        QSpacerItem *spacerBottomLayout;
        void addSpacerItems();
        
        QPushButton *topSearchButton;
        QPushButton *topApplyButton;
        QLineEdit *topSearch;
        QHBoxLayout *topSearchLayout;
        QDir topCurrentDirectory;

        QPushButton *bottomApplyButton;
        QPushButton *bottomSearchButton;
        QLineEdit *bottomSearch;
        QHBoxLayout *bottomSearchLayout;

        CentralImage* newImage(QString path);
        QString searchImage(QDir directory, QString name);
        void imageToMiddleLayout(QString path);
        void imageToTopLayout(QString path);

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
