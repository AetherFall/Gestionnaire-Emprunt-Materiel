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

private slots:
    void refresh();
    void ajout();
    void suppression();
    void modification();
    void updateTable(int currentRow = -1, int currentCol = -1);
    void onCloseAction();
};

#endif // MODIFICATIONEMPLOYE_H
