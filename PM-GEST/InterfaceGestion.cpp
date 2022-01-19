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
}

InterfaceGestion::~InterfaceGestion() {
    delete ui;
    delete empScreen;
}

void InterfaceGestion::ouvertureInterfaceEmp(){
    empScreen = new ModificationEmploye(this);
    empScreen->show();
}
