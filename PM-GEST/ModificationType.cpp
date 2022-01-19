#include "ModificationType.h"
#include "ui_ModificationType.h"

ModificationType::ModificationType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModificationType)
{
    ui->setupUi(this);
}

ModificationType::~ModificationType()
{
    delete ui;
}
