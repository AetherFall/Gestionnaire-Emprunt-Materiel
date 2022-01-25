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

        void addEmploye(int id, QString name, Departement *depart, bool gestion =false);
        void modEmploye(int i, int id, QString name, Departement *depart, bool gestion =false);
        void delEmploye(int i);

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
        int getDepartementId(Departement *depart);

        vector<Employe*> getListEmploye();
        Employe* getEmployeAt(int i);
        size_t getListEmployeSize();

        vector<Objets*> getListObjets();
        Objets* getObjetAt(int i);
        size_t getListObjetSize();

        vector<Registre*> getListRegistre();
        Registre* getRegistreAt(int i);
        size_t getRegistreSize();

    private:
        vector<Departement*> departements;
        vector<Employe*> employe;
        vector<Objets*> objets;
        vector<Registre*> registre;
        vector<ObjetType*> typeObjet;

        void lectureDepartement(QString file);
        void lectureEmploye(QString file);
        void lectureObjets(QString file);
        void lectureTypeObjets(QString file);
        void lectureRegistre(QString file);


};

#endif // CSVBD_H
