/********************************************************************************
** Form generated from reading UI file 'ModificationDepartement.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONDEPARTEMENT_H
#define UI_MODIFICATIONDEPARTEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModificationDepartement
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *txfRecherche;
    QTableWidget *tblDepartement;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRefresh;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QPushButton *btnMod;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *txfEmploye;
    QPushButton *btnQuitter;

    void setupUi(QWidget *ModificationDepartement)
    {
        if (ModificationDepartement->objectName().isEmpty())
            ModificationDepartement->setObjectName(QString::fromUtf8("ModificationDepartement"));
        ModificationDepartement->resize(1221, 671);
        ModificationDepartement->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        gridFrame = new QFrame(ModificationDepartement);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 1221, 671));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(30, 30, 25, 25);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(25);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalWidget = new QWidget(gridFrame);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color:#EBEBEB;\n"
""));
        verticalLayout_7 = new QVBoxLayout(verticalWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 10, 0, 0);
        txfRecherche = new QLineEdit(verticalWidget);
        txfRecherche->setObjectName(QString::fromUtf8("txfRecherche"));
        txfRecherche->setMinimumSize(QSize(0, 25));
        txfRecherche->setMaximumSize(QSize(350, 50));
        txfRecherche->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border-style:none;\n"
"	border-radius: 12px;\n"
"	background-color: #B9B9B9;\n"
"	padding-left:20px;\n"
"	margin-left:10px;\n"
"	color:black;\n"
"}"));

        verticalLayout_7->addWidget(txfRecherche);

        tblDepartement = new QTableWidget(verticalWidget);
        tblDepartement->setObjectName(QString::fromUtf8("tblDepartement"));
        tblDepartement->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tblDepartement->sizePolicy().hasHeightForWidth());
        tblDepartement->setSizePolicy(sizePolicy);
        tblDepartement->setMinimumSize(QSize(650, 0));
        tblDepartement->setMaximumSize(QSize(670, 16777215));
        QFont font;
        font.setPointSize(12);
        tblDepartement->setFont(font);
        tblDepartement->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"border-style:none;\n"
"color:black;\n"
"}\n"
"\n"
"QTableWidget::item{\n"
"background-color:#D8D7D7;\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"background-color:#727171;\n"
"border-style:none;\n"
"font: 12pt \"Segoe UI\";\n"
"color:white;\n"
"}\n"
"\n"
"QTableWidget::item:selected{\n"
"	border-style:none;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"  QScrollBar::handle:vertical {\n"
"        background-color:rgba(127, 127, 127, 255);\n"
"    }\n"
"\n"
"QScrollBar{\n"
"	width:15px;\n"
"	background-color:rgba(193, 193, 193, 255);\n"
"	border-radius:5px;\n"
"	margin-right:5px;\n"
"}\n"
"\n"
"QScrollBar::handle{\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"    QScrollBar::add-line:vertical {\n"
"		border-style:none;\n"
"        subcontrol-position: bottom;\n"
"        subcontrol-origin: margin;\n"
"		border-radius:5px;\n"
"    }\n"
"    QScrollBar::sub-line:vertical {\n"
"        background: #C1C1C1;\n"
"        subcontrol-position: top;\n"
"		border-radius:5px;\n"
"        subcontrol-origin:"
                        " margin;\n"
"		margin-right:5px;\n"
"    }\n"
"\n"
"QTableWidget::item:alternate{\n"
"	background-color:#B2B2B2;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color:#727171;\n"
"	color:white;\n"
"}"));
        tblDepartement->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tblDepartement->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDepartement->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tblDepartement->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDepartement->setProperty("showDropIndicator", QVariant(false));
        tblDepartement->setDragDropOverwriteMode(false);
        tblDepartement->setDefaultDropAction(Qt::IgnoreAction);
        tblDepartement->setAlternatingRowColors(true);
        tblDepartement->setSelectionMode(QAbstractItemView::SingleSelection);
        tblDepartement->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblDepartement->setTextElideMode(Qt::ElideMiddle);
        tblDepartement->setShowGrid(false);
        tblDepartement->horizontalHeader()->setVisible(false);
        tblDepartement->horizontalHeader()->setHighlightSections(false);
        tblDepartement->verticalHeader()->setVisible(false);
        tblDepartement->verticalHeader()->setHighlightSections(false);

        verticalLayout_7->addWidget(tblDepartement);


        horizontalLayout_2->addWidget(verticalWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, 200);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 220, 88);
        btnRefresh = new QPushButton(gridFrame);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMinimumSize(QSize(60, 60));
        btnRefresh->setMaximumSize(QSize(60, 60));
        btnRefresh->setCursor(QCursor(Qt::PointingHandCursor));
        btnRefresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:0px;\n"
"border-style: none;\n"
"background-color:#3737F9;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color:#2323A4;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Refresh.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnRefresh->setIcon(icon);
        btnRefresh->setIconSize(QSize(30, 30));
#if QT_CONFIG(shortcut)
        btnRefresh->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(btnRefresh);

        btnAdd = new QPushButton(gridFrame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(60, 60));
        btnAdd->setMaximumSize(QSize(60, 60));
        btnAdd->setCursor(QCursor(Qt::PointingHandCursor));
        btnAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:0px;\n"
"border-style: none;\n"
"background-color:#09AF25;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color:#0E8522;\n"
"}\n"
"\n"
"QPushButton::!enabled{\n"
"	background-color:rgb(80, 0, 0);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Ajout.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnAdd->setIcon(icon1);
        btnAdd->setIconSize(QSize(30, 30));
#if QT_CONFIG(shortcut)
        btnAdd->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(btnAdd);

        btnDel = new QPushButton(gridFrame);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        btnDel->setMinimumSize(QSize(60, 60));
        btnDel->setMaximumSize(QSize(60, 60));
        btnDel->setCursor(QCursor(Qt::PointingHandCursor));
        btnDel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:0px;\n"
"border-style: none;\n"
"background-color:#FF0046;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color:#CE0038;\n"
"}\n"
"\n"
"QPushButton::!enabled{\n"
"	background-color:rgb(80, 0, 0);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Delete2.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnDel->setIcon(icon2);
        btnDel->setIconSize(QSize(35, 35));
#if QT_CONFIG(shortcut)
        btnDel->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(btnDel);

        btnMod = new QPushButton(gridFrame);
        btnMod->setObjectName(QString::fromUtf8("btnMod"));
        btnMod->setMinimumSize(QSize(60, 60));
        btnMod->setMaximumSize(QSize(60, 60));
        btnMod->setCursor(QCursor(Qt::PointingHandCursor));
        btnMod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:0px;\n"
"border-style: none;\n"
"background-color:#F99237;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color:#D27E35;\n"
"}\n"
"\n"
"QPushButton::!enabled{\n"
"	background-color:rgb(80, 0, 0);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Modify.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnMod->setIcon(icon3);
        btnMod->setIconSize(QSize(30, 30));
#if QT_CONFIG(shortcut)
        btnMod->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(btnMod);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 90, -1, 0);
        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(13);
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        txfEmploye = new QLineEdit(gridFrame);
        txfEmploye->setObjectName(QString::fromUtf8("txfEmploye"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txfEmploye->sizePolicy().hasHeightForWidth());
        txfEmploye->setSizePolicy(sizePolicy1);
        txfEmploye->setMinimumSize(QSize(480, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(11);
        txfEmploye->setFont(font2);
        txfEmploye->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 2px solid rgb(112, 112, 112);\n"
"	border-radius: 15px;\n"
"	background-color: white;\n"
"	padding-left:20px;\n"
"}"));

        verticalLayout_3->addWidget(txfEmploye);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_5);

        btnQuitter = new QPushButton(gridFrame);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnQuitter->sizePolicy().hasHeightForWidth());
        btnQuitter->setSizePolicy(sizePolicy2);
        btnQuitter->setMinimumSize(QSize(0, 45));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(16);
        font3.setBold(false);
        btnQuitter->setFont(font3);
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


        retranslateUi(ModificationDepartement);

        QMetaObject::connectSlotsByName(ModificationDepartement);
    } // setupUi

    void retranslateUi(QWidget *ModificationDepartement)
    {
        ModificationDepartement->setWindowTitle(QCoreApplication::translate("ModificationDepartement", "Form", nullptr));
        txfRecherche->setText(QString());
        txfRecherche->setPlaceholderText(QCoreApplication::translate("ModificationDepartement", "Rechercher...", nullptr));
        btnRefresh->setText(QString());
        btnAdd->setText(QString());
        btnDel->setText(QString());
        btnMod->setText(QString());
        label_2->setText(QCoreApplication::translate("ModificationDepartement", "Nom du d\303\251partement", nullptr));
        txfEmploye->setText(QString());
        btnQuitter->setText(QCoreApplication::translate("ModificationDepartement", "Retour \303\240 l'interface de gestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificationDepartement: public Ui_ModificationDepartement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONDEPARTEMENT_H
