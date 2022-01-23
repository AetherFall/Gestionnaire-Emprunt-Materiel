#include "Employe.h"

Employe::Employe(int id, QString name, Departement* depart, bool gestion) {
    this->employeId = id;
    this->employeName = name;
    this->employeGestion = gestion;
    this->depart = depart;
}

Employe::~Employe() {}

//Getter

QString Employe::getName() { return this->employeName; }

bool Employe::getGestion() { return this->employeGestion;}

int Employe::getId() { return this->employeId; }

Departement* Employe::getDepartement() { return this->depart; }

//Setter

void Employe::setName(QString name) { this->employeName = name; }

void Employe::setGestion(bool gestion) { this->employeGestion = gestion; }

void Employe::setId(int id) { this->employeId = id; }

void Employe::setDepartement(Departement *depart) { this->depart = depart; }
