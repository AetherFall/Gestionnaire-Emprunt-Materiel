#ifndef OBJETTYPE_H
#define OBJETTYPE_H

#include <string>

class ObjetType
{

public:
    ObjetType(int id, std::string name, std::string image);
    ~ObjetType();

private:
    int id;
    std::string name;
    std::string image;
};

#endif // OBJETTYPE_H
