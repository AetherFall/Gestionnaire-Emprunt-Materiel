#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>

class Employe
{

public:
    Employe(int id, std::string name, bool gestion);
    ~Employe();

private:
    int employeId;
    std::string employeName;
    bool employeGestion;



};

#endif // EMPLOYE_H
