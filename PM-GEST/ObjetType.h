#ifndef OBJETTYPE_H
#define OBJETTYPE_H

#include <QString>

class ObjetType
{

public:
    ObjetType(int id, QString name, QString image);
    ~ObjetType();

private:
    int id;
    QString name;
    QString image;
};

#endif // OBJETTYPE_H
