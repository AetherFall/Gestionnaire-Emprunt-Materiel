#include "Registre.h"

Registre::Registre(int id, QDate date, Employe *employe, Objets *objet, Departement *departement) {
    this->id = id;
    this->date = date;
    this->employe = employe;
    this->objet = objet;
    this->departement = departement;
}

Registre::~Registre(){
    delete employe;
    delete objet;
    delete departement;
}
