#ifndef OBJETS_H
#define OBJETS_H

#include <QString>
#include "ObjetType.h"

class Objets
{

public:
    Objets(int id, QString name, ObjetType* type = nullptr, bool estEmprunte = false);
    ~Objets();

private:
    int id;
    ObjetType *type;
    QString name;
    bool estEmprunte;
};

#endif // OBJETS_H
