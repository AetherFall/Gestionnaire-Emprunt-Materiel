#include "ModificationAppareil.h"
#include "ui_ModificationAppareil.h"

ModificationAppareil::ModificationAppareil(QWidget *parent) : QWidget(parent), ui(new Ui::ModificationAppareil) {
    //Parametrage
    ui->setupUi(this);

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationAppareil::~ModificationAppareil() {
    delete ui;
}
