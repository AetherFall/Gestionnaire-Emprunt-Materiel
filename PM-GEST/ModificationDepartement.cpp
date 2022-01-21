#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"
#include "CSVBD.h"
#include <vector>
#include "Departement.h"
#include <iostream>
#include <QMessageBox>
#include "Messages.hpp"

ModificationDepartement::ModificationDepartement(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationDepartement) {
    ui->setupUi(this);
    this->BD = BD;

    ui->tblDepartement->setSelectionModel(new QItemSelectionModel());

    ui->tblDepartement->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblDepartement->setSelectionMode(QAbstractItemView::SingleSelection);

    updateTable();

    if(ui->tblDepartement->count())
        ui->tblDepartement->selectionModel()->selectedRows(0);

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblDepartement->selectionModel(), SIGNAL(selectionChanged()), this, SLOT(updateTable()));
}

ModificationDepartement::~ModificationDepartement() {
    delete ui;
    delete BD;
}

void ModificationDepartement::updateTable() {
    ui->tblDepartement->clear();

    for(size_t i = 0; i < BD->getListDepartementSize(); i++){
        ui->tblDepartement->addItem(new QListWidgetItem(BD->getDepartementAt(i)->getNom()));
        ui->tblDepartement->item(i)->setTextAlignment(Qt::AlignCenter);
    }

    if(ui->tblDepartement->selectionModel()->hasSelection()){
        QModelIndexList indexList = ui->tblDepartement->selectionModel()->selectedIndexes();
        ui->txfEmploye->setText(BD->getDepartementAt(indexList.at(0).row())->getNom());
    }
}

void ModificationDepartement::refresh() {
    ui->tblDepartement->clearSelection();
    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
}

void ModificationDepartement::ajout() {
    if(ui->txfEmploye->text().isEmpty()) {
        QMessageBox::critical(this,"Erreur", getError(DEP_CHAMPVIDE_TOADD));
        return;
    }

    //TODO Ajouter une verification si un autre departement a le meme nom.
    //TODO Mettre toute les erreures dans une classe d'erreur

    BD->addDepartement(ui->txfEmploye->text());

    refresh();
    updateTable();
}

void ModificationDepartement::suppression() {
    if(!ui->tblDepartement->count()){
        if(ui->tblDepartement->selectionModel()->hasSelection()){
            int rep = QMessageBox::information(this, getTitle(INFORMATION), getInfo(DEP_DELETE), QMessageBox::Yes, QMessageBox::No);

            if(rep == QMessageBox::Yes){
                QModelIndexList indexList = ui->tblDepartement->selectionModel()->selectedIndexes();
                BD->delDepartement(indexList.at(0).row());

                updateTable();
            }
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOSELECTION_TODELETE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOITEM_TODELETE));
}

void ModificationDepartement::modification() {
    if(!ui->tblDepartement->count()){
        if(!ui->txfEmploye->text().isEmpty()) {
            QModelIndexList indexList = ui->tblDepartement->selectionModel()->selectedIndexes();

            if(ui->txfEmploye->text() != BD->getDepartementAt(indexList.at(0).row())->getNom()) {
                BD->getDepartementAt(indexList.at(0).row())->setNom(ui->txfEmploye->text());
                updateTable();
            }
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(DEP_CHAMPVIDE_TOMOD));
    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOITEM_TOMODIFY));

}
