#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CentralImage.h"
#include "TopControlsLayout.h"
#include "Helpers.h"
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

    void centralSearchButtonClicked();
    void handleCentralButtonAndSearch();

    void bottomSearchButtonClicked();
    void handleBottomButtonAndSearch();

    void topSearchButtonClicked();
    void handleTopButtonAndSearch();

private:
    QSize *initialSize;
    QWidget *interfaceArea;

    QRegExp extensions;

    QVBoxLayout *mainLayout;

    QPushButton *resetButton;
    QPushButton *centralSearchButton;
    QPushButton *centralApplyButton;
    QLabel *centralImage;
    QLineEdit *centralSearch;
    QString centralImagePath;
    QDir centralCurrentDirectory;

    QSpacerItem *spacerTopImagesLayout;
    QSpacerItem *spacerControlsWrapperLayout;
    void addSpacerItems();

//    QPushButton *topSearchButton;
//    QPushButton *topApplyButton;
//    QLineEdit *topSearch;
    QHBoxLayout *topControlsLayout;
//    QDir topCurrentDirectory;

    QPushButton *bottomApplyButton;
    QPushButton *bottomSearchButton;
    QLineEdit *bottomSearch;
    QHBoxLayout *bottomControlsLayout;
    QDir bottomCurrentDirectory;

//    CentralImage* newImage(QString path);
//    QString searchImage(QDir directory, QString name);
    void imageToBottomImagesLayout(QString path);
//    void imageToTopImagesLayout(QString path);

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
