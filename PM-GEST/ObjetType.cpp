#include "ObjetType.h"

ObjetType::ObjetType(QString name, QString image) {
    this->name = name;
    this->image = image;
}

ObjetType::~ObjetType() {}

QString ObjetType::getName() { return this->name; }

QString ObjetType::getImage() { return this->image; }

void ObjetType::setImage(QString image) { this->image = image; }

void ObjetType::setName(QString name) { this->name = name; }
