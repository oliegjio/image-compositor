#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        QSize *initialSize;
        QWidget *interfaceArea;
        QGridLayout *mainLayout;
        QLabel *bigImage;
        QLabel *smallImage;
        QPlainTextEdit *bigSearch;
        QPlainTextEdit *smallSearch;
    public:
        MainWindow();
    protected:
        void resizeEvent(QResizeEvent *event);
};

#endif
