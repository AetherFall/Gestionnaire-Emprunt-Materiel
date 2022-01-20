#include "CSVBD.h"
#include <iostream>

CSVBD::CSVBD() {
    //Lecture des fichiers servant de base de données
    lectureDepartement("..\\PM-GEST\\res\\files\\Departements.csv");
}

CSVBD::~CSVBD() {
    size_t i;

    for(i = 0; i < employe.size(); i++){
        delete employe.at(i);
        employe.erase(employe.begin());
    }

    for(i = 0; i < objets.size(); i++){
        delete objets.at(i);
        objets.erase(objets.begin());
    }

    for(i = 0; i < typeObjet.size(); i++){
        delete typeObjet.at(i);
        typeObjet.erase(typeObjet.begin());
    }

    for(i = 0; i < departements.size(); i++){
        delete departements.at(i);
        departements.erase(departements.begin());
    }

    for(i = 0; i < registre.size(); i++){
        delete registre.at(i);
        registre.erase(registre.begin());
    }
}

void CSVBD::lectureDepartement(string file) {
    departements.push_back(new Departement("Cours"));\
}

vector<Departement*> CSVBD::getListDepartement() { return departements; }
