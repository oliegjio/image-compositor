#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private slots:
        void handleBigSearchReturn();
        void handleSearchButtonBig();
        void handleApplyButtonBig();
    private:
        QString bigImagePath;
        QPushButton *searchButtonBig;
        QPushButton *applyButtonBig;
        QPushButton *searchButtonSmall;
        QPushButton *applyButtonSmall;
        QSize *initialSize;
        QWidget *interfaceArea;
        QVBoxLayout *mainLayout;
        QHBoxLayout *centralLayout;
        QHBoxLayout *bottomLayout;
        QLabel *bigImage;
        QLabel *smallImage;
        QLineEdit *bigSearch;
        QLineEdit *smallSearch;
    public:
        MainWindow();
    protected:
        void paintEvent(QPaintEvent *event);
};

#endif
