#ifndef TOPCONTROLSLAYOUT_H
#define TOPCONTROLSLAYOUT_H

#include "CentralImage.h"
#include "Helpers.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDir>

class TopControlsLayout : public QHBoxLayout
{
    Q_OBJECT

public slots:
    void handleTopButtonAndSearch();
    void topSearchButtonClicked();

public:
    TopControlsLayout();

private:
    QPushButton *topApplyButton;
    QPushButton *topSearchButton;
    QLineEdit *topSearch;
    QDir topCurrentDirectory;

    QSpacerItem* spacer;

    void imageToTopImagesLayout(QString path);
};

#endif // TOPCONTROLSLAYOUT_H
