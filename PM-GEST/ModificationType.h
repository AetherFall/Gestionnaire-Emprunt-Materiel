#ifndef MODIFICATIONTYPE_H
#define MODIFICATIONTYPE_H

#include <QWidget>

namespace Ui {
class ModificationType;
}

class ModificationType : public QWidget
{
    Q_OBJECT

public:
    explicit ModificationType(QWidget *parent = nullptr);
    ~ModificationType();

private:
    Ui::ModificationType *ui;
};

#endif // MODIFICATIONTYPE_H
