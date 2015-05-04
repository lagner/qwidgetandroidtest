#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QStyledItemDelegate>


class ItemDelegate : public QStyledItemDelegate
{
public:
    explicit ItemDelegate(QObject* parent = nullptr);

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
};

#endif // ITEMDELEGATE_H
