#ifndef CSVBD_H
#define CSVBD_H

#include <fstream>
#include <string>
#include <QDate>
#include <vector>

#include "Employe.h"
#include "Objets.h"
#include "Departement.h"
#include "ObjetType.h"
#include "Registre.h"

using namespace std;

class CSVBD
{

public:
    CSVBD();
    ~CSVBD();
    void addEmploye(int id, string name, bool gestion);
    void delEmploye(int id);
    void addObjet(string id, int type, string name, bool estEmprunte);
    void delObjet(string id);
    void addTypeObjet(string typeName, string ImgfilePath);
    void delTypeObjet(int id);
    void addDepartement(string name);
    void delDepartement(int id);
    void addToRegistre(QDate date, int empId, int ObjId, int DepartementId, bool estRapporte = false);
    void setEstRapporter(int registreId, bool estRapporter);

private:
    vector<Employe*> employe;
    vector<Objets*> objets;
    vector<Registre*> registre;
    vector<Departement*> departements;
    vector<ObjetType*> typeObjet;

};

#endif // CSVBD_H
