#include "ModificationType.h"
#include "ui_ModificationType.h"

ModificationType::ModificationType(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationType) {
    ui->setupUi(this);
    this->BD = BD;

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationType::~ModificationType() {
    delete ui;
    delete BD;
}
