#ifndef CENTRALIMAGE_H
#define CENTRALIMAGE_H

#include "MainWindow.h"
#include <QLabel>
#include <QPushButton>

class MainWindow;

class CentralImage : public QLabel
{
    Q_OBJECT

    public:
        CentralImage(MainWindow *parent);
    private:
        QPushButton *closeButton;
        MainWindow *father;
    private slots:
        void handleCloseButton();
    protected:
        void mousePressEvent(QMouseEvent *event);
};

#endif
