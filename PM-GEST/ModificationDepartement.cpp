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

    updateTable();

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblDepartement, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateTable(QListWidgetItem*)));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnAdd->setFocusPolicy(Qt::NoFocus);
    ui->btnMod->setFocusPolicy(Qt::NoFocus);
    ui->btnDel->setFocusPolicy(Qt::NoFocus);
    ui->btnRefresh->setFocusPolicy(Qt::NoFocus);
}

ModificationDepartement::~ModificationDepartement() {
    delete ui;
}

void ModificationDepartement::onCloseAction() {
    emit qApp->applicationVersionChanged();
    this->close();
}


void ModificationDepartement::updateTable(QListWidgetItem* item) {
    int currentRow = ui->tblDepartement->indexFromItem(item).row();
    ui->tblDepartement->clear();

    for(size_t i = 0; i < BD->getListDepartementSize(); i++){
        ui->tblDepartement->addItem(new QListWidgetItem(BD->getDepartementAt(i)->getNom()));
        ui->tblDepartement->item(i)->setTextAlignment(Qt::AlignCenter);
    }

    if(item){
        ui->txfEmploye->setText(BD->getDepartementAt(currentRow)->getNom());
        ui->tblDepartement->setCurrentRow(currentRow);
    }
    else
        ui->txfEmploye->setText("");
}

void ModificationDepartement::refresh() {
    ui->tblDepartement->clearSelection();
    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
}

void ModificationDepartement::ajout() {
    if(!ui->txfEmploye->text().isEmpty()) {
            BD->addDepartement(ui->txfEmploye->text());
            updateTable();
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
    //TODO Mettre toute les erreures dans une classe d'erreur

    updateTable();
}

void ModificationDepartement::suppression() {
    if(ui->tblDepartement->count()){
        if(ui->tblDepartement->selectionModel()->hasSelection()){

            //Vérification contre les erreurs d'intégritée référentielle
            if(!BD->isThisDepartementInUse(ui->tblDepartement->currentRow())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(DEP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delDepartement(ui->tblDepartement->currentRow());
                    updateTable();
                }
            }
            else
                QMessageBox::critical(this, getTitle(INTEGRITE_REFERENTIELLE), getError(DEP_INTEGRITE_REFERENTIELLE));
        }
        else
            QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOSELECTION_TODELETE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOITEM_TODELETE));
}

void ModificationDepartement::modification() {
    if(ui->tblDepartement->count()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblDepartement->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblDepartement->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getDepartementAt(indexList.at(0).row())->getNom()) {
                    BD->getDepartementAt(indexList.at(0).row())->setNom(ui->txfEmploye->text());
                    updateTable(ui->tblDepartement->currentItem());
                }
            }
            else
                QMessageBox::critical(this, getTitle(ERROR), getError(DEP_CHAMPVIDE_TOMOD));
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(DEP_CHAMPVIDE_TOMOD));
    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_NOITEM_TOMODIFY));

}
