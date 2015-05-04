#include "customitem.h"
#include <QLabel>
#include <QPalette>
#include <QBrush>
#include <QGridLayout>
#include <QPixmapCache>
#include <QResizeEvent>
#include <QPushButton>
#include <QDebug>
#include <QIcon>


CustomItem::CustomItem(const QString &path) : filepath(path)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);

    initBackgroundImage();

    auto lout = new QGridLayout(this);
    lout->setColumnMinimumWidth(0, 300);
    lout->setColumnStretch(0, 100);
    lout->setColumnStretch(1, 1);
    lout->setRowStretch(0, 1);
    lout->setRowStretch(1, 100);

    setLayout(lout);

    title = new QLabel(this);
    title->setText("<H1>Title text</H1>");
    title->setStyleSheet("QLabel { color : white; }");

    lout->addWidget(title, 0, 0, 1, 2);

    label = new QLabel(this);
    QString text("Usually it is the other way around, an icon is supposed to provide different resolutions. But to do what you want you need to find the closest size supported by the icon, given an initial size as reference.");
    for (int i = 0; i < 4; ++i) {
        text += filepath + " ";
    }

    label->setText(text);
    label->setStyleSheet("QLabel { color: white; qproperty-alignment: AlignTop; qproperty-wordWrap: true;}");

    lout->addWidget(label, 1, 0, 1, 1);

    QPixmap buyIcon("://assets/cart.png");

    buy = new QPushButton(this);
    buy->setText("  Add to Cart");
    buy->setIcon(buyIcon);
    buy->setIconSize(buyIcon.size());

    lout->addWidget(buy, 2, 2, 1, 1);
}


QSize CustomItem::sizeHint() const
{
    return QSize(300, 300);
}


void CustomItem::initBackgroundImage()
{
    if (!filepath.isEmpty()) {
        if (backgroundOriginal.isNull())
            backgroundOriginal.load(filepath);

        QSize s = size();
        auto image = backgroundOriginal.scaled(s, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        setPixmap(QPixmap::fromImage(image));
    }
}


void CustomItem::resizeEvent(QResizeEvent * event)
{
    QWidget::resizeEvent(event);
    initBackgroundImage();
}
