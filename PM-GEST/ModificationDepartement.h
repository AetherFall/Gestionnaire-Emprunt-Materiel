#ifndef MODIFICATIONDEPARTEMENT_H
#define MODIFICATIONDEPARTEMENT_H

#include <QWidget>
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
};

#endif // MODIFICATIONDEPARTEMENT_H
