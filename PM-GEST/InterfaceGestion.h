#ifndef INTERFACEGESTION_H
#define INTERFACEGESTION_H

#include <QWidget>
#include "ModificationEmploye.h"
#include "ModificationAppareil.h"
#include "ModificationDepartement.h"
#include "ModificationType.h"
#include "CSVBD.h"

namespace Ui {
class InterfaceGestion;
}

class InterfaceGestion : public QWidget
{
    Q_OBJECT

public:
    explicit InterfaceGestion(CSVBD *BD, QWidget *parent = nullptr);
    ~InterfaceGestion();

private:
    Ui::InterfaceGestion *ui;
    ModificationEmploye *empScreen;
    ModificationAppareil *objScreen;
    ModificationDepartement *departScreen;
    ModificationType *typeScreen;
    CSVBD *BD;

private slots:
    void ouvertureInterfaceEmp();
    void ouvertureInterfaceObj();
    void ouvertureInterfaceType();
    void ouvertureInterfaceDepart();
};

#endif // INTERFACEGESTION_H
