#include "MainWindow.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QPlainTextEdit>

MainWindow::MainWindow()
{
    QWidget *interfaceArea = new QWidget; 
    setCentralWidget(interfaceArea);

    QGridLayout *mainLayout = new QGridLayout;

    QLabel *bigImage = new QLabel;
    bigImage->setPixmap(QPixmap("image.jpg"));
    mainLayout->addWidget(bigImage, 0, 0, 1, 0);

    QPlainTextEdit *bigSearch = new QPlainTextEdit;
    mainLayout->addWidget(bigSearch, 1, 0);

    QPlainTextEdit *smallSearch = new QPlainTextEdit;
    mainLayout->addWidget(smallSearch, 1, 1);

    interfaceArea->setLayout(mainLayout);
};
