/********************************************************************************
** Form generated from reading UI file 'ElementsItem.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEMENTSITEM_H
#define UI_ELEMENTSITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElementsItem
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labImageTag;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphActif;
    QLabel *labTagName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labUserName;

    void setupUi(QWidget *ElementsItem)
    {
        if (ElementsItem->objectName().isEmpty())
            ElementsItem->setObjectName(QString::fromUtf8("ElementsItem"));
        ElementsItem->resize(100, 150);
        ElementsItem->setMinimumSize(QSize(100, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        ElementsItem->setFont(font);
        ElementsItem->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border-radius:50px;"));
        verticalLayout = new QVBoxLayout(ElementsItem);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 10, 0, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        labImageTag = new QLabel(ElementsItem);
        labImageTag->setObjectName(QString::fromUtf8("labImageTag"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labImageTag->sizePolicy().hasHeightForWidth());
        labImageTag->setSizePolicy(sizePolicy);
        labImageTag->setMinimumSize(QSize(25, 60));
        labImageTag->setMaximumSize(QSize(45, 100));
        labImageTag->setPixmap(QPixmap(QString::fromUtf8(":/images/res/images/radio.png")));
        labImageTag->setScaledContents(true);
        labImageTag->setAlignment(Qt::AlignCenter);
        labImageTag->setIndent(-1);

        horizontalLayout_2->addWidget(labImageTag);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        graphActif = new QGraphicsView(ElementsItem);
        graphActif->setObjectName(QString::fromUtf8("graphActif"));
        graphActif->setMinimumSize(QSize(20, 20));
        graphActif->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(graphActif);

        labTagName = new QLabel(ElementsItem);
        labTagName->setObjectName(QString::fromUtf8("labTagName"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labTagName->sizePolicy().hasHeightForWidth());
        labTagName->setSizePolicy(sizePolicy1);
        labTagName->setMinimumSize(QSize(100, 15));
        labTagName->setMaximumSize(QSize(200, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(11);
        labTagName->setFont(font1);
        labTagName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(labTagName);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        labUserName = new QLabel(ElementsItem);
        labUserName->setObjectName(QString::fromUtf8("labUserName"));
        labUserName->setMaximumSize(QSize(200, 20));
        labUserName->setFont(font1);
        labUserName->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labUserName);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(ElementsItem);

        QMetaObject::connectSlotsByName(ElementsItem);
    } // setupUi

    void retranslateUi(QWidget *ElementsItem)
    {
        ElementsItem->setWindowTitle(QCoreApplication::translate("ElementsItem", "Form", nullptr));
        labImageTag->setText(QString());
        labTagName->setText(QCoreApplication::translate("ElementsItem", "[ObjectName]", nullptr));
        labUserName->setText(QCoreApplication::translate("ElementsItem", "[UserName]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ElementsItem: public Ui_ElementsItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEMENTSITEM_H
