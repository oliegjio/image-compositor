#ifndef CENTRALIMAGE_H
#define CENTRALIMAGE_H

#include <QLabel>
#include <QPushButton>
#include "MainWindow.h"

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
};

#endif
