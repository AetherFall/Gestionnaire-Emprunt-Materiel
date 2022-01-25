#include "FenPrincipale.h"
#include "ui_FenPrincipale.h"
#include <QMessageBox>
#include <QEvent>
#include <QImage>
#include "ElementsItem.h"

FenPrincipale::FenPrincipale(CSVBD *BD, QWidget *parent): QWidget(parent), ui(new Ui::FenPrincipale) {
    //Paramétrage principal
    this->BD = BD;
    ui->setupUi(this);

    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Gestionnaire des emprunts matériel");


    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);


    for(int i = 0; i < ui->tableWidget->columnCount(); i++)
        ui->tableWidget->setColumnWidth(i, ui->tableWidget->width() / ui->tableWidget->columnCount());

    for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        ui->tableWidget->setRowHeight(j, ui->tableWidget->height() / 3);

    //elem = new ElementsItem(/*"CB#01", *new QImage("/res/images/radio.png"), "William Lambert", true*/);
    /*QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLabel("TEST"));
    QWidget *widg = new QWidget();

    widg->setLayout(layout);*/

    for(int r = 0; r < ui->tableWidget->columnCount(); r++)
        for(int o = 0; o < ui->tableWidget->rowCount(); o++)
            ui->tableWidget->setCellWidget(o, r, new ElementsItem());

    //Connection des boutons
    connect(ui->btnQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->btnAffect, SIGNAL(clicked()), this, SLOT(affection()));
    connect(ui->btnDeAffect, SIGNAL(clicked()), this, SLOT(desaffection()));

    //Ajout ActionListener

}

FenPrincipale::~FenPrincipale() {
    delete ui;
    delete itGest;
    delete BD;
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
}

void FenPrincipale::desaffection() {
    if(ui->txfObjet->text().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez remplir le champs [Code barre de l'objet], afin de pouvoir le désafecter");
        return;
    }

    //Some code...
}



