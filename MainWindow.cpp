#include "MainWindow.h"

MainWindow::MainWindow() 
{
    // #####
    // ## Initialize Values:
    // #####

    extensions = QRegExp("^.*\.(jpg|png)$");
    extensions.setCaseSensitivity(Qt::CaseInsensitive);

    bigImagePath = QString("./image.jpg");

    initialSize = new QSize(1200, 700);
    setFixedSize(*initialSize);

    interfaceArea = new QWidget(); 
    setCentralWidget(interfaceArea);

    // #####
    // ## Setup Layouts:
    // #####

    mainLayout = new QVBoxLayout();

    topImagesLayout = new QHBoxLayout();
    mainLayout->addLayout(topImagesLayout);
    
    mainLayout->addStretch(1000);

    bottomImagesLayout = new QHBoxLayout();
    mainLayout->addLayout(bottomImagesLayout);

    addSpacerItems();

    mainLayout->addStretch(1);

    controlsWrapperLayout = new QVBoxLayout();
    mainLayout->addLayout(controlsWrapperLayout);
    
    topControlsLayout = new QHBoxLayout();
    controlsWrapperLayout->addLayout(topControlsLayout);

    bottomControlsLayout = new QHBoxLayout();
    controlsWrapperLayout->addLayout(bottomControlsLayout);

    // #####
    // ## Bottom Layout:
    // #####

    centralSearchButton = new QPushButton("Search");
    bottomControlsLayout->addWidget(centralSearchButton);
    connect(centralSearchButton, SIGNAL(clicked()), this, SLOT(centralSearchButtonClicked()));

    centralApplyButton = new QPushButton("Apply");
    bottomControlsLayout->addWidget(centralApplyButton);
    connect(centralApplyButton, SIGNAL(clicked()), this, SLOT(centralApplyButtonClicked()));
    
    centralSearch = new QLineEdit();
    bottomControlsLayout->addWidget(centralSearch);
    connect(centralSearch, SIGNAL(returnPressed()), this, SLOT(centralSearchReturnPressed()));

    resetButton = new QPushButton("Reset");
    bottomControlsLayout->addWidget(resetButton);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));

    // #####
    // ## Top Search Layout:
    // #####

    topApplyButton = new QPushButton("Apply");
    topControlsLayout->addWidget(topApplyButton);
    connect(topApplyButton, SIGNAL(clicked()), this, SLOT(topHandleButtonAndSearch()));

    topSearchButton = new QPushButton("Search");
    topControlsLayout->addWidget(topSearchButton);
    connect(topSearchButton, SIGNAL(clicked()), this, SLOT(topSearchButtonClicked()));

    topSearch = new QLineEdit();
    topControlsLayout->addWidget(topSearch);
    connect(topSearch, SIGNAL(returnPressed()), this, SLOT(topHandleButtonAndSearch()));

    // #####
    // ## Bottom Search Layout:
    // #####

    bottomSearch = new QLineEdit();
    topControlsLayout->addWidget(bottomSearch);
    connect(bottomSearch, SIGNAL(returnPressed()), this, SLOT(bottomSearchReturnPressed()));

    bottomApplyButton = new QPushButton("Apply");
    topControlsLayout->addWidget(bottomApplyButton);
    connect(bottomApplyButton, SIGNAL(clicked()), this, SLOT(bottomApplyButtonClicked()));

    bottomSearchButton = new QPushButton("Search");
    topControlsLayout->addWidget(bottomSearchButton);
    connect(bottomSearchButton, SIGNAL(clicked()), this, SLOT(bottomSearchButtonClicked()));

    // #####
    // ## Other:
    // #####

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    interfaceArea->setLayout(mainLayout);
};

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap image(bigImagePath);

    float x = -(image.width() - width()) / 2;
    float y = -(image.height() - height()) / 2;

    painter.drawPixmap(x, y, image);
}

// ========================================
// Other:
// ========================================

void MainWindow::addSpacerItems()
{
    spacertopImagesLayout = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    topImagesLayout->addSpacerItem(spacertopImagesLayout);
    spacercontrolsWrapperLayout = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    bottomImagesLayout->addSpacerItem(spacercontrolsWrapperLayout);
}

CentralImage* MainWindow::newImage(QString path)
{
    CentralImage* image = new CentralImage(this);
    image->setPixmap(QPixmap(path));
    image->setAlignment(Qt::AlignCenter);
    image->setFixedSize(280, 280);
    return image;
}

QString MainWindow::searchImage(QDir directory, QString name)
{
    QStringList files = directory.entryList();

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

// ========================================
// Top Search Layout:
// ========================================

void MainWindow::topHandleButtonAndSearch()
{
    QString path = searchImage(topCurrentDirectory, topSearch->text());
    if (path != "") imageTotopImagesLayout(path);
}

void MainWindow::topSearchButtonClicked()
{
    topCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

void MainWindow::imageTotopImagesLayout(QString path)
{
    if (path.isEmpty()) return;

    CentralImage* image = newImage(path);

    topImagesLayout->addWidget(image, 0, Qt::AlignLeft);

    topImagesLayout->removeItem(spacertopImagesLayout);
    topImagesLayout->insertItem(1000, spacertopImagesLayout);
}

// ========================================
// Middle Search Layout:
// ========================================

void MainWindow::imageTobottomImagesLayout(QString path)
{
    if (path.isEmpty()) return;

    CentralImage* image = newImage(path);
    bottomImagesLayout->addWidget(image, 0, Qt::AlignRight);
}

void MainWindow::bottomSearchReturnPressed()
{
    imageTobottomImagesLayout(bottomSearch->text());
}

void MainWindow::bottomApplyButtonClicked()
{
    imageTobottomImagesLayout(bottomSearch->text());
}

void MainWindow::bottomSearchButtonClicked()
{
//    QString imagePath = QFileDialog::getOpenFileName();
//    imageTobottomImagesLayout(imagePath);
    bottomCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

// ========================================
// Bottom Layout:
// ========================================

void MainWindow::centralSearchButtonClicked()
{
    bigImagePath = QFileDialog::getOpenFileName();
    centralSearch->setText(bigImagePath);
    repaint();
}

void MainWindow::centralApplyButtonClicked()
{
    bigImagePath = centralSearch->text();
    repaint();
}

void MainWindow::centralSearchReturnPressed()
{
    bigImagePath = centralSearch->text();
    repaint();
}

void MainWindow::resetButtonClicked()
{
    while (QLayoutItem *item = topImagesLayout->takeAt(0))
        delete item->widget();
    while (QLayoutItem *item = bottomImagesLayout->takeAt(0))
        delete item->widget();

    addSpacerItems();
}
