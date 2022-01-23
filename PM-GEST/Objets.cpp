#include "Objets.h"

Objets::Objets(QString name, ObjetType *type, bool estEmprunte){
    this->type = type;
    this->name = name;
    this->estEmprunte = estEmprunte;
}

Objets::~Objets() {
    delete type;
}

QString Objets::getName() { return this->name; }

ObjetType* Objets::getType() { return this->type; }

bool Objets::isEmprunte() { return this->estEmprunte; }

void Objets::setName(QString name) { this->name = name; }

void Objets::setEmprunte(bool emprunte) { this->estEmprunte = emprunte; }

void Objets::setType(ObjetType *type) { this->type = type; }
