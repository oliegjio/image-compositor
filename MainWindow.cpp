#include "MainWindow.h"

MainWindow::MainWindow() 
{
    bigImagePath = QString("./image.jpg");

    initialSize = new QSize(1200, 700);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget(); 
    setCentralWidget(interfaceArea);

    mainLayout = new QVBoxLayout();

    mainLayout->addStretch(1);
    
    topLayout = new QHBoxLayout();
    mainLayout->addLayout(topLayout);
    topLayout->setMargin(20);

    mainLayout->addStretch(1);

    middleLayout = new QHBoxLayout();
    mainLayout->addLayout(middleLayout);
    middleLayout->setMargin(20);

    mainLayout->addStretch(1);

    bottomLayout = new QVBoxLayout();
    mainLayout->addLayout(bottomLayout);
    
    searchTopLayout = new QHBoxLayout();
    bottomLayout->addLayout(searchTopLayout);

    searchBottomLayout = new QHBoxLayout();
    bottomLayout->addLayout(searchBottomLayout);

    searchButtonBig = new QPushButton("Search");
    searchBottomLayout->addWidget(searchButtonBig);
    connect(searchButtonBig, SIGNAL(clicked()), this, SLOT(handleSearchButtonBigClicked()));

    applyButtonBig = new QPushButton("Apply");
    searchBottomLayout->addWidget(applyButtonBig);
    connect(applyButtonBig, SIGNAL(clicked()), this, SLOT(handleApplyButtonBigClicked()));
    
    bigSearch = new QLineEdit();
    searchBottomLayout->addWidget(bigSearch);
    connect(bigSearch, SIGNAL(returnPressed()), this, SLOT(handleBigSearchReturnPressed()));

    resetButton = new QPushButton("Reset");
    searchBottomLayout->addWidget(resetButton);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(handleResetButtonClicked()));

    smallBottomApplyButton = new QPushButton("Apply");
    searchTopLayout->addWidget(smallBottomApplyButton);
    // connect(smallBottomApplyButton, SIGNAL(clicked()), this, SLOT(handleSmallTopApplyButtonClicked()));

    smallBottomSearchButton = new QPushButton("Search");
    searchTopLayout->addWidget(smallBottomSearchButton);
    // connect(smallBottomSearchButton, SIGNAL(clicked()), this, SLOT(handleSmallTopSearchButtonClicked()));

    smallBottomSearch = new QLineEdit();
    searchTopLayout->addWidget(smallBottomSearch);
    connect(smallBottomSearch, SIGNAL(returnPressed()), this, SLOT(handleSmallBottomSearchReturnPressed()));

    smallTopSearch = new QLineEdit();
    searchTopLayout->addWidget(smallTopSearch);
    connect(smallTopSearch, SIGNAL(returnPressed()), this, SLOT(handleSmallTopSearchReturnPressed()));

    smallTopApplyButton = new QPushButton("Apply");
    searchTopLayout->addWidget(smallTopApplyButton);
    connect(smallTopApplyButton, SIGNAL(clicked()), this, SLOT(handleSmallTopApplyButtonClicked()));

    smallTopSearchButton = new QPushButton("Search");
    searchTopLayout->addWidget(smallTopSearchButton);
    connect(smallTopSearchButton, SIGNAL(clicked()), this, SLOT(handleSmallTopSearchButtonClicked()));

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
    while (QLayoutItem *item = topLayout->takeAt(0))
        delete item->widget();
    while (QLayoutItem *item = middleLayout->takeAt(0))
        delete item->widget();

    // QWidget *empty = new QWidget();
    // imagesTopLayout->addWidget(empty);
}

void MainWindow::handleSmallTopSearchReturnPressed()
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(smallTopSearch->text()));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(200, 200);
    topLayout->addWidget(newImage, 1, Qt::AlignLeft);
}

void MainWindow::handleSmallBottomSearchReturnPressed()
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(smallBottomSearch->text()));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(200, 200);
    middleLayout->addWidget(newImage, 1, Qt::AlignRight);
}

void MainWindow::handleSmallTopSearchButtonClicked()
{
    QString imagePath = QFileDialog::getOpenFileName();

    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(imagePath));
    newImage->setAlignment(Qt::AlignLeft);
    newImage->setFixedSize(300, 300);
    topLayout->addWidget(newImage, 1, Qt::AlignLeft);
}

void MainWindow::handleSmallTopApplyButtonClicked()
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(smallTopSearch->text()));
    newImage->setAlignment(Qt::AlignLeft);
    newImage->setFixedSize(300, 300);
    topLayout->addWidget(newImage, 1, Qt::AlignLeft);
}

