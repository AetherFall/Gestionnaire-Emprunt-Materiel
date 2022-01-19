#ifndef MODIFICATIONDEPARTEMENT_H
#define MODIFICATIONDEPARTEMENT_H

#include <QWidget>

namespace Ui {
class ModificationDepartement;
}

class ModificationDepartement : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationDepartement(QWidget *parent = nullptr);
    ~ModificationDepartement();

private:
    Ui::ModificationDepartement *ui;
};

#endif // MODIFICATIONDEPARTEMENT_H
