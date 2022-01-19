#ifndef OBJETS_H
#define OBJETS_H

#include <string>
#include "ObjetType.h"

class Objets
{

public:
    Objets(int id, std::string name, ObjetType* type = nullptr, bool estEmprunte = false);
    ~Objets();

private:
    int id;
    ObjetType *type;
    std::string name;
    bool estEmprunte;
};

#endif // OBJETS_H
