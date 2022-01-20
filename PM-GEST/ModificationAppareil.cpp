#include "ModificationAppareil.h"
#include "ui_ModificationAppareil.h"

ModificationAppareil::ModificationAppareil(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationAppareil) {
    //Parametrage
    ui->setupUi(this);
    this->BD = BD;

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationAppareil::~ModificationAppareil() {
    delete ui;
    delete BD;
}
