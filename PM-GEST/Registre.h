#ifndef REGISTRE_H
#define REGISTRE_H

#include <QDate>
#include "Employe.h"
#include "Departement.h"
#include "Objets.h"

class Registre
{

public:
    Registre(int id, QDate date, Employe *employe, Objets *objet, Departement *departement);
    ~Registre();

private:
    int id;
    QDate date;
    Employe *employe;
    Objets *objet;
    Departement *departement;
};

#endif // REGISTRE_H
