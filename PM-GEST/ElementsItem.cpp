#include "ElementsItem.h"
#include "ui_ElementsItem.h"

ElementsItem::ElementsItem(/*QString tagName, QImage imgLink, QString userName, bool actif, */) : QWidget(), ui(new Ui::ElementsItem) {
    ui->setupUi(this);
    QPainter painter;
    painter.drawEllipse(QPoint(0,0), 20, 20);
    QColor color;
    bool actif = false;

    actif ? color.setRgb(209,90,90) : color.setRgb(78,199,82);

    ui->graphActif->setScene(new QGraphicsScene());
    ui->graphActif->scene()->addEllipse(0,0,10,10, *new QPen(color), *new QBrush(color, Qt::SolidPattern));
}

ElementsItem::~ElementsItem() {
    delete ui;
}
