#include "Objets.h"

Objets::Objets(int id, std::string name, ObjetType *type, bool estEmprunte){
    this->id = id;
    this->type = type;
    this->name = name;
    this->estEmprunte = estEmprunte;
}

Objets::~Objets() {
    delete type;
}