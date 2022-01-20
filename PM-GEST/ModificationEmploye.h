#ifndef MODIFICATIONEMPLOYE_H
#define MODIFICATIONEMPLOYE_H

#include <QWidget>
#include "CSVBD.h"

namespace Ui {
class ModificationEmploye;
}

class ModificationEmploye : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationEmploye(CSVBD *BD, QWidget *parent = nullptr);
    ~ModificationEmploye();

private:
    Ui::ModificationEmploye *ui;
    CSVBD *BD;
};

#endif // MODIFICATIONEMPLOYE_H
