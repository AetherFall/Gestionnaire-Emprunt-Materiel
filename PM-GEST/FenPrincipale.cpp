#include "FenPrincipale.h"
#include "ui_FenPrincipale.h"
#include <QMessageBox>
#include <QEvent>
#include <QImage>
#include "ElementsItem.h"
#include "Registre.h"
#include "Objets.h"
#include "Messages.hpp"

FenPrincipale::FenPrincipale(CSVBD *BD, QWidget *parent): QWidget(parent), ui(new Ui::FenPrincipale) {
    //Paramétrage principal
    this->BD = BD;
    ui->setupUi(this);

    itGest = new InterfaceGestion(BD, this);
    itGest->setStyleSheet("background-color:rgba(255,255,255,20);");
    itGest->setHidden(true);

    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Gestionnaire des emprunts matériel");

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    lectureRegistre();

    //Connection des boutons
    connect(ui->btnQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->btnAffect, SIGNAL(clicked()), this, SLOT(affection()));
    connect(ui->btnDeAffect, SIGNAL(clicked()), this, SLOT(desaffection()));
    connect(qApp, SIGNAL(applicationVersionChanged()), this, SLOT(updateTable()));
    connect(this, SIGNAL(verificationTextField(QString, QLineEdit*)), this, SLOT(verification(QString, QLineEdit*)));
    connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(focusChange(QWidget*, QWidget*)));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnAffect->setFocusPolicy(Qt::NoFocus);
    ui->btnDeAffect->setFocusPolicy(Qt::NoFocus);
}

/**
 * @brief FenPrincipale::~FenPrincipale Destructeur
 */
FenPrincipale::~FenPrincipale() {
    delete ui;
    delete itGest;
    delete BD;
}

/**
 * @brief FenPrincipale::updateTable Rafraichissement de la fenêtre principale.
 */
void FenPrincipale::updateTable() {
    lectureRegistre();
    ui->txfEmploye->clear();
    ui->txfObjet->clear();
}

/**
 * @brief FenPrincipale::focusChange Activation de la vérification des champs des QLineEdits lors de la perte de focus.
 * @param a Objet Inutile obligatoirement transmis en parametre lors de l'utilisation d'un focusChange
 * @param b Objet Inutile obligatoirement transmis en parametre lors de l'utilisation d'un focusChange
 */
void FenPrincipale::focusChange(QWidget* a, QWidget* b){
    if(!ui->txfEmploye->hasFocus())
        emit verificationTextField(ui->txfEmploye->text(), ui->txfEmploye);
    if(!ui->txfObjet->hasFocus())
        emit verificationTextField(ui->txfObjet->text(), ui->txfObjet);
}


/**
 * @brief FenPrincipale::verification Sert à enlever les caractères superflus d'une mauvaise conversion de code bar vers la norme UPC-A.
 * @param text texte que contient le widget actuel pour vérifier.
 * @param edit Widget (QLineEdit) actuel pour réinscription du texte sans les charactères superflus.
 */
void FenPrincipale::verification(QString text, QLineEdit *edit) {
    if(text.contains('|', Qt::CaseInsensitive)){
        edit->clear();

        for (QString item : text.split('|'))
            edit->setText(edit->text().append(item));
    }
}

/**
 * @brief FenPrincipale::affection Création d'un lien entre un employé et un appareil.
 */
void FenPrincipale::affection(){
    //Vérification
    if(!ui->txfEmploye->text().isEmpty() && !ui->txfObjet->text().isEmpty()){

        //Vérification du code employé...
        if(BD->getEmployeIndexOfThisId(ui->txfEmploye->text().toInt()) != -1){
            if(BD->getObjetIndexOfThisId(ui->txfObjet->text()) != -1){
                //Affectation
                BD->addToRegistre(QDate().currentDate(), BD->getEmployeAt(BD->getEmployeIndexOfThisId(ui->txfEmploye->text().toInt())),
                                  BD->getObjetAt(BD->getObjetIndexOfThisId(ui->txfObjet->text())));

                BD->getObjetAt(BD->getObjetIndexOfThisId(ui->txfObjet->text()))->setEmprunte(true);

                updateTable();
            }

            else{
                if(ui->txfEmploye->text() == ui->txfObjet->text() && BD->getEmployeAt(BD->getEmployeIndexOfThisId(ui->txfEmploye->text().toInt()))->getGestion())
                    itGest->show();
                else
                        QMessageBox::critical(this, getTitle(ERROR), getError(AFFECT_OBJ_INEXISTANT));
            }
        }

        else{
            //TODO Majeur: Encrypter cette ligne..
            QString codeAdmin = "6961227";

            if(ui->txfEmploye->text() == codeAdmin && ui->txfObjet->text() == codeAdmin)
                itGest->show();

            else
                QMessageBox::critical(this, getTitle(ERROR), getError(AFFECT_EMP_INEXISTANT));
        }
    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(AFFECT_CHAMPVIDE));
}

/**
 * @brief FenPrincipale::desaffection Desctruction du lien entre un employé et un appareil.
 */
void FenPrincipale::desaffection() {
    if(!ui->txfObjet->text().isEmpty()){
        if(BD->getObjetIndexOfThisId(ui->txfObjet->text()) != -1){
            if(BD->getObjetAt(BD->getObjetIndexOfThisId(ui->txfObjet->text()))->isEmprunte()){
                BD->delFromRegistre(BD->getRegistreOfThisObject(BD->getObjetAt(BD->getObjetIndexOfThisId(ui->txfObjet->text()))));
                BD->getObjetAt(BD->getObjetIndexOfThisId(ui->txfObjet->text()))->setEmprunte(false);
                updateTable();
            }
            else
                QMessageBox::critical(this, getTitle(ERROR), getError(DESAFFECT_NOLINK));
        }
        else
           QMessageBox::critical(this, getTitle(ERROR), getError(DESAFFECT_OBJ_INEXISTANT));

    }

    else
        QMessageBox::critical(this, getTitle(ERROR), getError(DESAFFECT_CHAMPVIDE));
}

/**
 * @brief FenPrincipale::lectureRegistre Lecture des objets du tableau principale et affichage des liens d'affectations.
 */
void FenPrincipale::lectureRegistre(){
    //Réinitialisation tableau
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int rowChange = 0;
    int colChange = 0;

    //Row Insertion
    int addRow = (BD->getListObjetSize() % ui->tableWidget->columnCount())? 1 : 0;
    ui->tableWidget->setRowCount(BD->getListObjetSize() / ui->tableWidget->columnCount() + addRow);

    //Object Add
    for(int i = 0; i < BD->getListObjetSize(); i++) {
        QString user = "";

        if(BD->getObjetAt(i)->isEmprunte())
            for(Registre *in : BD->getListRegistre())
                if(in->getObjet() == BD->getObjetAt(i))
                    user = in->getEmploye()->getName();

        if(i && i % ui->tableWidget->columnCount() == 0){
            colChange = 0;
            rowChange++;
        }
        else if(!i)
            colChange = 0;
        else
            colChange++;

        ui->tableWidget->setCellWidget(rowChange, colChange, new ElementsItem(BD->getObjetAt(i)->getName(), BD->getObjetAt(i)->getType()->getImage(), user, BD->getObjetAt(i)->isEmprunte()));
    }

    //Set Row and Col size
    for(int i = 0; i < ui->tableWidget->columnCount(); i++)
        ui->tableWidget->setColumnWidth(i, ui->tableWidget->width() / ui->tableWidget->columnCount());

    for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        ui->tableWidget->setRowHeight(j, ui->tableWidget->height() / 3);
}



