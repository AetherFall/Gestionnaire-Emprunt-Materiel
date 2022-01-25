#include "ModelItemCustom.h"
#include <QImage>
#include <QRect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QLabel>

ModelItemCustom::ModelItemCustom(QObject *parent) : QAbstractItemModel(parent) {
    mModel.append({"CB#01", QRect(0,0,20,20), QImage(".\\res\\images\\radio.png"), "William Lambert"});
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

    return mModel->items().size();
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

    if(role == Qt::DecorationRole || role == Qt::UserRole){
        ElementsForm
    }

    return QVariant();
}
