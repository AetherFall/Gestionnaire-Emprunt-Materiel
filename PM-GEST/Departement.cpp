#include "Departement.h"

Departement::Departement(std::string name){
    this->name = name;
}

Departement::~Departement() {}

std::string Departement::getNom() { return this->name; }

void Departement::setNom(std::string nom) { this->name = nom; }
