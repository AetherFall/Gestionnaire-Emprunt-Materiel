#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"

ModificationDepartement::ModificationDepartement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModificationDepartement)
{
    ui->setupUi(this);
}

ModificationDepartement::~ModificationDepartement()
{
    delete ui;
}
