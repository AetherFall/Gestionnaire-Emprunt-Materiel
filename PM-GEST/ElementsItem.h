#ifndef ELEMENTSITEM_H
#define ELEMENTSITEM_H

#include <QWidget>

namespace Ui {
class ElementsItem;
}

class ElementsItem : public QWidget
{
    Q_GADGET

public:
    explicit ElementsItem(/*QString tagName, QImage imgLink, QString userName = "", bool actif = false, */);
    ~ElementsItem();

private:
    Ui::ElementsItem *ui;
};

#endif // ELEMENTSITEM_H