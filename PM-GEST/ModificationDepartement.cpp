#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"
#include "CSVBD.h"
#include <vector>
#include "Departement.h"
#include <iostream>

ModificationDepartement::ModificationDepartement(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationDepartement) {
    ui->setupUi(this);
    this->BD = BD;

   vector<Departement*> lstDepart = BD->getListDepartement();

   std::cout << lstDepart.size() << std::endl;
/*
    ui->txfEmploye->setText(QString::fromStdString(lstDepart[0]->getNom()));*/

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationDepartement::~ModificationDepartement() {
    delete ui;
    delete BD;
}
