#include "TopControlsLayout.h"

TopControlsLayout::TopControlsLayout()
{
    topCurrentDirectory = QDir("./");

    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    addSpacerItem(spacer);

    topApplyButton = new QPushButton("Apply");
    addWidget(topApplyButton);
    connect(topApplyButton, SIGNAL(clicked()), this, SLOT(handleTopButtonAndSearch()));

    topSearchButton = new QPushButton("Search");
    addWidget(topSearchButton);
    connect(topSearchButton, SIGNAL(clicked()), this, SLOT(topSearchButtonClicked()));

    topSearch = new QLineEdit();
    addWidget(topSearch);
    connect(topSearch, SIGNAL(returnPressed()), this, SLOT(handleTopButtonAndSearch()));
}

void TopControlsLayout::handleTopButtonAndSearch()
{
    QString path = Helpers().searchImage(topCurrentDirectory, topSearch->text());
    if (path != "") imageToTopImagesLayout(path);
}

void TopControlsLayout::topSearchButtonClicked()
{
    topCurrentDirectory = QDir(QFileDialog::getExistingDirectory());
}

void TopControlsLayout::imageToTopImagesLayout(QString path)
{
    if (path.isEmpty()) return;

    CentralImage* image = Helpers().newImage(this, path);

    addWidget(image, 0, Qt::AlignLeft);

    removeItem(spacer);
    insertItem(1000, spacer);
}
