#include "ModificationEmploye.h"
#include "ui_ModificationEmploye.h"
#include "Messages.hpp"

#include <QMessageBox>
#include <string>

ModificationEmploye::ModificationEmploye(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationEmploye) {
    //Paramétrages
    ui->setupUi(this);
    this->BD = BD;

    ui->tblEmploye->setAlternatingRowColors(true);
    ui->tblEmploye->setColumnCount(4);

    QStringList tblHeader;
    tblHeader << "Identifiant" << "Nom" << "Département" << "Gestion";
    ui->tblEmploye->setHorizontalHeaderLabels(tblHeader);

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
    connect(this, SIGNAL(verificationTextField(QString, QLineEdit*, bool)), this, SLOT(verification(QString, QLineEdit*, bool)));
    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(focusChange(QWidget*, QWidget*)));

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

/**
 * @brief FenPrincipale::focusChange Activation de la vérification des champs des QLineEdits lors de la perte de focus.
 * @param a Objet Inutile obligatoirement transmis en parametre lors de l'utilisation d'un focusChange
 * @param b Objet Inutile obligatoirement transmis en parametre lors de l'utilisation d'un focusChange
 */
void ModificationEmploye::focusChange(QWidget* a, QWidget* b){
    if(!ui->txfEmploye->hasFocus() && !ui->txfEmploye->text().isEmpty())
        emit verificationTextField(ui->txfEmploye->text(), ui->txfEmploye, true);

    if(!ui->txfNom->hasFocus() && !ui->txfNom->text().isEmpty())
        emit verificationTextField(ui->txfNom->text(), ui->txfNom, false);
}


/**
 * @brief FenPrincipale::verification Sert à enlever les caractères superflus d'une mauvaise conversion de code bar vers la norme UPC-A.
 * @param text texte que contient le widget actuel pour vérifier.
 * @param edit Widget (QLineEdit) actuel pour réinscription du texte sans les charactères superflus.
 */
void ModificationEmploye::verification(QString text, QLineEdit *edit, bool basic) {
    if(basic){
        if(text.contains('|', Qt::CaseInsensitive)){
            edit->clear();

            for (QString item : text.split('|'))
                edit->setText(edit->text().append(item));
        }


        if(!CSVBD::isNumeric(edit->text().toStdString())){
            edit->clear();
            QMessageBox::critical(this, getTitle(ERROR), getError(EMP_NOTNUMERIC));
        }
        else{
            if(edit->text().toStdString().length() >= 10){ //Limite d'un integer
                string temp = edit->text().toStdString();
                temp.erase(temp.begin()+9, temp.end());

                edit->setText(QString::fromStdString(temp));
                QMessageBox::critical(this, getTitle(ERROR), getError(EMP_OVERINTLIMIT));
            }
        }
    }
    else{
        QStringList textValue = text.split(" ");
        edit->setText("");

        for(size_t i = 0; i < textValue.count(); i++){
            if(!textValue[i].isEmpty()){
                textValue[i][0] = textValue[i][0].toUpper();
                edit->setText(edit->text().append(textValue[i]));
            }

            if(i+1 < textValue.size() && textValue[i+1].toStdString() != "" && textValue[i].toStdString() != "")
                edit->setText(edit->text().append(" "));
        }
    }
}

void ModificationEmploye::updateTable(int currentRow, int currentCol) {
    ui->tblEmploye->clearContents();
    ui->tblEmploye->setRowCount(0);

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
        QWidget *w = new QWidget();
        QHBoxLayout *l = new QHBoxLayout();

        l->setAlignment(Qt::AlignCenter);
        l->addWidget(chbGest);
        w->setLayout(l);
        chbGest->setStyleSheet("QCheckBox::indicator{background-color:none; border-style:none; width:25px; height:25px;}  QCheckBox::checked{image: url(:/icons/res/icons/SVG/Check.svg);}");
        w->setStyleSheet("background-color:none;");

        ui->tblEmploye->setCellWidget(i, 3, w);
    }

    for(int r = 0; r < ui->tblEmploye->rowCount(); r++)
        for(int c = 0; c < ui->tblEmploye->columnCount() -1; c++)
            ui->tblEmploye->item(r,c)->setTextAlignment(Qt::AlignCenter);

    if(currentRow > -1){
        ui->txfEmploye->setText(QString::fromStdString(to_string(BD->getEmployeAt(currentRow)->getId())));
        ui->txfNom->setText(BD->getEmployeAt(currentRow)->getName());
        ui->cbxDepartement->setCurrentIndex(BD->getDepartementId(BD->getEmployeAt(currentRow)->getDepartement()));
        ui->chbGestion->setCheckState(BD->getEmployeAt(currentRow)->getGestion()? Qt::Checked : Qt::Unchecked);
        ui->tblEmploye->selectRow(currentRow);
    }

    //Désactivation des boutons de contrôle quand le dit contrôle n'est plus possible.
    ui->btnDel->setEnabled(ui->tblEmploye->rowCount());
    ui->btnMod->setEnabled(ui->tblEmploye->rowCount() && currentRow > -1);
    ui->btnAdd->setEnabled(BD->getListDepartementSize());

    if(!BD->getListDepartementSize())
        ui->cbxDepartement->setPlaceholderText("Erreur - Veuillez ajoutez un département avant.");
    else
        ui->cbxDepartement->setPlaceholderText("");
}

void ModificationEmploye::refresh() {
    ui->tblEmploye->clearSelection();

    ui->txfEmploye->clear();
    ui->txfRecherche->clear();
    ui->txfNom->clear();
    ui->chbGestion->setCheckState(Qt::Unchecked);
    ui->cbxDepartement->setCurrentIndex(-1);
    ui->btnMod->setEnabled(false);
}

void ModificationEmploye::ajout() {
    if(!ui->txfEmploye->text().isEmpty() || !ui->txfNom->text().isEmpty()) {
        if(ui->cbxDepartement->currentIndex() > -1){
            //Vérification si le ID est unique.
            if(!BD->isAnotherEmploye(ui->txfEmploye->text().toInt())){

                verification(ui->txfNom->text(), ui->txfNom, false);
                BD->addEmploye(std::stoi(ui->txfEmploye->text().toStdString()), ui->txfNom->text(), BD->getDepartementAt(ui->cbxDepartement->currentIndex()), ui->chbGestion->isChecked());

                refresh();
                updateTable();
            }
            else
               QMessageBox::critical(this, getTitle(ERROR), getError(EMP_EXISTANT_TOADD));
        }
        else
             QMessageBox::critical(this, getTitle(ERROR), getError(EMP_COMBOBOX_VIDE));
    }
    else
        QMessageBox::critical(this, getTitle(ERROR), getError(EMP_CHAMPVIDE_TOADD));

}

void ModificationEmploye::suppression() {
    if(ui->tblEmploye->rowCount()){
        if(ui->tblEmploye->selectionModel()->hasSelection()){
            QModelIndexList indexList = ui->tblEmploye->selectionModel()->selectedIndexes();

            //Vérification contre les erreurs d'intégrités référentielle
            if(!BD->isThisEmployeInUse(indexList.at(0).row())){
                if(QMessageBox::information(this, getTitle(INFORMATION), getInfo(EMP_DELETE), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
                    BD->delEmploye(indexList.at(0).row());

                    refresh();
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

                if(ui->txfNom->text() != BD->getEmployeAt(indexList.at(0).row())->getName()){
                    verification(ui->txfNom->text(), ui->txfNom, false);
                    BD->getEmployeAt(indexList.at(0).row())->setName(ui->txfNom->text());
                }

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
