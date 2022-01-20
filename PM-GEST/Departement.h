#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <string>

class Departement
{

public:
    Departement(std::string name);
    ~Departement();

    std::string getNom();
    void setNom(std::string nom);

private:
    std::string name;
};

#endif // DEPARTEMENT_H
