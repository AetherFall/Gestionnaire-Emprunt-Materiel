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

    for(int i = 0; i < ui->tableWidget->columnCount(); i++)
        ui->tableWidget->setColumnWidth(i, ui->tableWidget->width() / ui->tableWidget->columnCount());

    for(int j = 0; j < ui->tableWidget->rowCount(); j++)
        ui->tableWidget->setRowHeight(j, ui->tableWidget->height() / 3);

    /*for(int r = 0; r < ui->tableWidget->columnCount(); r++)
        for(int o = 0; o < ui->tableWidget->rowCount(); o++)
            ui->tableWidget->setCellWidget(o, r, new ElementsItem("CB#01", ":/images/res/images/radio.png", "William Lambert", false));*/



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

void FenPrincipale::lectureRegistre(){
    int rowChange = 0;
    int colChange = 0;

    for(int i = 0; i < BD->getListObjetSize(); i++) {
        QString user = "";

        if(BD->getObjetAt(i)->isEmprunte())
            for(Registre *in : BD->getListRegistre())
                if(in->getObjet() == BD->getObjetAt(i))
                    user = in->getEmploye()->getName();

        if(i && i % ui->tableWidget->columnCount() == 0){
            ui->tableWidget->insertRow(1);
            colChange = 0;
            rowChange++;
        }
        else if(!i)
            colChange = 0;
        else
            colChange++;

        std::cout << rowChange << " : " << colChange << std::endl;
        //ui->tableWidget->setCellWidget(rowChange, colChange, new QLabel("Here"));
        ui->tableWidget->setCellWidget(rowChange, colChange, new ElementsItem(BD->getObjetAt(i)->getName(), BD->getObjetAt(i)->getType()->getImage(), user, BD->getObjetAt(i)->isEmprunte()));
    }

    std::cout<< ui->tableWidget->rowCount() << std::endl;
}



