#include "ModificationDepartement.h"
#include "ui_ModificationDepartement.h"

ModificationDepartement::ModificationDepartement(QWidget *parent) : QWidget(parent), ui(new Ui::ModificationDepartement) {
    ui->setupUi(this);

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationDepartement::~ModificationDepartement() {
    delete ui;
}
