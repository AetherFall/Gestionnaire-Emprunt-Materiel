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

        vector<Departement*> getListDepartement();
        Departement* getDepartementAt(int i);
        size_t getListDepartementSize();
        int getDepartementId(Departement *depart);
        void addDepartement(QString name);
        void delDepartement(int id);
        void modDepartement(QString name, int id);
        bool isThisDepartementInUse(int id);
        int isAnotherDepartement(QString name);

        vector<Employe*> getListEmploye();
        Employe* getEmployeAt(int i);
        size_t getListEmployeSize();
        int getEmployeId(Employe *emp);
        int getEmployeIndexOfThisId(int id);
        void addEmploye(int id, QString name, Departement *depart, bool gestion =false);
        void modEmploye(int i, int id, QString name, Departement *depart, bool gestion =false);
        void delEmploye(int i);
        bool isThisEmployeInUse(int id);
        bool isAnotherEmploye(int id);
        int isAnotherEmployeName(QString name);

        vector<Objets*> getListObjets();
        Objets* getObjetAt(int i);
        size_t getListObjetSize();
        int getObjetId(Objets *obj);
        int getObjetIndexOfThisId(QString id);
        void addObjet(QString id, QString name, ObjetType *type, bool estEmprunte);
        void delObjet(int i);
        bool isThisObjetInUse(int id);
        bool isAnotherObjet(QString id);
        int HowManyAnotherObjetName(QString name);

        void addToRegistre(QDate date, Employe *employe, Objets *objet);
        void delFromRegistre(int i);
        vector<Registre*> getListRegistre();
        Registre* getRegistreAt(int i);
        size_t getRegistreSize();
        int getRegistreOfThisObject(Objets* object);

        vector<ObjetType*> getListType();
        ObjetType* getTypeAt(int i);
        size_t getListTypeSize();
        int getTypeId(ObjetType *type);
        void addTypeObjet(QString typeName, QString ImgfilePath);
        void delTypeObjet(int id);
        bool isThisTypeInUse(int id);
        int isAnotherType(QString name);

        static bool isNumeric(string str);

    private:
        vector<Departement*> departements;
        vector<Employe*> employe;
        vector<Objets*> objets;
        vector<Registre*> registre;
        vector<ObjetType*> typeObjet;

        void lectureDepartement(const QString& file);
        void lectureEmploye(const QString& file);
        void lectureObjets(const QString& file);
        void lectureTypeObjets(const QString& file);
        void lectureRegistre(const QString& file);

        void writingDepartement(const QString& file);
        void writingEmploye(const QString& file);
        void writingObjets(const QString& file);
        void writingTypeObjets(const QString& file);
        void writingRegistre(const QString& file);
        inline bool exist (const std::string& name);

};

#endif // CSVBD_H
