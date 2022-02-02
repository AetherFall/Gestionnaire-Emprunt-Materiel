#ifndef MODIFICATIONTYPE_H
#define MODIFICATIONTYPE_H

#include <QWidget>
#include "CSVBD.h"
#include <QListWidgetItem>

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
    void updateTable(QListWidgetItem* item = nullptr);
    void onCloseAction();
    void fileSearch();

};

#endif // MODIFICATIONTYPE_H
