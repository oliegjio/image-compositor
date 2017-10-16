#include "CentralImage.h"

CentralImage::CentralImage(MainWindow *parent)
{
    father = parent;

    QPushButton *closeButton = new QPushButton("X", this);

    QFont font = closeButton->font();
    font.setPointSize(8);

    closeButton->setFont(font);
    closeButton->setFixedWidth(20);
    closeButton->setFixedHeight(20);
    closeButton->move(0, 0);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeButtonClicked()));
}

void CentralImage::closeButtonClicked()
{
    father->topImagesLayout->removeWidget(this);
    delete this;
}

void CentralImage::mousePressEvent(QMouseEvent *event)
{
    raise();
}
