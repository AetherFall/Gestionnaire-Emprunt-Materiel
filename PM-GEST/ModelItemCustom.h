#ifndef MODELITEMCUSTOM_H
#define MODELITEMCUSTOM_H

#include <QAbstractItemModel>

class ModelItemCustom : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ModelItemCustom(QString name, QImage image, QRect roundPatch, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QImage *image;
    QString *name;
    QRect *roundPatch;
    QString *empName;



};

#endif // MODELITEMCUSTOM_H
