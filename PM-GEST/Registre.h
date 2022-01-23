#ifndef REGISTRE_H
#define REGISTRE_H

#include <QDate>
#include "Employe.h"
#include "Departement.h"
#include "Objets.h"

class Registre
{

public:
    Registre(QDate date, Employe *employe, Objets *objet, Departement *departement);
    ~Registre();

    //Getter
    QDate getDate();
    Employe* getEmploye();
    Objets* getObjet();
    Departement* getDepartement();

    //Setter
    void setDate(QDate date);
    void setEmploye(Employe* emp);
    void setObjet(Objets* obj);
    void setDepartement(Departement* depart);

private:
    QDate date;
    Employe *employe;
    Objets *objet;
    Departement *departement;
};

#endif // REGISTRE_H
