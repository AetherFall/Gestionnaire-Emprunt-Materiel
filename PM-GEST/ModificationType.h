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

private slots:
    void refresh();
    void ajout();
    void suppression();
    void modification();
    void updateTable(int row = -1, int col = -1);
    void onCloseAction();
    void fileSearch();

};

#endif // MODIFICATIONTYPE_H
