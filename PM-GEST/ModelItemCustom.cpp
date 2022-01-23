#include "ModelItemCustom.h"
#include <QImage>
#include <QRect>

ModelItemCustom::ModelItemCustom(QString name, QImage image, QRect roundPatch, QObject *parent) : QAbstractItemModel(parent) {
    this->image = image
}

QVariant ModelItemCustom::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QModelIndex ModelItemCustom::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

QModelIndex ModelItemCustom::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int ModelItemCustom::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
    return 0;
}

int ModelItemCustom::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return 0;
}

QVariant ModelItemCustom::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
