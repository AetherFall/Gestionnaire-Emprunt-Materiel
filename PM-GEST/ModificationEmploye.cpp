#include "ModificationEmploye.h"
#include "ui_ModificationEmploye.h"

ModificationEmploye::ModificationEmploye(QWidget *parent) : QWidget(parent), ui(new Ui::ModificationEmploye) {
    //Paramétrages
    ui->setupUi(this);

    //Connection Button
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));

}

ModificationEmploye::~ModificationEmploye() {
    delete ui;
}
