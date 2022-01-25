#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QPushButton>
#include "InterfaceGestion.h"
#include <iostream>
#include "CSVBD.h"
#include <QEvent>
#include "ElementsItem.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class FenPrincipale; }
QT_END_NAMESPACE

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale(CSVBD *BD, QWidget *parent = nullptr);
    ~FenPrincipale();

private:
    Ui::FenPrincipale *ui;
    InterfaceGestion *itGest;
    CSVBD *BD;
    ElementsItem *elem;

private slots:
    void affection();
    void desaffection();
    void lectureRegistre();

protected:
    bool keyPress(QKeyEvent *keyEvent);
};
#endif // FENPRINCIPALE_H
