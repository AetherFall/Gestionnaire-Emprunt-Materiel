/********************************************************************************
** Form generated from reading UI file 'InterfaceGestion.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEGESTION_H
#define UI_INTERFACEGESTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceGestion
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QColumnView *columnView;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnLstEmp;
    QPushButton *btnLstObjets;
    QPushButton *btnLstDepartement;
    QPushButton *btnLstTypeObjets;
    QPushButton *btnQuitter;

    void setupUi(QWidget *InterfaceGestion)
    {
        if (InterfaceGestion->objectName().isEmpty())
            InterfaceGestion->setObjectName(QString::fromUtf8("InterfaceGestion"));
        InterfaceGestion->resize(1151, 611);
        gridFrame = new QFrame(InterfaceGestion);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 1151, 611));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 30, 25, 25);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(25);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        columnView = new QColumnView(gridFrame);
        columnView->setObjectName(QString::fromUtf8("columnView"));
        columnView->setStyleSheet(QString::fromUtf8("background-color:#EBEBEB;\n"
"border-style:none;\n"
"border-radius:30px;"));

        horizontalLayout_2->addWidget(columnView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(100);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 350);
        btnLstEmp = new QPushButton(gridFrame);
        btnLstEmp->setObjectName(QString::fromUtf8("btnLstEmp"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnLstEmp->sizePolicy().hasHeightForWidth());
        btnLstEmp->setSizePolicy(sizePolicy);
        btnLstEmp->setMinimumSize(QSize(400, 45));
        btnLstEmp->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Emoji"));
        font.setPointSize(14);
        font.setBold(false);
        btnLstEmp->setFont(font);
        btnLstEmp->setCursor(QCursor(Qt::PointingHandCursor));
        btnLstEmp->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        verticalLayout_5->addWidget(btnLstEmp);

        btnLstObjets = new QPushButton(gridFrame);
        btnLstObjets->setObjectName(QString::fromUtf8("btnLstObjets"));
        sizePolicy.setHeightForWidth(btnLstObjets->sizePolicy().hasHeightForWidth());
        btnLstObjets->setSizePolicy(sizePolicy);
        btnLstObjets->setMinimumSize(QSize(400, 45));
        btnLstObjets->setMaximumSize(QSize(16777215, 16777215));
        btnLstObjets->setFont(font);
        btnLstObjets->setCursor(QCursor(Qt::PointingHandCursor));
        btnLstObjets->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        verticalLayout_5->addWidget(btnLstObjets);

        btnLstDepartement = new QPushButton(gridFrame);
        btnLstDepartement->setObjectName(QString::fromUtf8("btnLstDepartement"));
        sizePolicy.setHeightForWidth(btnLstDepartement->sizePolicy().hasHeightForWidth());
        btnLstDepartement->setSizePolicy(sizePolicy);
        btnLstDepartement->setMinimumSize(QSize(400, 45));
        btnLstDepartement->setMaximumSize(QSize(16777215, 16777215));
        btnLstDepartement->setFont(font);
        btnLstDepartement->setCursor(QCursor(Qt::PointingHandCursor));
        btnLstDepartement->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        verticalLayout_5->addWidget(btnLstDepartement);

        btnLstTypeObjets = new QPushButton(gridFrame);
        btnLstTypeObjets->setObjectName(QString::fromUtf8("btnLstTypeObjets"));
        sizePolicy.setHeightForWidth(btnLstTypeObjets->sizePolicy().hasHeightForWidth());
        btnLstTypeObjets->setSizePolicy(sizePolicy);
        btnLstTypeObjets->setMinimumSize(QSize(400, 45));
        btnLstTypeObjets->setMaximumSize(QSize(16777215, 16777215));
        btnLstTypeObjets->setFont(font);
        btnLstTypeObjets->setCursor(QCursor(Qt::PointingHandCursor));
        btnLstTypeObjets->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        verticalLayout_5->addWidget(btnLstTypeObjets);


        verticalLayout_2->addLayout(verticalLayout_5);

        btnQuitter = new QPushButton(gridFrame);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        sizePolicy.setHeightForWidth(btnQuitter->sizePolicy().hasHeightForWidth());
        btnQuitter->setSizePolicy(sizePolicy);
        btnQuitter->setMinimumSize(QSize(0, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(16);
        font1.setBold(false);
        btnQuitter->setFont(font1);
        btnQuitter->setCursor(QCursor(Qt::PointingHandCursor));
        btnQuitter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color: rgb(209, 122, 90);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(176, 103, 76);\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnQuitter);


        verticalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(InterfaceGestion);

        QMetaObject::connectSlotsByName(InterfaceGestion);
    } // setupUi

    void retranslateUi(QWidget *InterfaceGestion)
    {
        InterfaceGestion->setWindowTitle(QCoreApplication::translate("InterfaceGestion", "Form", nullptr));
        btnLstEmp->setText(QCoreApplication::translate("InterfaceGestion", "Listes des employ\303\251s autoris\303\251 aux emprunts", nullptr));
        btnLstObjets->setText(QCoreApplication::translate("InterfaceGestion", "Liste des appareils inventori\303\251", nullptr));
        btnLstDepartement->setText(QCoreApplication::translate("InterfaceGestion", "Liste des d\303\251partements", nullptr));
        btnLstTypeObjets->setText(QCoreApplication::translate("InterfaceGestion", "Types d'appareils potentiel", nullptr));
        btnQuitter->setText(QCoreApplication::translate("InterfaceGestion", "Quitter l'interface de gestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceGestion: public Ui_InterfaceGestion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEGESTION_H
