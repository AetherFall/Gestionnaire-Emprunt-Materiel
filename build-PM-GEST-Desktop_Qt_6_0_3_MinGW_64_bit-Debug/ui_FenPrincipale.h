/********************************************************************************
** Form generated from reading UI file 'FenPrincipale.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENPRINCIPALE_H
#define UI_FENPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenPrincipale
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *backgroundTab;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLineEdit *txfEmploye;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *txfObjet;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAffect;
    QPushButton *btnDeAffect;
    QPushButton *btnQuitter;

    void setupUi(QWidget *FenPrincipale)
    {
        if (FenPrincipale->objectName().isEmpty())
            FenPrincipale->setObjectName(QString::fromUtf8("FenPrincipale"));
        FenPrincipale->resize(1141, 598);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FenPrincipale->sizePolicy().hasHeightForWidth());
        FenPrincipale->setSizePolicy(sizePolicy);
        FenPrincipale->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));
        gridFrame = new QFrame(FenPrincipale);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(-10, -10, 1151, 611));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 30, 25, 25);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(25);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        backgroundTab = new QGraphicsView(gridFrame);
        backgroundTab->setObjectName(QString::fromUtf8("backgroundTab"));
        backgroundTab->setEnabled(false);
        backgroundTab->setStyleSheet(QString::fromUtf8("background-color:rgb(235, 235, 235);\n"
"border-radius:25px;"));

        horizontalLayout_2->addWidget(backgroundTab);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 100, -1, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 100);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(-1, 25, -1, 25);
        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(13);
        label_2->setFont(font);

        verticalLayout_4->addWidget(label_2);

        txfEmploye = new QLineEdit(gridFrame);
        txfEmploye->setObjectName(QString::fromUtf8("txfEmploye"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txfEmploye->sizePolicy().hasHeightForWidth());
        txfEmploye->setSizePolicy(sizePolicy1);
        txfEmploye->setMinimumSize(QSize(480, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(11);
        txfEmploye->setFont(font1);
        txfEmploye->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 2px solid rgb(112, 112, 112);\n"
"	border-radius: 15px;\n"
"	background-color: white;\n"
"	padding-left:20px;\n"
"}"));

        verticalLayout_4->addWidget(txfEmploye);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(-1, 35, -1, -1);
        label = new QLabel(gridFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 49));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label);

        txfObjet = new QLineEdit(gridFrame);
        txfObjet->setObjectName(QString::fromUtf8("txfObjet"));
        sizePolicy1.setHeightForWidth(txfObjet->sizePolicy().hasHeightForWidth());
        txfObjet->setSizePolicy(sizePolicy1);
        txfObjet->setMinimumSize(QSize(480, 30));
        txfObjet->setFont(font1);
        txfObjet->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 2px solid rgb(112, 112, 112);\n"
"	border-radius: 15px;\n"
"	background-color: white;\n"
"	padding-left:20px;\n"
"}"));
        txfObjet->setFrame(true);

        verticalLayout_3->addWidget(txfObjet);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 40, -1, -1);
        btnAffect = new QPushButton(gridFrame);
        btnAffect->setObjectName(QString::fromUtf8("btnAffect"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(30);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnAffect->sizePolicy().hasHeightForWidth());
        btnAffect->setSizePolicy(sizePolicy2);
        btnAffect->setMinimumSize(QSize(0, 45));
        btnAffect->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI Emoji"));
        font2.setPointSize(17);
        font2.setBold(false);
        btnAffect->setFont(font2);
        btnAffect->setCursor(QCursor(Qt::PointingHandCursor));
        btnAffect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        horizontalLayout_3->addWidget(btnAffect);

        btnDeAffect = new QPushButton(gridFrame);
        btnDeAffect->setObjectName(QString::fromUtf8("btnDeAffect"));
        sizePolicy2.setHeightForWidth(btnDeAffect->sizePolicy().hasHeightForWidth());
        btnDeAffect->setSizePolicy(sizePolicy2);
        btnDeAffect->setMinimumSize(QSize(0, 45));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(17);
        btnDeAffect->setFont(font3);
        btnDeAffect->setCursor(QCursor(Qt::PointingHandCursor));
        btnDeAffect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:22px;\n"
"background-color:rgb(29, 67, 219);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(22, 50, 162);\n"
"}"));

        horizontalLayout_3->addWidget(btnDeAffect);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_5);

        btnQuitter = new QPushButton(gridFrame);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnQuitter->sizePolicy().hasHeightForWidth());
        btnQuitter->setSizePolicy(sizePolicy3);
        btnQuitter->setMinimumSize(QSize(0, 45));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(16);
        font4.setBold(false);
        btnQuitter->setFont(font4);
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


        retranslateUi(FenPrincipale);

        QMetaObject::connectSlotsByName(FenPrincipale);
    } // setupUi

    void retranslateUi(QWidget *FenPrincipale)
    {
        FenPrincipale->setWindowTitle(QCoreApplication::translate("FenPrincipale", "FenPrincipale", nullptr));
        label_2->setText(QCoreApplication::translate("FenPrincipale", "Veuillez scanner votre carte d'employ\303\251", nullptr));
        label->setText(QCoreApplication::translate("FenPrincipale", "Veuillez scanner le code barre de l'objet", nullptr));
        txfObjet->setInputMask(QString());
        btnAffect->setText(QCoreApplication::translate("FenPrincipale", "Affecter", nullptr));
        btnDeAffect->setText(QCoreApplication::translate("FenPrincipale", "D\303\251saffecter", nullptr));
        btnQuitter->setText(QCoreApplication::translate("FenPrincipale", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenPrincipale: public Ui_FenPrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENPRINCIPALE_H