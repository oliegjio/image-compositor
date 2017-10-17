#include "Helpers.h"

QString Helpers::searchImage(QDir directory, QString name)
{
    QStringList files = directory.entryList();

    QRegExp extensions("^.*\.(jpg|png)$");
    extensions.setCaseSensitivity(Qt::CaseInsensitive);

    QList<QString>::Iterator i;
    for (i = files.begin(); i != files.end(); ++i)
    {
        if (extensions.exactMatch(*i) && (*i).left((*i).length() - 4) == name)
        {
            return directory.absoluteFilePath(*i);
        }
    }

    return QString("");
}

CentralImage* Helpers::newImage(QWidget parent, QString path)
{
    CentralImage* image = new CentralImage(parent);
    image->setPixmap(QPixmap(path));
    image->setAlignment(Qt::AlignCenter);
    image->setFixedSize(280, 280);
    image->setScaledContents(true);
    return image;
}
