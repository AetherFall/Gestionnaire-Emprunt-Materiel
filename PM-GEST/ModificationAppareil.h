#ifndef MODIFICATIONAPPAREIL_H
#define MODIFICATIONAPPAREIL_H

#include <QWidget>
#include <QLineEdit>

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
    void focusChange(QWidget* a = nullptr, QWidget* b = nullptr);
    void verification(QString text, QLineEdit *edit, bool basic = true);

signals:
    void verificationTextField(QString, QLineEdit*, bool);
};

#endif // MODIFICATIONAPPAREIL_H
