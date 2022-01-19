#include "FenPrincipale.h"
#include "ui_FenPrincipale.h"
#include <QMessageBox>

FenPrincipale::FenPrincipale(QWidget *parent): QWidget(parent), ui(new Ui::FenPrincipale) {
    //Paramétrage principal
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Gestionnaire des emprunts matériel");

    //Connection des boutons
    connect(ui->btnQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->btnAffect, SIGNAL(clicked()), this, SLOT(affection()));
    connect(ui->btnDeAffect, SIGNAL(clicked()), this, SLOT(desaffection()));
}

FenPrincipale::~FenPrincipale() {
    delete ui;
    delete itGest;
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
    QString codeObjAdmin = "PM07";

    if(codeEmploye == codeAdmin && codeObjet == codeObjAdmin){
        //Acces à l'interface de gestion
        itGest = new InterfaceGestion(this);
        itGest->show();
    }

    else {
        //Code pour l'affectation de l'objet. Sauf si Emp
    }
}

void FenPrincipale::desaffection() {
    if(ui->txfObjet->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez remplir le champs [Code barre de l'objet], afin de pouvoir le désafecter");
        return;
    }

    //Some code...
}



