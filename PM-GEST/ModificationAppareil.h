#ifndef MODIFICATIONAPPAREIL_H
#define MODIFICATIONAPPAREIL_H

#include <QWidget>

namespace Ui {
class ModificationAppareil;
}

class ModificationAppareil : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationAppareil(QWidget *parent = nullptr);
    ~ModificationAppareil();

private:
    Ui::ModificationAppareil *ui;
};

#endif // MODIFICATIONAPPAREIL_H
