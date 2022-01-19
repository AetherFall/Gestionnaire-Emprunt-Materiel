#ifndef MODIFICATIONEMPLOYE_H
#define MODIFICATIONEMPLOYE_H

#include <QWidget>

namespace Ui {
class ModificationEmploye;
}

class ModificationEmploye : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationEmploye(QWidget *parent = nullptr);
    ~ModificationEmploye();

private:
    Ui::ModificationEmploye *ui;
};

#endif // MODIFICATIONEMPLOYE_H
