#include "MainWindow.h"

MainWindow::MainWindow() 
{
    // #####
    // ## Initialize Values:
    // #####

    topCurrentDirectory = QDir("./");
    bottomCurrentDirectory = QDir("./");
    centralCurrentDirectory = QDir("./");

    extensions = QRegExp("^.*\.(jpg|png)$");
    extensions.setCaseSensitivity(Qt::CaseInsensitive);

    centralImagePath = QString("./image.jpg");

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
    // ## Top Images Controls:
    // #####

    topApplyButton = new QPushButton("Apply");
    topControlsLayout->addWidget(topApplyButton);
    connect(topApplyButton, SIGNAL(clicked()), this, SLOT(handleTopButtonAndSearch()));

    topSearchButton = new QPushButton("Search");
    topControlsLayout->addWidget(topSearchButton);
    connect(topSearchButton, SIGNAL(clicked()), this, SLOT(topSearchButtonClicked()));

    topSearch = new QLineEdit();
    topControlsLayout->addWidget(topSearch);
    connect(topSearch, SIGNAL(returnPressed()), this, SLOT(handleTopButtonAndSearch()));

    // #####
    // ## Bottom Images Controls:
    // #####

    bottomSearch = new QLineEdit();
    topControlsLayout->addWidget(bottomSearch);
    connect(bottomSearch, SIGNAL(returnPressed()), this, SLOT(handleBottomButtonAndSearch()));

    bottomApplyButton = new QPushButton("Apply");
    topControlsLayout->addWidget(bottomApplyButton);
    connect(bottomApplyButton, SIGNAL(clicked()), this, SLOT(handleBottomButtonAndSearch()));

    bottomSearchButton = new QPushButton("Search");
    topControlsLayout->addWidget(bottomSearchButton);
    connect(bottomSearchButton, SIGNAL(clicked()), this, SLOT(bottomSearchButtonClicked()));

    // #####
    // ## Central Image Controls:
    // #####

    centralApplyButton = new QPushButton("Apply");
    bottomControlsLayout->addWidget(centralApplyButton);
    connect(centralApplyButton, SIGNAL(clicked()), this, SLOT(handleCentralButtonAndSearch()));

    centralSearchButton = new QPushButton("Search");
    bottomControlsLayout->addWidget(centralSearchButton);
    connect(centralSearchButton, SIGNAL(clicked()), this, SLOT(centralSearchButtonClicked()));

    centralSearch = new QLineEdit();
    bottomControlsLayout->addWidget(centralSearch);
    connect(centralSearch, SIGNAL(returnPressed()), this, SLOT(handleCentralButtonAndSearch()));

    resetButton = new QPushButton("Reset");
    bottomControlsLayout->addWidget(resetButton);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));

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
    QPixmap image(centralImagePath);

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
// Top Images Controls:
// ========================================

void MainWindow::handleTopButtonAndSearch()
{
    QString path = searchImage(topCurrentDirectory, topSearch->text());
    if (path != "") imageToTopImagesLayout(path);
}

void MainWindow::topSearchButtonClicked()
{
    topCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

void MainWindow::imageToTopImagesLayout(QString path)
{
    if (path.isEmpty()) return;

    CentralImage* image = newImage(path);

    topImagesLayout->addWidget(image, 0, Qt::AlignLeft);

    topImagesLayout->removeItem(spacertopImagesLayout);
    topImagesLayout->insertItem(1000, spacertopImagesLayout);
}

// ========================================
// Bottom Images Controls:
// ========================================

void MainWindow::handleBottomButtonAndSearch()
{
    QString path = searchImage(bottomCurrentDirectory, bottomSearch->text());
    if (path != "") imageToBottomImagesLayout(path);
}

void MainWindow::bottomSearchButtonClicked()
{
    bottomCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

void MainWindow::imageToBottomImagesLayout(QString path)
{
    if (path.isEmpty()) return;

    CentralImage* image = newImage(path);
    bottomImagesLayout->addWidget(image, 0, Qt::AlignRight);
}

// ========================================
// Central Image Controls:
// ========================================

void MainWindow::centralSearchButtonClicked()
{
    centralCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

void MainWindow::handleCentralButtonAndSearch()
{
    QString path = searchImage(centralCurrentDirectory, centralSearch->text());
    if (path != "")
    {
        centralImagePath = path;
        repaint();
    }
}

void MainWindow::resetButtonClicked()
{
    while (QLayoutItem *item = topImagesLayout->takeAt(0))
        delete item->widget();
    while (QLayoutItem *item = bottomImagesLayout->takeAt(0))
        delete item->widget();

    addSpacerItems();
}
