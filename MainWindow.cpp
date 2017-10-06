#include "MainWindow.h"

MainWindow::MainWindow() 
{
    bigImagePath = QString("./image.jpg");

    initialSize = new QSize(1200, 700);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget(); 
    setCentralWidget(interfaceArea);

    mainLayout = new QVBoxLayout();

    topLayout = new QHBoxLayout();
    mainLayout->addLayout(topLayout);
    topLayout->setMargin(20);
    
    mainLayout->addStretch(1000);

    middleLayout = new QHBoxLayout();
    mainLayout->addLayout(middleLayout);
    middleLayout->setMargin(20);

    addSpacerItems();

    mainLayout->addStretch(1);

    bottomLayout = new QVBoxLayout();
    mainLayout->addLayout(bottomLayout);
    
    topSearchLayout = new QHBoxLayout();
    bottomLayout->addLayout(topSearchLayout);

    bottomSearchLayout = new QHBoxLayout();
    bottomLayout->addLayout(bottomSearchLayout);

    bigSearchButton = new QPushButton("Search");
    bottomSearchLayout->addWidget(bigSearchButton);
    connect(bigSearchButton, SIGNAL(clicked()), this, SLOT(bigSearchButtonClicked()));

    bigApplyButton = new QPushButton("Apply");
    bottomSearchLayout->addWidget(bigApplyButton);
    connect(bigApplyButton, SIGNAL(clicked()), this, SLOT(bigApplyButtonClicked()));
    
    bigSearch = new QLineEdit();
    bottomSearchLayout->addWidget(bigSearch);
    connect(bigSearch, SIGNAL(returnPressed()), this, SLOT(bigSearchReturnPressed()));

    resetButton = new QPushButton("Reset");
    bottomSearchLayout->addWidget(resetButton);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));

    topApplyButton = new QPushButton("Apply");
    topSearchLayout->addWidget(topApplyButton);
    connect(topApplyButton, SIGNAL(clicked()), this, SLOT(topApplyButtonClicked()));

    topSearchButton = new QPushButton("Search");
    topSearchLayout->addWidget(topSearchButton);
    connect(topSearchButton, SIGNAL(clicked()), this, SLOT(topSearchButtonClicked()));

    topSearch = new QLineEdit();
    topSearchLayout->addWidget(topSearch);
    connect(topSearch, SIGNAL(returnPressed()), this, SLOT(topSearchReturnPressed()));

    bottomSearch = new QLineEdit();
    topSearchLayout->addWidget(bottomSearch);
    connect(bottomSearch, SIGNAL(returnPressed()), this, SLOT(bottomSearchReturnPressed()));

    bottomApplyButton = new QPushButton("Apply");
    topSearchLayout->addWidget(bottomApplyButton);
    // connect(bottomApplyButton, SIGNAL(clicked()), this, SLOT(bottomApplyButtonClicked()));

    bottomSearchButton = new QPushButton("Search");
    topSearchLayout->addWidget(bottomSearchButton);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    interfaceArea->setLayout(mainLayout);
};

void MainWindow::addSpacerItems()
{
    spacerTopLayout = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    topLayout->addSpacerItem(spacerTopLayout);
    spacerMiddleLayout = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    middleLayout->addSpacerItem(spacerMiddleLayout);
}

void MainWindow::bigSearchButtonClicked()
{
    bigImagePath = QFileDialog::getOpenFileName();
    bigSearch->setText(bigImagePath);
    repaint();
}

void MainWindow::bigApplyButtonClicked() 
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

void MainWindow::bigSearchReturnPressed()
{
    bigImagePath = bigSearch->text();
    repaint();
}

void MainWindow::resetButtonClicked()
{
    while (QLayoutItem *item = topLayout->takeAt(0))
        delete item->widget();
    while (QLayoutItem *item = middleLayout->takeAt(0))
        delete item->widget();

    addSpacerItems();
}

void MainWindow::imageToMiddleLayout(QString path)
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(bottomSearch->text()));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(280, 280);
    newImage->setMargin(20);
    middleLayout->addWidget(newImage, 0, Qt::AlignRight);
}

void MainWindow::imageToTopLayout(QString path)
{
    CentralImage *newImage = new CentralImage(this);
    newImage->setPixmap(QPixmap(path));
    newImage->setAlignment(Qt::AlignCenter);
    newImage->setFixedSize(280, 280);
    newImage->setMargin(20);
    topLayout->addWidget(newImage, 0, Qt::AlignLeft);

    topLayout->removeItem(spacerTopLayout);
    topLayout->insertItem(1000, spacerTopLayout);
}

void MainWindow::topSearchReturnPressed()
{
    imageToTopLayout(topSearch->text());
}

void MainWindow::topApplyButtonClicked()
{
    imageToTopLayout(topSearch->text());
}

void MainWindow::topSearchButtonClicked()
{
    QString imagePath = QFileDialog::getOpenFileName();
    imageToTopLayout(imagePath);
}

void MainWindow::bottomSearchReturnPressed()
{
    imageToMiddleLayout(bottomSearch->text());
}



