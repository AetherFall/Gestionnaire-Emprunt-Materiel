#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"
#include "CSVBD.h"
#include "Departement.h"
#include "Messages.hpp"

#include <vector>
#include <QMessageBox>

ModificationDepartement::ModificationDepartement(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationDepartement) {
    ui->setupUi(this);
    this->BD = BD;

    QStringList tblHeader;
    tblHeader << "Départements";

    ui->tblDepartement->setColumnCount(1);
    ui->tblDepartement->setColumnWidth(0, ui->tblDepartement->width());
    ui->tblDepartement->setHorizontalHeaderLabels(tblHeader);

    updateTable();

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblDepartement, SIGNAL(cellClicked(int,int)), this, SLOT(updateTable(int,int)));

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


void ModificationDepartement::updateTable(int currentRow, int currentCol) {
    ui->tblDepartement->clearContents();
    ui->tblDepartement->setRowCount(BD->getListDepartementSize());

    for(size_t i = 0; i < BD->getListDepartementSize(); i++){
        ui->tblDepartement->setItem(i, 0, new QTableWidgetItem(BD->getDepartementAt(i)->getNom()));
        ui->tblDepartement->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }

    if(currentRow > -1){
        ui->txfEmploye->setText(BD->getDepartementAt(currentRow)->getNom());
        ui->tblDepartement->selectRow(currentRow);
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
        QString name = ui->txfEmploye->text();
        int count = 0;

        while (BD->isAnotherDepartement(name) > -1) {
            count++;
            name = ui->txfEmploye->text().append(QString::fromStdString('(' + to_string(count) + ')'));
        }

        BD->addDepartement(name);
        updateTable();
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DEP_CHAMPVIDE_TOADD));
}

void ModificationDepartement::suppression() {
    if(ui->tblDepartement->rowCount()){
        if(ui->tblDepartement->selectionModel()->hasSelection()){

            //Vérification contre les erreurs d'intégritée référentielle
            if(!BD->isThisDepartementInUse(ui->tblDepartement->currentRow())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(DEP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delDepartement(ui->tblDepartement->currentRow());

                    refresh();
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
    if(ui->tblDepartement->rowCount()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblDepartement->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblDepartement->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getDepartementAt(indexList.at(0).row())->getNom()) {
                    BD->getDepartementAt(indexList.at(0).row())->setNom(ui->txfEmploye->text());
                    updateTable(indexList.at(0).row());
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
