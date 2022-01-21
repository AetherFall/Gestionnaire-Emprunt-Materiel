#ifndef CSVBD_H
#define CSVBD_H

#include <fstream>
#include <QString>
#include <QDate>
#include <vector>

#include "Employe.h"
#include "Objets.h"
#include "Departement.h"
#include "ObjetType.h"
#include "Registre.h"

using namespace std;

class CSVBD {
    public:
        CSVBD();
        ~CSVBD();

        void addEmploye(int id, QString name, bool gestion);
        void delEmploye(int id);
        void addObjet(QString id, int type, QString name, bool estEmprunte);
        void delObjet(QString id);
        void addTypeObjet(QString typeName, QString ImgfilePath);
        void delTypeObjet(int id);
        void addDepartement(QString name);
        void delDepartement(int id);
        void modDepartement(QString name, int id);
        void addToRegistre(QDate date, int empId, int ObjId, int DepartementId, bool estRapporte = false);
        void setEstRapporter(int registreId, bool estRapporter);

        vector<Departement*> getListDepartement();
        Departement* getDepartementAt(int i);
        size_t getListDepartementSize();

    private:
        vector<Departement*> departements;
        vector<Employe*> employe;
        vector<Objets*> objets;
        vector<Registre*> registre;
        vector<ObjetType*> typeObjet;

        void lectureDepartement(QString file);


};

#endif // CSVBD_H
