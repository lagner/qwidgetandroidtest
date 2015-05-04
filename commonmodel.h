#ifndef COMMONMODEL_H
#define COMMONMODEL_H

#include <QAbstractItemModel>


class CommonModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum class Roles {
        BACKGROUND = Qt::UserRole + 1
    };

public:
    explicit CommonModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QModelIndex index(int row, int col, const QModelIndex& parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& index) const;

signals:
public slots:
private:
    QStringList simplemodel;
};

#endif // COMMONMODEL_H
