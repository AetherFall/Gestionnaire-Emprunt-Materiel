#ifndef MODIFICATIONAPPAREIL_H
#define MODIFICATIONAPPAREIL_H

#include <QWidget>
#include "CSVBD.h"

namespace Ui {
class ModificationAppareil;
}

class ModificationAppareil : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationAppareil(CSVBD *BD, QWidget *parent = nullptr);
    ~ModificationAppareil();

private:
    Ui::ModificationAppareil *ui;
    CSVBD *BD;

private slots:
    void refresh();
    void ajout();
    void suppression();
    void modification();
    void updateTable(int currentRow = -1, int currentCol = -1);
    void onCloseAction();
};

#endif // MODIFICATIONAPPAREIL_H
