#include "CSVBD.h"
#include <fstream>

CSVBD::CSVBD() {
    //Lecture des fichiers servant de base de données
    lectureDepartement("../PM-GEST/res/files/Departements.csv");
    lectureEmploye("../PM-GEST/res/files/Employe.csv");
    lectureTypeObjets("../PM-GEST/res/files/TypeObjets.csv");
    lectureObjets("../PM-GEST/res/files/Objets.csv");
    lectureRegistre("../PM-GEST/res/files/Registre.csv");
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
void CSVBD::lectureDepartement(const QString& file) {
    ifstream fluxDepartement(file.toStdString().c_str());
    if(fluxDepartement){
        string line;

        while(getline(fluxDepartement, line)){
            line = QString::fromStdString(line).split(",")[0].toStdString();
            departements.push_back(new Departement(QString::fromStdString(line)));
        }

        fluxDepartement.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
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
void CSVBD::lectureEmploye(const QString& file){
    ifstream fluxEmploye(file.toStdString().c_str());
    if(fluxEmploye){
        string lineConvert;

        while(getline(fluxEmploye, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            employe.push_back(new Employe(line[0].toInt(), line[1], getDepartementAt(line[2].toInt()), (line[3] == "true")));
        }

        fluxEmploye.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
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


int CSVBD::getEmployeId(Employe *emp){
    for(size_t i = 0; i < employe.size(); i++)
        if(employe.at(i) == emp)
            return i;
    return -1;
}

void CSVBD::addObjet(QString id, QString name, ObjetType *type, bool estEmprunte) {
    objets.push_back(new Objets(id, name, type, estEmprunte));
}

void CSVBD::delObjet(int i) {
    delete objets.at(i);
    objets.erase(objets.begin() + i);
}

int CSVBD::getObjetId(Objets *obj){
    for(size_t i = 0; i < objets.size(); i++)
        if(objets.at(i) == obj)
            return i;
    return -1;
}

void CSVBD::lectureObjets(const QString& file){
    ifstream fluxObjets(file.toStdString().c_str());
    if(fluxObjets){
        string lineConvert;

        while(getline(fluxObjets, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            objets.push_back(new Objets(line[0], line[1], getTypeAt(line[2].toInt()), (line[3] == "true")));
        }

        fluxObjets.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::lectureTypeObjets(const QString& file){
    ifstream fluxType(file.toStdString().c_str());
    if(fluxType){
        string lineConvert;

        while(getline(fluxType, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            typeObjet.push_back(new ObjetType(line[0], line[1]));
        }

        fluxType.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::lectureRegistre(const QString& file){
    ifstream fluxRegistre(file.toStdString().c_str());
    if(fluxRegistre){
        string lineConvert;

        while(getline(fluxRegistre, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            registre.push_back(new Registre(QDate::fromString(line[0]), getEmployeAt(line[1].toInt()), getObjetAt(line[2].toInt()), getDepartementAt(line[3].toInt())));
        }

        fluxRegistre.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
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
    return -1;
}

void CSVBD::writingDepartement(const QString &file) {

}

void CSVBD::writingEmploye(const QString &file) {

}

void CSVBD::writingObjets(const QString &file) {

}

void CSVBD::writingTypeObjets(const QString &file) {

}

void CSVBD::writingRegistre(const QString &file) {
   /* ofstream fluxRegistre(file.toStdString().c_str());

    if(fluxRegistre){
        for(int i = 0; i < registre.size(); i++) {
            fluxRegistre << registre.at(i)->getDate().toString() << ',' << to_string(getEmployeId(registre.at(i)->getEmploye()));
        }

        while(getline(fluxRegistre, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            registre.push_back(new Registre(QDate::fromString(line[0]), getEmployeAt(line[1].toInt()), getObjetAt(line[2].toInt()), getDepartementAt(line[3].toInt())));
        }

        fluxRegistre.close();
    }*/
}
