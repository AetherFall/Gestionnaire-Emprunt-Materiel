#include "ModificationType.h"
#include "ui_ModificationType.h"
#include "Messages.hpp"

#include <QMessageBox>
#include <QFileDialog>

ModificationType::ModificationType(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationType) {
    ui->setupUi(this);
    this->BD = BD;

    updateTable();

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnRefresh, SIGNAL(clicked()), this, SLOT(refresh()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(ajout()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(suppression()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(modification()));
    connect(ui->tblEmploye, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateTable(QListWidgetItem*)));
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

void ModificationType::updateTable(QListWidgetItem* item) {
    int currentRow = ui->tblEmploye->indexFromItem(item).row();

    ui->tblEmploye->clear();

    for(size_t i = 0; i < BD->getListTypeSize(); i++){
        ui->tblEmploye->addItem(new QListWidgetItem(BD->getTypeAt(i)->getName()));
        ui->tblEmploye->item(i)->setTextAlignment(Qt::AlignCenter);
    }

    if(item){
        ui->txfEmploye->setText(BD->getTypeAt(currentRow)->getName());
        ui->labImage->setText(BD->getTypeAt(currentRow)->getImage());
        ui->tblEmploye->setCurrentRow(currentRow);
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
    if(!ui->txfEmploye->text().isEmpty()) {
            BD->addTypeObjet(ui->txfEmploye->text(), ui->labImage->text());
            updateTable();
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(TYP_CHAMPVIDE_TOADD));

    //TODO Ajouter une verification si un autre departement a le meme nom.
    //TODO Mettre toute les erreures dans une classe d'erreur

    updateTable(ui->tblEmploye->currentItem());
}

void ModificationType::suppression() {
    if(ui->tblEmploye->count()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){

            //Vérification contre les erreurs d'intégrité référentielle
            if(!BD->isThisTypeInUse(ui->tblEmploye->currentRow())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(TYP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delTypeObjet(ui->tblEmploye->currentRow());

                    //TODO -- REVOIR ICI.

                    updateTable();
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
    if(ui->tblEmploye->count()){
        if(!ui->txfEmploye->text().isEmpty()) {
            if(ui->tblEmploye->selectionModel()->hasSelection()){
                QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

                if(ui->txfEmploye->text() != BD->getTypeAt(indexList.at(0).row())->getName())
                    BD->getTypeAt(indexList.at(0).row())->setName(ui->txfEmploye->text());

                if(ui->labImage->text() != BD->getTypeAt(indexList.at(0).row())->getImage())
                    BD->getTypeAt(indexList.at(0).row())->setImage(ui->labImage->text());

                updateTable(ui->tblEmploye->currentItem());
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
