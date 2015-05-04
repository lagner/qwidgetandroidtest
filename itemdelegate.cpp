#include <QStyleOptionViewItem>
#include <QPainter>
#include <QDebug>
#include <QPixmapCache>
#include <QImage>
#include <QPixmap>
#include <QFont>
#include <QGradient>
#include <QLinearGradient>
#include <QBrush>
#include "itemdelegate.h"
#include "commonmodel.h"


ItemDelegate::ItemDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
}


QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);

    auto size = option.rect.size();
    size.rheight() = 400;
    return size;
}


void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QString filename = index.data((int)CommonModel::Roles::BACKGROUND).toString();
    QPixmap background;

    if (!QPixmapCache::find(filename, background)) {
        QImage image(filename);

        auto simage = image.scaled(option.rect.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        background = QPixmap::fromImage(simage);

        QPixmapCache::insert(filename, background);
    }

    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.size().width();
    int h = option.rect.size().height();

    auto font = painter->font();
    font.setPointSize(14);
    font.setBold(true);

    QLinearGradient grad(QPointF(x, y), QPointF(x, y+h * 0.15));
    grad.setColorAt(0, Qt::black);
    grad.setColorAt(1, QColor(255, 255, 255, 0));

    QBrush brush(grad);

    QPen pen;
    pen.setWidth(0);
    pen.setColor(QColor(0, 0, 0, 0));

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setClipRect(option.rect);
    painter->setClipping(true);

    painter->drawPixmap(x, y, background);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(x, y, x+w, y+h*0.15);

    painter->setPen(Qt::white);
    painter->setFont(font);
    painter->drawText(QPoint(x + 10, y + 30), index.data((int)CommonModel::Roles::BACKGROUND).toString());
    painter->restore();
}



