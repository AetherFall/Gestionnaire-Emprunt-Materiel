#ifndef OBJETS_H
#define OBJETS_H

#include <QString>
#include "ObjetType.h"

class Objets
{

public:
    Objets(QString id, QString name, ObjetType* type = nullptr, bool estEmprunte = false);
    ~Objets();

    //Getter
    QString getId();
    QString getName();
    ObjetType* getType();
    bool isEmprunte();

    //Setter
    void setId(QString id);
    void setName(QString name);
    void setType(ObjetType* type);
    void setEmprunte(bool emprunte);

private:
    QString id;
    ObjetType *type;
    QString name;
    bool estEmprunte;
};

#endif // OBJETS_H
