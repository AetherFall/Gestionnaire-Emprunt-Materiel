#ifndef MODIFICATIONTYPE_H
#define MODIFICATIONTYPE_H

#include <QWidget>
#include "CSVBD.h"

namespace Ui {
class ModificationType;
}

class ModificationType : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationType(CSVBD *BD, QWidget *parent = nullptr);
    ~ModificationType();

private:
    Ui::ModificationType *ui;
    CSVBD *BD;
};

#endif // MODIFICATIONTYPE_H
