#include "CSVBD.h"
#include <fstream>

#define LINK_REGISTRE "./res/files/Registre.csv" //"../PM-GEST/res/files/Registre.csv"
#define LINK_DEPARTEMENT "./res/files/Departements.csv"
#define LINK_EMPLOYES "./res/files/Employe.csv"
#define LINK_TYPEOBJETS "./res/files/TypeObjets.csv"
#define LINK_OBJETS "./res/files/Objets.csv"



CSVBD::CSVBD() {
    //Lecture des fichiers servant de base de données
    lectureDepartement(LINK_DEPARTEMENT);
    lectureEmploye(LINK_EMPLOYES);
    lectureTypeObjets(LINK_TYPEOBJETS);
    lectureObjets(LINK_OBJETS);
    lectureRegistre(LINK_REGISTRE);
}

CSVBD::~CSVBD() {
    writingRegistre(LINK_REGISTRE);
    writingObjets(LINK_OBJETS);
    writingTypeObjets(LINK_TYPEOBJETS);
    writingDepartement(LINK_DEPARTEMENT);
    writingEmploye(LINK_EMPLOYES);

    size_t i, r;

    r = employe.size();
    for(i = 0; i < r; i++)
        delete employe.at(i);

    r = objets.size();
    for(i = 0; i < r; i++)
        delete objets.at(i);

    r = typeObjet.size();
    for(i = 0; i < r; i++)
        delete typeObjet.at(i);

    r = departements.size();
    for(i = 0; i < r; i++)
        delete departements.at(i);

    r = registre.size();
    for(i = 0; i < r; i++)
        delete registre.at(i);
}


// ----------------------------------------------------------------------------------METHODE DÉPARTEMENTS

vector<Departement*> CSVBD::getListDepartement() { return departements; }

Departement* CSVBD::getDepartementAt(int i) { return departements.at(i); }

size_t CSVBD::getListDepartementSize() { return departements.size(); }

void CSVBD::addDepartement(QString name){ departements.push_back(new Departement(name)); }

void CSVBD::delDepartement(int id) {
    delete departements.at(id);
    departements.erase(departements.begin() + id);
}

int CSVBD::getDepartementId(Departement* depart) {
    for(size_t i = 0; i < departements.size(); i++)
        if(departements.at(i) == depart)
            return i;
    return -1;
}

bool CSVBD::isAnotherDepartement(QString name){
    for(size_t i = 0; i < departements.size(); i++)
        if(departements.at(i)->getNom() == name)
            return true;
    return false;
}

bool CSVBD::isThisDepartementInUse(int id){
    //Seul les employés utilisent l'objet département.
    for(size_t i = 0; i < employe.size(); i++)
        if(getDepartementId(employe.at(i)->getDepartement()) == id)
            return true;
    return false;
}

void CSVBD::lectureDepartement(const QString& file) {
    ifstream fluxDepartement(file.toStdString().c_str());
    if(fluxDepartement){
        string line;

        while(getline(fluxDepartement, line))
            departements.push_back(new Departement(QString::fromStdString(line)));

        fluxDepartement.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::writingDepartement(const QString &file) {
    ofstream fluxDepartement(file.toStdString().c_str());

    if(fluxDepartement){
        for(size_t i = 0; i < departements.size(); i++)
            fluxDepartement << departements.at(i)->getNom().toStdString() << std::endl;

        fluxDepartement.close();
    }
}


// ----------------------------------------------------------------------------------METHODE EMPLOYÉS

vector<Employe*> CSVBD::getListEmploye() { return employe; }

Employe* CSVBD::getEmployeAt(int i) { return employe.at(i); }

size_t CSVBD::getListEmployeSize() { return employe.size(); }

void CSVBD::addEmploye(int id, QString name, Departement* depart, bool gestion) { employe.push_back(new Employe(id, name, depart, gestion)); }

void CSVBD::delEmploye(int i) {
    delete employe.at(i);
    employe.erase(employe.begin() + i);
}

int CSVBD::getEmployeId(Employe *emp){
    for(size_t i = 0; i < employe.size(); i++)
        if(employe.at(i) == emp)
            return i;
    return -1;
}

int CSVBD::getEmployeIndexOfThisId(int id){
    for(size_t i = 0; i < employe.size(); i++)
        if(employe.at(i)->getId() == id)
            return i;

    return -1;
}

bool CSVBD::isThisEmployeInUse(int id){
    //Seul le registre utilise l'objet Employe.
    for(size_t i = 0; i < registre.size(); i++)
        if(getEmployeId(registre.at(i)->getEmploye()) == id)
            return true;
    return false;
}


bool CSVBD::isAnotherEmploye(int id){
    for(size_t i = 0; i < employe.size(); i++)
        if(employe.at(i)->getId() == id)
            return true;
    return false;
}

int CSVBD::isAnotherEmployeName(QString name) {
    int count = 0;

    for(size_t i = 0; i < employe.size(); i++)
        if(employe.at(i)->getName() == name)
            count++;
    return count;
}

void CSVBD::lectureEmploye(const QString& file){
    ifstream fluxEmploye(file.toStdString().c_str());
    if(fluxEmploye){
        string lineConvert;

        while(getline(fluxEmploye, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            employe.push_back(new Employe(line[0].toInt(), line[1], getDepartementAt(line[2].toInt()), line[3].toInt()));
        }

        fluxEmploye.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::writingEmploye(const QString &file) {
    ofstream fluxEmploye(file.toStdString().c_str());

    if(fluxEmploye){
        for(size_t i = 0; i < employe.size(); i++)
            fluxEmploye << employe.at(i)->getId() << ','
                        << employe.at(i)->getName().toStdString() << ','
                        << getDepartementId(employe.at(i)->getDepartement()) << ','
                        << employe.at(i)->getGestion() << std::endl;

        fluxEmploye.close();
    }
}


// ----------------------------------------------------------------------------------METHODE OBJETS

vector<Objets *> CSVBD::getListObjets() { return objets; }

Objets *CSVBD::getObjetAt(int i){ return objets.at(i); }

size_t CSVBD::getListObjetSize(){ return objets.size(); }

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

int CSVBD::getObjetIndexOfThisId(QString id) {
    for(size_t i = 0; i < objets.size(); i++)
        if(objets.at(i)->getId() == id)
            return i;

    return -1;
}

bool CSVBD::isThisObjetInUse(int id){
    //Seul le registre utilise l'objet Objet.
    for(size_t i = 0; i < registre.size(); i++)
        if(getObjetId(registre.at(i)->getObjet()) == id)
            return true;
    return false;
}

bool CSVBD::isAnotherObjet(QString id){
    for(size_t i = 0; i < objets.size(); i++)
        if(objets.at(i)->getId() == id)
            return true;
    return false;
}

int CSVBD::HowManyAnotherObjetName(QString name){
    int compt =0;

    for(size_t i = 0; i < objets.size(); i++)
        if(objets.at(i)->getName() == name)
            compt++;

    return compt;
}

void CSVBD::lectureObjets(const QString& file){
    ifstream fluxObjets(file.toStdString().c_str());
    if(fluxObjets){
        string lineConvert;

        while(getline(fluxObjets, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            objets.push_back(new Objets(line[0], line[1], getTypeAt(line[2].toInt()), line[3].toInt()));
        }

        fluxObjets.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::writingObjets(const QString &file) {
    ofstream fluxObjets(file.toStdString().c_str());

    if(fluxObjets){
        for(size_t i = 0; i < objets.size(); i++)
            fluxObjets << objets.at(i)->getId().toStdString() << ',' << objets.at(i)->getName().toStdString() << ',' << getTypeId(objets.at(i)->getType()) << ',' << objets.at(i)->isEmprunte() << std::endl;

        fluxObjets.close();
    }
}


// ----------------------------------------------------------------------------------METHODE REGISTRE

vector<Registre *> CSVBD::getListRegistre() { return registre; }

Registre *CSVBD::getRegistreAt(int i) { return registre.at(i); }

size_t CSVBD::getRegistreSize() { return registre.size(); }

void CSVBD::addToRegistre(QDate date, Employe *employe, Objets *objet){
    registre.push_back(new Registre(date, employe, objet));
}

void CSVBD::delFromRegistre(int i) {
    delete registre.at(i);
    registre.erase(registre.begin() + i);
}

int CSVBD::getRegistreOfThisObject(Objets* object){
    for(size_t i = 0; i < registre.size(); i++)
        if(registre.at(i)->getObjet() == object)
            return i;
    return -1;
}

void CSVBD::lectureRegistre(const QString& file){
    ifstream fluxRegistre(file.toStdString().c_str());
    if(fluxRegistre){
        string lineConvert;

        while(getline(fluxRegistre, lineConvert)){
            QList<QString> line = QString::fromStdString(lineConvert).split(",");
            if(line[1].toInt() != -1)
                registre.push_back(new Registre(QDate::fromString(line[0], "yyyy-MM-dd"), getEmployeAt(line[1].toInt()), getObjetAt(line[2].toInt())));
            else
                registre.push_back(new Registre(QDate::fromString(line[0], "yyyy-MM-dd"), new Employe(0, "Administrateur", new Departement("Gestion systeme"), true), getObjetAt(line[2].toInt())));
        }

        fluxRegistre.close();
    }

    //Pas de fichier, alors on en crée un
    else {
        ofstream createFile(file.toStdString().c_str());
        createFile.close();
    }
}

void CSVBD::writingRegistre(const QString &file) {
    ofstream fluxRegistre(file.toStdString().c_str());

    if(fluxRegistre){
        for(size_t i = 0; i < registre.size(); i++)
            fluxRegistre << registre.at(i)->getDate().toString("yyyy-MM-dd").toStdString() << ','
                         << to_string(getEmployeId(registre.at(i)->getEmploye())) << ','
                         << to_string(getObjetId(registre.at(i)->getObjet())) << std::endl;

        fluxRegistre.close();
    }
}


// ----------------------------------------------------------------------------------METHODE TYPE OBJET

vector<ObjetType *> CSVBD::getListType(){ return typeObjet; }

ObjetType* CSVBD::getTypeAt(int i){ return typeObjet.at(i); }

size_t CSVBD::getListTypeSize(){ return typeObjet.size(); }

int CSVBD::getTypeId(ObjetType *type){
    for(size_t i = 0; i < typeObjet.size(); i++)
        if(typeObjet.at(i) == type)
            return i;
    return -1;
}

void CSVBD::addTypeObjet(QString typeName, QString ImgfilePath){
    typeObjet.push_back(new ObjetType(typeName, ImgfilePath));
}

void CSVBD::delTypeObjet(int id) {
    delete typeObjet.at(id);
    typeObjet.erase(typeObjet.begin() + id);
}

bool CSVBD::isThisTypeInUse(int id){
    //Seul les objets utilise l'objet TypeObjet.
    for(size_t i = 0; i < objets.size(); i++)
        if(getTypeId(objets.at(i)->getType()) == id)
            return true;
    return false;
}

bool CSVBD::isAnotherType(QString name){
    for(size_t i = 0; i < typeObjet.size(); i++)
        if(typeObjet.at(i)->getName() == name)
            return true;
    return false;
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

void CSVBD::writingTypeObjets(const QString &file) {
    ofstream fluxType(file.toStdString().c_str());

    if(fluxType){
        for(size_t i = 0; i < typeObjet.size(); i++)
            fluxType << typeObjet.at(i)->getName().toStdString() << ',' << typeObjet.at(i)->getImage().toStdString() << std::endl;

        fluxType.close();
    }
}
