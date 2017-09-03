#include "MainWindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow()
{
    initialSize = new QSize(1200, 800);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget; 
    setCentralWidget(interfaceArea);
    interfaceArea->show();

    mainLayout = new QGridLayout;

    QWidget *centralWidget = new QWidget;
    mainLayout->addWidget(centralWidget, 0, 0, 1, 0);

    bigImage = new QLabel(centralWidget);
    bigImage->setPixmap(QPixmap("image.jpg"));
    bigImage->setAlignment(Qt::AlignCenter);
    bigImage->setFixedSize(*initialSize);
    bigImage->show();

    smallImage = new QLabel(centralWidget);
    smallImage->setPixmap(QPixmap("image2.jpg"));
    smallImage->setAlignment(Qt::AlignCenter);
    smallImage->setFixedSize(300, 300);
    smallImage->show();
    
    bigSearch = new QPlainTextEdit;
    bigSearch->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    bigSearch->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    bigSearch->setFixedHeight(24);
    mainLayout->addWidget(bigSearch, 1, 0);
    bigSearch->show();

    smallSearch = new QPlainTextEdit;
    smallSearch->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    smallSearch->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    smallSearch->setFixedHeight(24);
    mainLayout->addWidget(smallSearch, 1, 1);
    smallSearch->show();

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    interfaceArea->setLayout(mainLayout);
};

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    bigImage->setFixedSize(size);

    int bigImageWidth = bigImage->width();
    int bigImageHeight = bigImage->height();

    int newSmallImageWidth = bigImageWidth / 4;
    int newSmallImageHeight = bigImageHeight / 4;
    smallImage->setFixedSize(newSmallImageWidth, newSmallImageHeight);

    int centerCoordinateX = (bigImageWidth / 2) - newSmallImageWidth / 2;
    int centerCoordinateY = (bigImageHeight / 2) - (newSmallImageHeight / 2);
    smallImage->move(centerCoordinateX, centerCoordinateY);
};
