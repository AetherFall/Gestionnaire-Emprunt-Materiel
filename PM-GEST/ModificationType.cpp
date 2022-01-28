#include "ModificationType.h"
#include "ui_ModificationType.h"

ModificationType::ModificationType(CSVBD *BD, QWidget *parent) : QWidget(parent), ui(new Ui::ModificationType) {
    ui->setupUi(this);
    this->BD = BD;

    //Connection
    connect(ui->btnQuitter, SIGNAL(clicked()), this, SLOT(onCloseAction()));

    ui->btnQuitter->setFocusPolicy(Qt::NoFocus);
    ui->btnAdd->setFocusPolicy(Qt::NoFocus);
    ui->btnMod->setFocusPolicy(Qt::NoFocus);
    ui->btnDel->setFocusPolicy(Qt::NoFocus);
    ui->btnRefresh->setFocusPolicy(Qt::NoFocus);
}

ModificationType::~ModificationType() {
    delete ui;
    delete BD;
}

void ModificationType::onCloseAction() {
    emit qApp->applicationVersionChanged();
    this->close();
}
