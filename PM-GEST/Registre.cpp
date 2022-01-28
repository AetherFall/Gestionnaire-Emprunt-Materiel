#include "Registre.h"

Registre::Registre(QDate date, Employe *employe, Objets *objet, Departement *departement) {
    this->date = date;
    this->employe = employe;
    this->objet = objet;
    this->departement = departement;
}

Registre::~Registre(){}

QDate Registre::getDate() { return this->date; }

Employe* Registre::getEmploye() { return this->employe; }

Objets* Registre::getObjet() { return this->objet; }

Departement* Registre::getDepartement() { return this->departement; }

void Registre::setDate(QDate date) { this->date = date; }

void Registre::setEmploye(Employe *emp) { this->employe = emp; }

void Registre::setObjet(Objets *obj) { this->objet = obj; }

void Registre::setDepartement(Departement *depart) { this->departement = depart; }
