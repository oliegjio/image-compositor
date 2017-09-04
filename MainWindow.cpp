#include "MainWindow.h"

MainWindow::MainWindow() 
{
    bigImagePath = QString("./image.jpg");

    initialSize = new QSize(1200, 800);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget(); 
    setCentralWidget(interfaceArea);

    mainLayout = new QVBoxLayout();

    centralLayout = new QHBoxLayout();
    centralLayout->setSizeConstraint(QLayout::SetMinimumSize);
    mainLayout->addLayout(centralLayout);

    QWidget *empty = new QWidget();
    centralLayout->addWidget(empty);

    bottomLayout = new QHBoxLayout();
    mainLayout->addLayout(bottomLayout);

    searchButtonBig = new QPushButton("Search");
    bottomLayout->addWidget(searchButtonBig);
    connect(searchButtonBig, SIGNAL(clicked()), this, SLOT(handleSearchButtonBigClicked()));

    applyButtonBig = new QPushButton("Apply");
    bottomLayout->addWidget(applyButtonBig);
    connect(applyButtonBig, SIGNAL(clicked()), this, SLOT(handleApplyButtonBigClicked()));
    
    bigSearch = new QLineEdit();
    bottomLayout->addWidget(bigSearch);
    connect(bigSearch, SIGNAL(returnPressed()), this, SLOT(handleBigSearchReturnPressed()));

    resetButton = new QPushButton("Reset");
    bottomLayout->addWidget(resetButton);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(handleResetButtonClicked()));

    smallSearch = new QLineEdit();
    bottomLayout->addWidget(smallSearch);
    connect(smallSearch, SIGNAL(returnPressed()), this, SLOT(handleSmallSearchReturnPressed()));

    applyButtonSmall = new QPushButton("Apply");
    bottomLayout->addWidget(applyButtonSmall);
    connect(applyButtonSmall, SIGNAL(clicked()), this, SLOT(handleApplyButtonSmallClicked()));

    searchButtonSmall = new QPushButton("Search");
    bottomLayout->addWidget(searchButtonSmall);
    connect(searchButtonSmall, SIGNAL(clicked()), this, SLOT(handleSearchButtonSmallClicked()));

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    interfaceArea->setLayout(mainLayout);
};

void MainWindow::handleSearchButtonBigClicked()
{
    bigImagePath = QFileDialog::getOpenFileName();
    bigSearch->setText(bigImagePath);
    repaint();
}

void MainWindow::handleApplyButtonBigClicked() 
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

void MainWindow::handleBigSearchReturnPressed()
{
    bigImagePath = bigSearch->text();
    repaint();
}

void MainWindow::handleResetButtonClicked()
{
    while (QLayoutItem *item = centralLayout->takeAt(0))
        delete item->widget();

    QWidget *empty = new QWidget();
    centralLayout->addWidget(empty);
}

void MainWindow::handleSmallSearchReturnPressed()
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(smallSearch->text()));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(300, 300);
    centralLayout->addWidget(newImage, 1, Qt::AlignCenter);
}

void MainWindow::handleSearchButtonSmallClicked()
{
    QString imagePath = QFileDialog::getOpenFileName();

    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(imagePath));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(300, 300);
    centralLayout->addWidget(newImage, 1, Qt::AlignCenter);
}

void MainWindow::handleApplyButtonSmallClicked()
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(smallSearch->text()));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(300, 300);
    centralLayout->addWidget(newImage, 1, Qt::AlignCenter);
}
