#include "ModificationAppareil.h"
#include "ui_ModificationAppareil.h"
#include <QMessageBox>
#include "Messages.hpp"
#include "FenPrincipale.h"
#include <QKeySequence>

ModificationAppareil::ModificationAppareil(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationAppareil) {
    //Paramétrages
    ui->setupUi(this);
    this->BD = BD;

    QStringList tblHeader;
    tblHeader << "Identifiant" << "Nom" << "Type d'appareil" << "En cours d'utilisation";

    ui->tblEmploye->setColumnCount(4);
    ui->tblEmploye->setVerticalHeaderLabels(tblHeader);

    for(size_t i = 0; i < BD->getListTypeSize(); i++)
        ui->cbxDepartement->addItem(BD->getTypeAt(i)->getName());

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

    ui->btnRefresh->setShortcut(QKeySequence(Qt::Key_F5));
    ui->btnAdd->setShortcut(QKeySequence(Qt::Key_F6));
    ui->btnAdd->setShortcut(QKeySequence(Qt::Key_F7));
    ui->btnAdd->setShortcut(QKeySequence(Qt::Key_F8));
    ui->btnAdd->setShortcut(QKeySequence(Qt::Key_F9));
}

ModificationAppareil::~ModificationAppareil() {
    delete ui;
}

void ModificationAppareil::updateTable(int currentRow, int currentCol) {
    ui->tblEmploye->clearContents();
    ui->tblEmploye->setRowCount(0);

    for(int i = 0; i < ui->tblEmploye->columnCount(); i++)
        ui->tblEmploye->setColumnWidth(i, ui->tblEmploye->width() / ui->tblEmploye->columnCount());

    for(size_t i = 0; i < BD->getListObjetSize(); i++){
        ui->tblEmploye->insertRow(i);
        ui->tblEmploye->setItem(i, 0, new QTableWidgetItem(BD->getObjetAt(i)->getId()));
        ui->tblEmploye->setItem(i, 1, new QTableWidgetItem(BD->getObjetAt(i)->getName()));
        ui->tblEmploye->setItem(i, 2, new QTableWidgetItem(BD->getObjetAt(i)->getType()->getName()));

        QCheckBox *chbUse = new QCheckBox();
        chbUse->setCheckState(BD->getObjetAt(i)->isEmprunte()? Qt::Checked : Qt::Unchecked);
        chbUse->setEnabled(false);

        ui->tblEmploye->setCellWidget(i, 3, chbUse);
    }

    if(currentRow > -1){
        ui->txfEmploye->setText(BD->getObjetAt(currentRow)->getId());
        ui->txfNom->setText(BD->getObjetAt(currentRow)->getName());
        ui->cbxDepartement->setCurrentIndex(BD->getTypeId(BD->getObjetAt(currentRow)->getType()));
        ui->chbGestion->setCheckState(BD->getObjetAt(currentRow)->isEmprunte()? Qt::Checked : Qt::Unchecked);
        ui->tblEmploye->selectRow(currentRow);
    }
}

void ModificationAppareil::onCloseAction() {
    emit qApp->applicationVersionChanged();
    this->close();
}

void ModificationAppareil::refresh() {
    ui->tblEmploye->clearSelection();

    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
    ui->txfNom->clear();
    ui->chbGestion->setCheckState(Qt::Unchecked);
    ui->cbxDepartement->setCurrentIndex(-1);
}

void ModificationAppareil::ajout() {
    if(!ui->txfEmploye->text().isEmpty() || !ui->txfNom->text().isEmpty()) {
        if(ui->cbxDepartement->currentIndex() > -1){
            BD->addObjet(ui->txfEmploye->text(), ui->txfNom->text(), BD->getTypeAt(ui->cbxDepartement->currentIndex()), ui->chbGestion->isChecked());
            updateTable();
        }
        //TODO MSGBOX
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
}

void ModificationAppareil::suppression() {
    if(ui->tblEmploye->rowCount()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){
            QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

            //Vérification contre les erreurs d'intégritée référentielle
            if(!BD->isThisObjetInUse(indexList.at(0).row())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(OBJ_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delObjet(indexList.at(0).row());

                    updateTable();
                }
            }
            else
                QMessageBox::critical(this, getTitle(INTEGRITE_REFERENTIELLE), getError(OBJ_INTEGRITE_REFERENTIELLE));
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_NOSELECTION_TODELETE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_NOITEM_TODELETE));
}

void ModificationAppareil::modification() {
    if(ui->tblEmploye->rowCount()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblEmploye->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getObjetAt(indexList.at(0).row())->getId())
                    BD->getObjetAt(indexList.at(0).row())->setId(ui->txfEmploye->text());

                if(ui->txfNom->text() != BD->getObjetAt(indexList.at(0).row())->getName())
                    BD->getObjetAt(indexList.at(0).row())->setName(ui->txfNom->text());

                if(ui->cbxDepartement->currentIndex() != BD->getTypeId(BD->getObjetAt(indexList.at(0).row())->getType()))
                    BD->getObjetAt(indexList.at(0).row())->setType(BD->getTypeAt(ui->cbxDepartement->currentIndex()));

                if(ui->chbGestion->isChecked() != BD->getObjetAt(indexList.at(0).row())->isEmprunte())
                    BD->getObjetAt(indexList.at(0).row())->setEmprunte(ui->chbGestion->isChecked());

                updateTable();
            }
            else
                QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_NOSELECTION_TOMODIFY));
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_CHAMPVIDE_TOMOD));
    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(OBJ_NOITEM_TOMODIFY));
}

