#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>

class Employe
{

public:
    Employe(int id, QString name, bool gestion);
    ~Employe();

private:
    int employeId;
    QString employeName;
    bool employeGestion;



};

#endif // EMPLOYE_H
