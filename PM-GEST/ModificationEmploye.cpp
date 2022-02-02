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
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblEmploye, SIGNAL(cellClicked(int,int)), this, SLOT(updateTable(int,int)));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnAdd->setFocusPolicy(Qt::NoFocus);
    ui->btnMod->setFocusPolicy(Qt::NoFocus);
    ui->btnDel->setFocusPolicy(Qt::NoFocus);
    ui->btnRefresh->setFocusPolicy(Qt::NoFocus);

}

ModificationEmploye::~ModificationEmploye() {
    delete ui;
}

void ModificationEmploye::onCloseAction() {
    emit qApp->applicationVersionChanged();
    this->close();
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
        QMessageBox::critical(this, getTitle(ERROR), getError(EMP_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
}

void ModificationEmploye::suppression() {
    if(ui->tblEmploye->rowCount()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){
            QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

            //Vérification contre les erreurs d'intégrités référentielle
            if(!BD->isThisEmployeInUse(indexList.at(0).row())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(EMP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delEmploye(indexList.at(0).row());

                    updateTable();
                }
            }
            else
                QMessageBox::critical(this, getTitle(INTEGRITE_REFERENTIELLE), getError(EMP_INTEGRITE_REFERENTIELLE));
        }
        else
            QMessageBox::critical(this, getTitle(ERROR), getError(EMP_NOSELECTION_TODELETE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(EMP_NOITEM_TODELETE));
}

void ModificationEmploye::modification() {
    if(ui->tblEmploye->rowCount()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblEmploye->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

                if(ui->txfNom->text() != BD->getEmployeAt(indexList.at(0).row())->getName())
                    BD->getEmployeAt(indexList.at(0).row())->setName(ui->txfNom->text());

                if(ui->txfEmploye->text() != QString::fromStdString(to_string(BD->getEmployeAt(indexList.at(0).row())->getId())))
                    BD->getEmployeAt(indexList.at(0).row())->setId(ui->txfEmploye->text().toInt());

                if(BD->getDepartementAt(ui->cbxDepartement->currentIndex()) != BD->getEmployeAt(indexList.at(0).row())->getDepartement())
                    BD->getEmployeAt(indexList.at(0).row())->setDepartement(BD->getDepartementAt(ui->cbxDepartement->currentIndex()));

                if(ui->chbGestion->isChecked() != BD->getEmployeAt(indexList.at(0).row())->getGestion())
                    BD->getEmployeAt(indexList.at(0).row())->setGestion(ui->chbGestion->isChecked());

                updateTable(indexList.at(0).row());
            }
            else
                QMessageBox::critical(this, getTitle(ERROR), getError(EMP_NOSELECTION_TOMODIFY));
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(EMP_CHAMPVIDE_TOMOD));
    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(EMP_NOITEM_TOMODIFY));

}
