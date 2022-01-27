#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <QPushButton>
#include "InterfaceGestion.h"
#include <iostream>
#include "CSVBD.h"
#include <QEvent>
#include "ElementsItem.h"
#include <QLineEdit>

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
    void updateTable();
    void verification(QString text, QLineEdit* edit);
    void focusChange(QWidget* a = nullptr, QWidget* b = nullptr);

signals:
    void verificationTextField(QString text, QLineEdit* edit);

protected:
    bool keyPress(QKeyEvent *keyEvent);
};
#endif // FENPRINCIPALE_H
