#include "ModificationType.h"
#include "ui_ModificationType.h"
#include "Messages.hpp"

#include <QMessageBox>
#include <QFileDialog>

ModificationType::ModificationType(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationType) {
    ui->setupUi(this);
    this->BD = BD;

    QStringList tblHead;
    tblHead << "Type d'appareil";

    ui->tblEmploye->setColumnCount(1);
    ui->tblEmploye->setColumnWidth(0, ui->tblEmploye->width());
    ui->tblEmploye->setHorizontalHeaderLabels(tblHead);

    updateTable();

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblEmploye, SIGNAL(cellChanged(int, int)), this, SLOT(updateTable(int, int)));
    connect(ui->btnRecherche, SIGNAL(clicked()), this, SLOT(fileSearch()));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnAdd->setFocusPolicy(Qt::NoFocus);
    ui->btnMod->setFocusPolicy(Qt::NoFocus);
    ui->btnDel->setFocusPolicy(Qt::NoFocus);
    ui->btnRefresh->setFocusPolicy(Qt::NoFocus);
    ui->btnRecherche->setFocusPolicy(Qt::NoFocus);
}

ModificationType::~ModificationType() {
    delete ui;
}

void ModificationType::onCloseAction() {
    emit qApp->applicationVersionChanged();
    this->close();
}

void ModificationType::fileSearch() {
    QString img = QFileDialog::getOpenFileName(this, "Rechercher une image avec fond transparent", QString(), "Images (*.png)");

    if(!img.isEmpty())
        ui->labImage->setText(img);
}

void ModificationType::updateTable(int currentRow, int currentCol) {
    ui->tblEmploye->clearContents();
    ui->tblEmploye->setRowCount(BD->getListTypeSize());

    for(size_t i = 0; i < BD->getListTypeSize(); i++){
        ui->tblEmploye->setItem(i, 0, new QTableWidgetItem(BD->getTypeAt(i)->getName()));
        ui->tblEmploye->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }

    if(currentRow > -1){
        ui->txfEmploye->setText(BD->getTypeAt(currentRow)->getName());
        ui->labImage->setText(BD->getTypeAt(currentRow)->getImage());
        ui->tblEmploye->selectRow(currentRow);
    }
    else {
        ui->txfEmploye->setText("");
        ui->labImage->setText("Lien vers l'image...");
    }
}

void ModificationType::refresh() {
    ui->tblEmploye->clearSelection();
    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
    ui->labImage->setText("Lien vers l'image...");
}

void ModificationType::ajout() {
    if(!ui->txfEmploye->text().isEmpty())
            BD->addTypeObjet(ui->txfEmploye->text(), ui->labImage->text());
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(TYP_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
    //TODO Mettre toute les erreures dans une classe d'erreur

    updateTable(ui->tblEmploye->rowCount() -1);
}

void ModificationType::suppression() {
    if(ui->tblEmploye->rowCount()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){
            QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

            //Vérification contre les erreurs d'intégrité référentielle
            if(!BD->isThisTypeInUse(ui->tblEmploye->currentRow())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(TYP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delTypeObjet(indexList.at(0).row());
                    updateTable(indexList.at(0).row());
                }
            }
            else
                QMessageBox::critical(this, getTitle(INTEGRITE_REFERENTIELLE), getError(TYP_INTEGRITE_REFERENTIELLE));
        }

        else
            QMessageBox::critical(this, getTitle(ERROR), getError(TYP_NOSELECTION_TODELETE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(TYP_NOITEM_TODELETE));
}

void ModificationType::modification() {
    if(ui->tblEmploye->rowCount()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblEmploye->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getTypeAt(indexList.at(0).row())->getName())
                    BD->getTypeAt(indexList.at(0).row())->setName(ui->txfEmploye->text());

                if(ui->labImage->text() != BD->getTypeAt(indexList.at(0).row())->getImage())
                    BD->getTypeAt(indexList.at(0).row())->setImage(ui->labImage->text());

                updateTable(indexList.at(0).row());
            }
            else
                QMessageBox::critical(this, getTitle(ERROR), getError(TYP_NOSELECTION_TOMODIFY));
        }
        else
            QMessageBox::critical(this, getTitle(ERROR), getError(TYP_CHAMPVIDE_TOMOD));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(TYP_NOITEM_TOMODIFY));

}
