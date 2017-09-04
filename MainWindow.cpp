#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow() 
{
    bigImagePath = QString("./image.jpg");

    initialSize = new QSize(1200, 800);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget(); 
    setCentralWidget(interfaceArea);

    mainLayout = new QVBoxLayout();

    centralLayout = new QHBoxLayout();
    mainLayout->addLayout(centralLayout);

    QWidget *empty = new QWidget();
    centralLayout->addWidget(empty);

    smallImage = new CentralImage(this);
    smallImage->setPixmap(QPixmap("image2.jpg"));
    smallImage->setAlignment(Qt::AlignCenter);
    smallImage->setFixedSize(300, 300);
    centralLayout->addWidget(smallImage, 1, Qt::AlignCenter);

    bottomLayout = new QHBoxLayout();
    mainLayout->addLayout(bottomLayout);

    searchButtonBig = new QPushButton("Search");
    bottomLayout->addWidget(searchButtonBig);
    connect(searchButtonBig, SIGNAL(clicked()), this, SLOT(handleSearchButtonBig()));

    applyButtonBig = new QPushButton("Apply");
    bottomLayout->addWidget(applyButtonBig);
    connect(applyButtonBig, SIGNAL(clicked()), this, SLOT(handleApplyButtonBig()));
    
    bigSearch = new QLineEdit();
    bottomLayout->addWidget(bigSearch);
    connect(bigSearch, SIGNAL(returnPressed()), this, SLOT(handleBigSearchReturn()));

    resetButton = new QPushButton("Reset");
    bottomLayout->addWidget(resetButton);

    smallSearch = new QLineEdit();
    bottomLayout->addWidget(smallSearch);

    applyButtonSmall = new QPushButton("Apply");
    bottomLayout->addWidget(applyButtonSmall);

    searchButtonSmall = new QPushButton("Search");
    bottomLayout->addWidget(searchButtonSmall);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    interfaceArea->setLayout(mainLayout);
};

void MainWindow::handleSearchButtonBig()
{
    bigImagePath = QFileDialog::getOpenFileName();
    bigSearch->setText(bigImagePath);
    repaint();
}

void MainWindow::handleApplyButtonBig() 
{
    bigImagePath = bigSearch->text();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap image(bigImagePath);
    float x = -(image.width() - width()) / 2;
    float y = -(image.height() - height()) / 2;
    painter.drawPixmap(x, y, image);
}

void MainWindow::handleBigSearchReturn()
{
    bigImagePath = bigSearch->text();
    repaint();
}
