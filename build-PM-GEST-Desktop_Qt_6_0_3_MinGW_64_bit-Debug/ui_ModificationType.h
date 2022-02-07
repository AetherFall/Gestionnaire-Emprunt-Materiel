/********************************************************************************
** Form generated from reading UI file 'ModificationType.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONTYPE_H
#define UI_MODIFICATIONTYPE_H

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

class Ui_ModificationType
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *txfRecherche;
    QTableWidget *tblEmploye;
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
    QVBoxLayout *verticalLayout_6;
    QLabel *labImage;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *btnRecherche;
    QPushButton *btnQuitter;

    void setupUi(QWidget *ModificationType)
    {
        if (ModificationType->objectName().isEmpty())
            ModificationType->setObjectName(QString::fromUtf8("ModificationType"));
        ModificationType->resize(1221, 671);
        ModificationType->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        gridFrame = new QFrame(ModificationType);
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
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 10, 0, -1);
        txfRecherche = new QLineEdit(verticalWidget);
        txfRecherche->setObjectName(QString::fromUtf8("txfRecherche"));
        txfRecherche->setMinimumSize(QSize(0, 25));
        txfRecherche->setMaximumSize(QSize(350, 50));
        txfRecherche->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border-style:none;\n"
"	border-radius: 12px;\n"
"	background-color: #B9B9B9;\n"
"	padding-left:20px;\n"
"	margin-left:9px;\n"
"	color:black;\n"
"}"));

        verticalLayout_7->addWidget(txfRecherche);

        tblEmploye = new QTableWidget(verticalWidget);
        tblEmploye->setObjectName(QString::fromUtf8("tblEmploye"));
        tblEmploye->setMinimumSize(QSize(650, 0));
        tblEmploye->setMaximumSize(QSize(670, 16777215));
        tblEmploye->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
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
        tblEmploye->setFrameShape(QFrame::StyledPanel);
        tblEmploye->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblEmploye->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblEmploye->setProperty("showDropIndicator", QVariant(false));
        tblEmploye->setDragDropOverwriteMode(false);
        tblEmploye->setSelectionMode(QAbstractItemView::SingleSelection);
        tblEmploye->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblEmploye->setTextElideMode(Qt::ElideMiddle);
        tblEmploye->setShowGrid(false);
        tblEmploye->horizontalHeader()->setHighlightSections(false);
        tblEmploye->verticalHeader()->setVisible(false);
        tblEmploye->verticalHeader()->setHighlightSections(false);

        verticalLayout_7->addWidget(tblEmploye);


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
        verticalLayout_5->setContentsMargins(-1, 0, -1, 61);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 220, 21);
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
        btnRefresh->setShortcut(QString::fromUtf8("F5"));
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
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Ajout.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnAdd->setIcon(icon1);
        btnAdd->setIconSize(QSize(30, 30));
#if QT_CONFIG(shortcut)
        btnAdd->setShortcut(QString::fromUtf8("F6"));
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
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Delete2.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnDel->setIcon(icon2);
        btnDel->setIconSize(QSize(35, 35));

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
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/res/icons/SVG/Modify.svg"), QSize(), QIcon::Normal, QIcon::On);
        btnMod->setIcon(icon3);
        btnMod->setIconSize(QSize(30, 30));
#if QT_CONFIG(shortcut)
        btnMod->setShortcut(QString::fromUtf8("Ctrl+S"));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(btnMod);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 100, -1, 24);
        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(13);
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

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

        verticalLayout_3->addWidget(txfEmploye);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 20, -1, 100);
        labImage = new QLabel(gridFrame);
        labImage->setObjectName(QString::fromUtf8("labImage"));
        labImage->setMaximumSize(QSize(480, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setItalic(true);
        labImage->setFont(font2);
        labImage->setStyleSheet(QString::fromUtf8("padding-left:150px;\n"
"color:black;"));

        verticalLayout_6->addWidget(labImage);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(30);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 10, -1, 10);
        label_3 = new QLabel(gridFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(250, 20));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        btnRecherche = new QPushButton(gridFrame);
        btnRecherche->setObjectName(QString::fromUtf8("btnRecherche"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnRecherche->sizePolicy().hasHeightForWidth());
        btnRecherche->setSizePolicy(sizePolicy2);
        btnRecherche->setMinimumSize(QSize(0, 30));
        btnRecherche->setMaximumSize(QSize(200, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(16);
        font3.setBold(false);
        btnRecherche->setFont(font3);
        btnRecherche->setCursor(QCursor(Qt::PointingHandCursor));
        btnRecherche->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:15px;\n"
"background-color: #1D43DB;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:#2323A4;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(btnRecherche);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_2->addLayout(verticalLayout_5);

        btnQuitter = new QPushButton(gridFrame);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        sizePolicy2.setHeightForWidth(btnQuitter->sizePolicy().hasHeightForWidth());
        btnQuitter->setSizePolicy(sizePolicy2);
        btnQuitter->setMinimumSize(QSize(0, 45));
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


        retranslateUi(ModificationType);

        QMetaObject::connectSlotsByName(ModificationType);
    } // setupUi

    void retranslateUi(QWidget *ModificationType)
    {
        ModificationType->setWindowTitle(QCoreApplication::translate("ModificationType", "ModificationType", nullptr));
        txfRecherche->setText(QString());
        txfRecherche->setPlaceholderText(QCoreApplication::translate("ModificationType", "Rechercher...", nullptr));
        btnRefresh->setText(QString());
        btnAdd->setText(QString());
        btnDel->setText(QString());
#if QT_CONFIG(shortcut)
        btnDel->setShortcut(QCoreApplication::translate("ModificationType", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        btnMod->setText(QString());
        label_2->setText(QCoreApplication::translate("ModificationType", "Nom du type d'appareil", nullptr));
        txfEmploye->setText(QString());
        labImage->setText(QCoreApplication::translate("ModificationType", "Lien image", nullptr));
        label_3->setText(QCoreApplication::translate("ModificationType", "Image descriptive de l'appareil", nullptr));
        btnRecherche->setText(QCoreApplication::translate("ModificationType", "Rechercher...", nullptr));
#if QT_CONFIG(shortcut)
        btnRecherche->setShortcut(QCoreApplication::translate("ModificationType", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        btnQuitter->setText(QCoreApplication::translate("ModificationType", "Retour \303\240 l'interface de gestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificationType: public Ui_ModificationType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONTYPE_H
