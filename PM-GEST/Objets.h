#ifndef OBJETS_H
#define OBJETS_H

#include <QString>
#include "ObjetType.h"

class Objets
{

public:
    Objets(QString name, ObjetType* type = nullptr, bool estEmprunte = false);
    ~Objets();

    //Getter
    QString getName();
    ObjetType* getType();
    bool isEmprunte();

    //Setter
    void setName(QString name);
    void setType(ObjetType* type);
    void setEmprunte(bool emprunte);

private:
    ObjetType *type;
    QString name;
    bool estEmprunte;
};

#endif // OBJETS_H
