#ifndef MODIFICATIONDEPARTEMENT_H
#define MODIFICATIONDEPARTEMENT_H

#include <QWidget>
#include <QItemSelectionModel>
#include "CSVBD.h"

namespace Ui {
class ModificationDepartement;
}

class ModificationDepartement : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationDepartement(CSVBD *BD, QWidget *parent = nullptr);
    ~ModificationDepartement();

private:
    Ui::ModificationDepartement *ui;
    CSVBD *BD;
    QItemSelectionModel *mdlTbl;

private slots:
    void refresh();
    void ajout();
    void suppression();
    void modification();
};

#endif // MODIFICATIONDEPARTEMENT_H
