#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <string>

class Departement
{

public:
    Departement(int id, std::string name);
    ~Departement();

private:
    int id;
    std::string name;
};

#endif // DEPARTEMENT_H
