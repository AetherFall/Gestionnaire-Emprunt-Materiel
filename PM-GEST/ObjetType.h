#ifndef OBJETTYPE_H
#define OBJETTYPE_H

#include <QString>

class ObjetType
{

public:
    ObjetType(QString name, QString image);
    ~ObjetType();

    //Getter
    QString getName();
    QString getImage();

    //Setter
    void setName(QString name);
    void setImage(QString image);

private:
    QString name;
    QString image;
};

#endif // OBJETTYPE_H
