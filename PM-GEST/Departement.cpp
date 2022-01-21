#include "Departement.h"

Departement::Departement(QString name){
    this->name = name;
}

Departement::~Departement() {}

QString Departement::getNom() { return this->name; }

void Departement::setNom(QString nom) { this->name = nom; }
