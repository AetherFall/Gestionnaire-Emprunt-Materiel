#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include "Departement.h"

class Employe
{

public:
    Employe(int id, QString name, Departement* depart, bool gestion =false);
    ~Employe();

    //Getter
    QString getName();
    bool getGestion();
    int getId();
    Departement* getDepartement();

    //Setter
    void setName(QString name);
    void setGestion(bool gestion);
    void setId(int id);
    void setDepartement(Departement* depart);

private:
    int employeId;
    QString employeName;
    bool employeGestion;
    Departement* depart;
};

#endif // EMPLOYE_H
