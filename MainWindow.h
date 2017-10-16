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

        void centralSearchReturnPressed();
        void centralSearchButtonClicked();
        void centralApplyButtonClicked();

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
        QPushButton *centralSearchButton;
        QPushButton *centralApplyButton;
        QString bigImagePath;
        QLabel *bigImage;
        QLineEdit *centralSearch;

        QSpacerItem *spacertopImagesLayout;
        QSpacerItem *spacercontrolsWrapperLayout;
        void addSpacerItems();
        
        QPushButton *topSearchButton;
        QPushButton *topApplyButton;
        QLineEdit *topSearch;
        QHBoxLayout *topControlsLayout;
        QDir topCurrentDirectory;

        QPushButton *bottomApplyButton;
        QPushButton *bottomSearchButton;
        QLineEdit *bottomSearch;
        QHBoxLayout *bottomControlsLayout;
        QDir bottomCurrentDirectory;

        CentralImage* newImage(QString path);
        QString searchImage(QDir directory, QString name);
        void imageTobottomImagesLayout(QString path);
        void imageTotopImagesLayout(QString path);

        CentralImage *smallImage;
        
    public:
        QHBoxLayout *topImagesLayout;
        QHBoxLayout *bottomImagesLayout;
        QVBoxLayout *controlsWrapperLayout;
        MainWindow();
        
    protected:
        void paintEvent(QPaintEvent *event);
};

#endif
