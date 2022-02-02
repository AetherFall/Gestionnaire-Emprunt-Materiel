#include "InterfaceGestion.h"
#include "ui_InterfaceGestion.h"
#include "ModificationEmploye.h"
#include "FenPrincipale.h"

InterfaceGestion::InterfaceGestion(CSVBD *BD, QWidget *parent): QWidget(parent), ui(new Ui::InterfaceGestion) {
    //Paramétrage principal
    this->BD = BD;

    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Interface de gestion de l'application");

    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));
    connect(ui->btnLstEmp, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceEmp()));
    connect(ui->btnLstDepartement, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceDepart()));
    connect(ui->btnLstObjets, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceObj()));
    connect(ui->btnLstTypeObjets, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceType()));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnLstDepartement->setFocusPolicy(Qt::NoFocus);
    ui->btnLstEmp->setFocusPolicy(Qt::NoFocus);
    ui->btnLstObjets->setFocusPolicy(Qt::NoFocus);
    ui->btnLstTypeObjets->setFocusPolicy(Qt::NoFocus);
}

void InterfaceGestion::onCloseAction() {
    //Revoir l'émission: Nouveau signal dans qApp est possible?
    emit qApp->applicationVersionChanged();
    this->close();
}

InterfaceGestion::~InterfaceGestion() {
    delete ui;
}

void InterfaceGestion::ouvertureInterfaceEmp(){
    empScreen = new ModificationEmploye(BD, this);
    empScreen->show();
}

void InterfaceGestion::ouvertureInterfaceObj(){
    objScreen = new ModificationAppareil(BD, this);
    objScreen->show();
}

void InterfaceGestion::ouvertureInterfaceType() {
    typeScreen = new ModificationType(BD, this);
    typeScreen->show();
}

void InterfaceGestion::ouvertureInterfaceDepart() {
    departScreen = new ModificationDepartement(BD, this);
    departScreen->show();
}
