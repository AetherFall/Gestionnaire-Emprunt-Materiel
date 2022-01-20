#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"
#include "CSVBD.h"
#include <vector>
#include "Departement.h"
#include <iostream>

ModificationDepartement::ModificationDepartement(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationDepartement) {
    ui->setupUi(this);
    this->BD = BD;

    for(size_t i = 0; i < BD->getListDepartementSize(); i++){
        ui->tblDepartement->addItem(new QListWidgetItem(QString::fromStdString(BD->getDepartementAt(i)->getNom())));
        ui->tblDepartement->item(i)->setTextAlignment(Qt::AlignCenter);
    }

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
}

ModificationDepartement::~ModificationDepartement() {
    delete ui;
    delete BD;
}

void ModificationDepartement::refresh() {
    //ui->tblDepartement->setSelectio
}

void ModificationDepartement::ajout() {}

void ModificationDepartement::suppression() {}

void ModificationDepartement::modification() {}
