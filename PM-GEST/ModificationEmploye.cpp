#include "ModificationEmploye.h"
#include "ui_ModificationEmploye.h"
#include <QMessageBox>
#include "Messages.hpp"
#include <string>
#include <iostream>

ModificationEmploye::ModificationEmploye(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationEmploye) {
    //Paramétrages
    ui->setupUi(this);
    this->BD = BD;

    ui->tblEmploye->setAlternatingRowColors(true);
    ui->tblEmploye->setColumnCount(4);

    for(size_t i = 0; i < BD->getListDepartementSize(); i++)
        ui->cbxDepartement->addItem(BD->getDepartementAt(i)->getNom());

    if(ui->tblEmploye->rowCount())
        ui->tblEmploye->setCurrentCell(0, 0);

    updateTable();

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblEmploye, SIGNAL(cellClicked(int,int)), this, SLOT(updateTable(int,int)));

}

ModificationEmploye::~ModificationEmploye() {
    delete ui;
    delete BD;
}



void ModificationEmploye::updateTable(int currentRow, int currentCol) {
    ui->tblEmploye->clearContents();
    ui->tblEmploye->setRowCount(0);

    QStringList tblHeader;
    tblHeader << "Identifiant" << "Nom" << "Département" << "Gestion";
    ui->tblEmploye->setVerticalHeaderLabels(tblHeader);

    for(int i = 0; i < ui->tblEmploye->columnCount(); i++)
        ui->tblEmploye->setColumnWidth(i, ui->tblEmploye->width() / ui->tblEmploye->columnCount());

    for(size_t i = 0; i < BD->getListEmployeSize(); i++){
        ui->tblEmploye->insertRow(i);
        ui->tblEmploye->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(to_string(BD->getEmployeAt(i)->getId()))));
        ui->tblEmploye->setItem(i, 1, new QTableWidgetItem(BD->getEmployeAt(i)->getName()));
        ui->tblEmploye->setItem(i, 2, new QTableWidgetItem(BD->getEmployeAt(i)->getDepartement()->getNom()));

        QCheckBox *chbGest = new QCheckBox();
        chbGest->setCheckState(BD->getEmployeAt(i)->getGestion()? Qt::Checked : Qt::Unchecked);
        chbGest->setEnabled(false);

        ui->tblEmploye->setCellWidget(i, 3, chbGest);

/*
        for(int r =0; r < 5; r++)
            ui->tblEmploye->item(i, r)->setTextAlignment(Qt::AlignCenter);*/
    }

    if(currentRow > -1){
        ui->txfEmploye->setText(QString::fromStdString(to_string(BD->getEmployeAt(currentRow)->getId())));
        ui->txfNom->setText(BD->getEmployeAt(currentRow)->getName());
        ui->cbxDepartement->setCurrentIndex(BD->getDepartementId(BD->getEmployeAt(currentRow)->getDepartement()));
        ui->chbGestion->setCheckState(BD->getEmployeAt(currentRow)->getGestion()? Qt::Checked : Qt::Unchecked);
        ui->tblEmploye->selectRow(currentRow);
    }
}

void ModificationEmploye::refresh() {
    ui->tblEmploye->clearSelection();

    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
    ui->txfNom->clear();
    ui->chbGestion->setCheckState(Qt::Unchecked);
    ui->cbxDepartement->setCurrentIndex(-1);
}

void ModificationEmploye::ajout() {
    if(!ui->txfEmploye->text().isEmpty() || !ui->txfNom->text().isEmpty()) {
        if(ui->cbxDepartement->currentIndex() > -1){
            BD->addEmploye(std::stoi(ui->txfEmploye->text().toStdString()), ui->txfNom->text(), BD->getDepartementAt(ui->cbxDepartement->currentIndex()), ui->chbGestion->isChecked());
            updateTable();
        }
        //TODO MSGBOX
    }
    else
        QMessageBox::critical(this,"Erreur", getError(DEP_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
}

void ModificationEmploye::suppression() {
    if(ui->tblEmploye->rowCount()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){
            int rep = QMessageBox::information(this, getTitle(INFORMATION), getInfo(DEP_DELETE), QMessageBox::Yes, QMessageBox::No);

            if(rep == QMessageBox::Yes){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();
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

void ModificationEmploye::modification() {
    if(ui->tblEmploye->rowCount()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblEmploye->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getDepartementAt(indexList.at(0).row())->getNom()) {
                    BD->getDepartementAt(indexList.at(0).row())->setNom(ui->txfEmploye->text());
                    updateTable();
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
