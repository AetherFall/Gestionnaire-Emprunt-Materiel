#include "CSVBD.h"
#include <iostream>

CSVBD::CSVBD() {
    //Lecture des fichiers servant de base de données
    lectureDepartement("..\\PM-GEST\\res\\files\\Departements.csv");
    lectureEmploye("..\\PM-GEST\\res\\files\\Employe.csv");
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


//Departement Section
void CSVBD::lectureDepartement(QString file) {
    departements.push_back(new Departement("Cours"));
    departements.push_back(new Departement("Peinture"));
}

vector<Departement*> CSVBD::getListDepartement() { return departements; }

Departement* CSVBD::getDepartementAt(int i) { return departements.at(i); }

size_t CSVBD::getListDepartementSize() { return departements.size(); }

void CSVBD::addDepartement(QString name){ departements.push_back(new Departement(name)); }

void CSVBD::delDepartement(int id) {
    delete departements.at(id);
    departements.erase(departements.begin() + id);
}

void CSVBD::modDepartement(QString name, int id) {
    departements.at(id)->setNom(name);
}

int CSVBD::getDepartementId(Departement* depart) {
    for(size_t i = 0; i < departements.size(); i++)
        if(departements.at(i) == depart)
            return i;
    return -1;
}


//Employe Section
void CSVBD::lectureEmploye(QString file){
    employe.push_back(new Employe(104476, "William Lambert", departements.at(0) ,true));
    employe.push_back(new Employe(123456, "Robert Deniro", departements.at(1)));
    employe.push_back(new Employe(895623, "Charle Bartowski", departements.at(0)));
    employe.push_back(new Employe(986532, "Patrick Singcaster", departements.at(1), true));

}

vector<Employe*> CSVBD::getListEmploye() { return employe; }

Employe* CSVBD::getEmployeAt(int i) { return employe.at(i); }

size_t CSVBD::getListEmployeSize() { return employe.size(); }

void CSVBD::addEmploye(int id, QString name, Departement* depart, bool gestion) { employe.push_back(new Employe(id, name, depart, gestion)); }

void CSVBD::delEmploye(int i) {
    delete employe.at(i);
    employe.erase(employe.begin() + i);
}

void CSVBD::modEmploye(int i, int id, QString name, Departement *depart ,bool gestion) {
    employe.at(i)->setName(name);
    employe.at(i)->setId(id);
    employe.at(i)->setGestion(gestion);
    employe.at(i)->setDepartement(depart);
}

void CSVBD::lectureObjets(QString file){
    objets.push_back(new Objets("CB#01", typeObjet.at(0)));
    objets.push_back(new Objets("CB#02", typeObjet.at(0)));
    objets.push_back(new Objets("CB#03", typeObjet.at(0)));
    objets.push_back(new Objets("CB#04", typeObjet.at(0)));
    objets.push_back(new Objets("CB#05", typeObjet.at(0)));
    objets.push_back(new Objets("CB#06", typeObjet.at(0)));
    objets.push_back(new Objets("CB#07", typeObjet.at(0)));
    objets.push_back(new Objets("CB#08", typeObjet.at(0)));
    objets.push_back(new Objets("CB#09", typeObjet.at(0)));
}

void CSVBD::lectureTypeObjets(QString file){
    typeObjet.push_back(new ObjetType("CB Radio", ".\\res\\images\\radio.png"));
}

void CSVBD::lectureRegistre(QString file){

}
