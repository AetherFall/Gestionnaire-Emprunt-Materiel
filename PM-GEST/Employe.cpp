#include "Employe.h"

Employe::Employe(int id, std::string name, bool gestion) {
    this->employeId = id;
    this->employeName = name;
    this->employeGestion = gestion;
}

Employe::~Employe() {}
