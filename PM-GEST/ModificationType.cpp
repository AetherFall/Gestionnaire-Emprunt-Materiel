#include "ModificationType.h"
#include "ui_ModificationType.h"

ModificationType::ModificationType(QWidget *parent) : QWidget(parent), ui(new Ui::ModificationType) {
    ui->setupUi(this);

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(close()));
}

ModificationType::~ModificationType() {
    delete ui;
}
