#include "FenPrincipale.h"
#include "ui_FenPrincipale.h"
#include <QMessageBox>
#include <QEvent>
#include <QImage>
#include "ElementsItem.h"
#include "Registre.h"
#include "Objets.h"

FenPrincipale::FenPrincipale(CSVBD *BD, QWidget *parent): QWidget(parent), ui(new Ui::FenPrincipale) {
    //Paramétrage principal
    this->BD = BD;
    ui->setupUi(this);

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

}

FenPrincipale::~FenPrincipale() {
    delete ui;
    delete itGest;
    delete BD;
}

void FenPrincipale::updateTable() {
    lectureRegistre();
    ui->txfEmploye->clear();
    ui->txfObjet->clear();
}

void FenPrincipale::focusChange(QWidget* a, QWidget* b){
    if(!ui->txfEmploye->hasFocus())
        emit verificationTextField(ui->txfEmploye->text(), ui->txfEmploye);
    if(!ui->txfObjet->hasFocus())
        emit verificationTextField(ui->txfObjet->text(), ui->txfObjet);
}

void FenPrincipale::verification(QString text, QLineEdit *edit) {
    if(text.contains('|', Qt::CaseInsensitive)){
        edit->clear();

        for (QString item : text.split('|'))
            edit->setText(edit->text().append(item));
    }
}

void FenPrincipale::affection(){
    //Vérification
    if(ui->txfEmploye->text().isEmpty() || ui->txfObjet->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez remplir les champs");
        return;
    }

    QString codeEmploye = ui->txfEmploye->text();
    QString codeObjet = ui->txfObjet->text();

    //TODO Majeur: Encrypter cette ligne..
    QString codeAdmin = "104476";
    QString codeObjAdmin = "104476";

    if(codeEmploye == codeAdmin && codeObjet == codeObjAdmin){

        //Acces à l'interface de gestion
        itGest = new InterfaceGestion(BD, this);
        itGest->setStyleSheet("background-color:rgba(255,255,255,20);");
        itGest->show();
    }

    else {
        //Code pour l'affectation de l'objet. Sauf si Emp
    }

    lectureRegistre();
}

void FenPrincipale::desaffection() {
    if(ui->txfObjet->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez remplir le champs [Code barre de l'objet], afin de pouvoir le désafecter");
        return;
    }

    //Some code...
    lectureRegistre();
}

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



