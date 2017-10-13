#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow();
    window->setWindowTitle("Image Compositor");
    window->show();

    return app.exec();
}
