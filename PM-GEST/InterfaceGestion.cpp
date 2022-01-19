#include "InterfaceGestion.h"
#include "ui_InterfaceGestion.h"
#include "ModificationEmploye.h"

InterfaceGestion::InterfaceGestion(QWidget *parent): QWidget(parent), ui(new Ui::InterfaceGestion) {
    //Paramétrage principal
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Interface de gestion de l'application");

    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnLstEmp, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceEmp()));
    connect(ui->btnLstDepartement, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceDepart()));
    connect(ui->btnLstObjets, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceObj()));
    connect(ui->btnLstTypeObjets, SIGNAL(clicked()), this, SLOT(ouvertureInterfaceType()));
}

InterfaceGestion::~InterfaceGestion() {
    delete ui;
    delete empScreen;
    delete objScreen;
    delete departScreen;
    delete typeScreen;
}

void InterfaceGestion::ouvertureInterfaceEmp(){
    empScreen = new ModificationEmploye(this);
    empScreen->show();
}

void InterfaceGestion::ouvertureInterfaceObj(){
    objScreen = new ModificationAppareil(this);
    objScreen->show();
}

void InterfaceGestion::ouvertureInterfaceType() {
    typeScreen = new ModificationType(this);
    typeScreen->show();
}

void InterfaceGestion::ouvertureInterfaceDepart() {
    departScreen = new ModificationDepartement(this);
    departScreen->show();
}
