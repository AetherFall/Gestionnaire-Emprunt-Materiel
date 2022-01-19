#include "ModificationAppareil.h"
#include "ui_ModificationAppareil.h"

ModificationAppareil::ModificationAppareil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModificationAppareil)
{
    ui->setupUi(this);
}

ModificationAppareil::~ModificationAppareil()
{
    delete ui;
}
