#include "commonmodel.h"
#include <QDebug>

CommonModel::CommonModel(QObject *parent) : QAbstractItemModel(parent)
{
    simplemodel
            << "assassin-s-creed-iv-black-flag-video-game-poster.jpg"
            << "league-of-legends.jpg"
            << "batman-origins-joker-bats.jpg"
            << "the-last-of-us.jpg"
            << "battlefield-4-cover.jpg"
            << "watch-dogs-aiden-video-game-poster.jpg"
            << "call-of-duty-black-ops-2-stealth-video-game-poster.jpg";

    simplemodel.append(simplemodel);
    simplemodel.append(simplemodel);
}


QHash<int, QByteArray> CommonModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert((int)Roles::BACKGROUND, QByteArray("backgroundImage"));

    return roles;
}


int CommonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return simplemodel.size();
}


int CommonModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}


QVariant CommonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() > simplemodel.size() || index.column() > 1)
        return QVariant();

    if (role == Qt::DisplayRole) {
        return simplemodel.at(index.row());

    } else if (role == (int)Roles::BACKGROUND) {
        QString filename = QStringLiteral("resources/") + simplemodel[index.row()];
#ifdef Q_OS_ANDROID
        filename = QStringLiteral("assets:/") + filename;
#endif
        return filename;
    }

    return QVariant();
}


QModelIndex CommonModel::index(int row, int col, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    if (col < 2 && row < int(simplemodel.size())) {
        return createIndex(row, col);
    }

    return QModelIndex();
}


QModelIndex CommonModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}
