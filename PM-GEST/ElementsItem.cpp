#include "ElementsItem.h"
#include "ui_ElementsItem.h"

ElementsItem::ElementsItem(QString tagName, QString imgLink, QString userName, bool actif) : QWidget(), ui(new Ui::ElementsItem) {
    ui->setupUi(this);
    QColor color;

    actif ? color.setRgb(209,90,90) : color.setRgb(78,199,82);

    ui->graphActif->setScene(new QGraphicsScene());
    ui->graphActif->scene()->addEllipse(0,0,10,10, *new QPen(color), *new QBrush(color, Qt::SolidPattern));

    ui->labTagName->setText(tagName);
    ui->labUserName->setText(userName);
    ui->labImageTag->setPixmap(QPixmap(imgLink));
}

ElementsItem::~ElementsItem() {
    delete ui;
}

QString ElementsItem::getTagName()
{
    return ui->labTagName->text();
}
