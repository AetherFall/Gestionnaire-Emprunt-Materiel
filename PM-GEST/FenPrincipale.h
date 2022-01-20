#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QPushButton>
#include <string>
#include "InterfaceGestion.h"
#include <iostream>
#include "CSVBD.h"
#include <QEvent>

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

private slots:
    void affection();
    void desaffection();
};
#endif // FENPRINCIPALE_H
