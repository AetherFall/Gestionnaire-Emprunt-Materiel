#include "CSVBD.h"
#include <iostream>

CSVBD::CSVBD() {
    //Lecture des fichiers servant de base de données
    lectureDepartement(":/CSV/res/files/Departements.csv");
    lectureEmploye(":/CSV/res/files/Employe.csv");
    lectureTypeObjets(":/CSV/res/files/TypeObjets.csv");
    lectureObjets(":/CSV/res/files/Objets.csv");
    lectureRegistre(":/CSV/res/files/Registre.csv");
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

void CSVBD::addObjet(QString id, QString name, ObjetType *type, bool estEmprunte) {
    objets.push_back(new Objets(id, name, type, estEmprunte));
}

void CSVBD::delObjet(int i) {
    delete objets.at(i);
    objets.erase(objets.begin() + i);
}

void CSVBD::lectureObjets(QString file){
    objets.push_back(new Objets("6542", "CB#01", typeObjet.at(0), true));
    objets.push_back(new Objets("812", "CB#02", typeObjet.at(0), true));
    objets.push_back(new Objets("6578956", "CB#03", typeObjet.at(0), true));
    objets.push_back(new Objets("iuyft654", "CB#04", typeObjet.at(0), true));
    objets.push_back(new Objets("ilugyuhtf53641", "CB#05", typeObjet.at(0), true));
    objets.push_back(new Objets("65451643", "CB#06", typeObjet.at(0)));
    objets.push_back(new Objets("9875631", "CB#07", typeObjet.at(0)));
    objets.push_back(new Objets("32586", "CB#08", typeObjet.at(0)));
    objets.push_back(new Objets("74123", "CB#09", typeObjet.at(0)));
    objets.push_back(new Objets("32147", "CB#10", typeObjet.at(0)));
    objets.push_back(new Objets("96541", "CB#11", typeObjet.at(0)));
    objets.push_back(new Objets("14236", "CB#12", typeObjet.at(0)));
    objets.push_back(new Objets("3259874", "CB#13", typeObjet.at(0)));
    objets.push_back(new Objets("65219874", "CB#14", typeObjet.at(0)));
    objets.push_back(new Objets("3256452", "CB#15", typeObjet.at(0)));
    objets.push_back(new Objets("85296", "CB#16", typeObjet.at(0)));
    objets.push_back(new Objets("142596", "CB#17", typeObjet.at(0)));
    objets.push_back(new Objets("258741", "CB#18", typeObjet.at(0)));
    objets.push_back(new Objets("326594", "CB#19", typeObjet.at(0)));
    objets.push_back(new Objets("126598", "CB#20", typeObjet.at(0)));
    objets.push_back(new Objets("1223567", "CB#21", typeObjet.at(0)));
}

void CSVBD::lectureTypeObjets(QString file){
    typeObjet.push_back(new ObjetType("CB Radio", ":/images/res/images/radio.png"));
}

void CSVBD::lectureRegistre(QString file){
    registre.push_back(new Registre(QDate().currentDate(), employe.at(0), objets.at(0), departements.at(0)));
    registre.push_back(new Registre(QDate().currentDate(), employe.at(1), objets.at(1), departements.at(0)));
    registre.push_back(new Registre(QDate().currentDate(), employe.at(2), objets.at(2), departements.at(0)));
    registre.push_back(new Registre(QDate().currentDate(), employe.at(3), objets.at(3), departements.at(0)));
    registre.push_back(new Registre(QDate().currentDate(), employe.at(0), objets.at(4), departements.at(0)));
}


vector<Objets *> CSVBD::getListObjets() { return objets; }

Objets *CSVBD::getObjetAt(int i){ return objets.at(i); }

size_t CSVBD::getListObjetSize(){ return objets.size(); }

vector<Registre *> CSVBD::getListRegistre() { return registre; }

Registre *CSVBD::getRegistreAt(int i) { return registre.at(i); }

size_t CSVBD::getRegistreSize() { return registre.size(); }


//TypeObjets
vector<ObjetType *> CSVBD::getListType(){ return typeObjet; }

ObjetType* CSVBD::getTypeAt(int i){ return typeObjet.at(i); }

size_t CSVBD::getListTypeSize(){ return typeObjet.size(); }

int CSVBD::getTypeId(ObjetType *type){
    for(size_t i = 0; i < typeObjet.size(); i++)
        if(typeObjet.at(i) == type)
            return i;
    return -1;}

