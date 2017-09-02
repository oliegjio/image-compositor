#include "MainWindow.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QString>

MainWindow::MainWindow()
{

    QLabel* label = new QLabel(QString("Text"));
    setCentralWidget(label);

}
