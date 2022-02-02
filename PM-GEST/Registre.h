#ifndef REGISTRE_H
#define REGISTRE_H

#include <QDate>
#include "Employe.h"
#include "Objets.h"

class Registre
{

public:
    Registre(QDate date, Employe *employe, Objets *objet);
    ~Registre();

    //Getter
    QDate getDate();
    Employe* getEmploye();
    Objets* getObjet();

    //Setter
    void setDate(QDate date);
    void setEmploye(Employe* emp);
    void setObjet(Objets* obj);

private:
    QDate date;
    Employe *employe;
    Objets *objet;
};

#endif // REGISTRE_H
