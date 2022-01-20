#include "ModificationEmploye.h"
#include "ui_ModificationEmploye.h"

ModificationEmploye::ModificationEmploye(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationEmploye) {
    //Paramétrages
    ui->setupUi(this);
    this->BD = BD;

    //Connection Button
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));

}

ModificationEmploye::~ModificationEmploye() {
    delete ui;
    delete BD;
}
