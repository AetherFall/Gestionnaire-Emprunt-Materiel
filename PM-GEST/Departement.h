#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <QString>

class Departement
{

public:
    Departement(QString name);
    ~Departement();

    QString getNom();
    void setNom(QString nom);

private:
    QString name;
};

#endif // DEPARTEMENT_H
