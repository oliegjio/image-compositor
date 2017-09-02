#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow();
    window->setFixedSize(800, 600);
    window->setWindowTitle("Image Finder");
    window->show();

    return app.exec();
}
