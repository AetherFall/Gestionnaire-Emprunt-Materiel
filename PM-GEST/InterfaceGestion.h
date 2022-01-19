#ifndef INTERFACEGESTION_H
#define INTERFACEGESTION_H

#include <QWidget>
#include "ModificationEmploye.h"

namespace Ui {
class InterfaceGestion;
}

class InterfaceGestion : public QWidget
{
    Q_OBJECT

public:
    explicit InterfaceGestion(QWidget *parent = nullptr);
    ~InterfaceGestion();

private:
    Ui::InterfaceGestion *ui;
    ModificationEmploye *empScreen;

private slots:
    void ouvertureInterfaceEmp();
};

#endif // INTERFACEGESTION_H
