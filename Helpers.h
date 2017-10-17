#ifndef HELPERS_H
#define HELPERS_H

#include "CentralImage.h"
#include <QString>
#include <QDir>
#include <QRegExp>

class CentralImage;

class Helpers
{
public:
    static QString searchImage(QDir directory, QString name);
    CentralImage* newImage(QWidget parent, QString path);
};

#endif // HELPERS_H
