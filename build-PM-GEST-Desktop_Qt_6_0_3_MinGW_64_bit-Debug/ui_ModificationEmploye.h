/********************************************************************************
** Form generated from reading UI file 'ModificationEmploye.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICATIONEMPLOYE_H
#define UI_MODIFICATIONEMPLOYE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_ModificationEmploye
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
    QLabel *label_2;
    QLineEdit *txfEmploye;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *txfNom;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QComboBox *cbxDepartement;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QCheckBox *chbGestion;
    QPushButton *btnQuitter;

    void setupUi(QWidget *ModificationEmploye)
    {
        if (ModificationEmploye->objectName().isEmpty())
            ModificationEmploye->setObjectName(QString::fromUtf8("ModificationEmploye"));
        ModificationEmploye->resize(1221, 671);
        ModificationEmploye->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        gridFrame = new QFrame(ModificationEmploye);
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
        tblEmploye->setMaximumSize(QSize(650, 16777215));
        QFont font;
        font.setPointSize(11);
        tblEmploye->setFont(font);
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
        tblEmploye->setFrameShape(QFrame::NoFrame);
        tblEmploye->setFrameShadow(QFrame::Sunken);
        tblEmploye->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblEmploye->setAutoScroll(true);
        tblEmploye->setAutoScrollMargin(15);
        tblEmploye->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblEmploye->setProperty("showDropIndicator", QVariant(false));
        tblEmploye->setDragDropOverwriteMode(false);
        tblEmploye->setSelectionMode(QAbstractItemView::SingleSelection);
        tblEmploye->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblEmploye->setShowGrid(false);
        tblEmploye->setGridStyle(Qt::SolidLine);
        tblEmploye->horizontalHeader()->setVisible(false);
        tblEmploye->horizontalHeader()->setDefaultSectionSize(140);
        tblEmploye->horizontalHeader()->setHighlightSections(false);
        tblEmploye->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tblEmploye->horizontalHeader()->setStretchLastSection(false);
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
        verticalLayout_5->setContentsMargins(-1, 0, -1, 50);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 220, 50);
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

        label_2 = new QLabel(gridFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(13);
        label_2->setFont(font1);

        verticalLayout_4->addWidget(label_2);

        txfEmploye = new QLineEdit(gridFrame);
        txfEmploye->setObjectName(QString::fromUtf8("txfEmploye"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txfEmploye->sizePolicy().hasHeightForWidth());
        txfEmploye->setSizePolicy(sizePolicy);
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
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label);

        txfNom = new QLineEdit(gridFrame);
        txfNom->setObjectName(QString::fromUtf8("txfNom"));
        sizePolicy.setHeightForWidth(txfNom->sizePolicy().hasHeightForWidth());
        txfNom->setSizePolicy(sizePolicy);
        txfNom->setMinimumSize(QSize(480, 30));
        txfNom->setMaximumSize(QSize(480, 30));
        txfNom->setFont(font2);
        txfNom->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	border: 2px solid rgb(112, 112, 112);\n"
"	border-radius: 15px;\n"
"	background-color: white;\n"
"	padding-left:20px;\n"
"}"));
        txfNom->setFrame(true);

        verticalLayout_3->addWidget(txfNom);


        verticalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_6->setContentsMargins(-1, 35, -1, -1);
        label_3 = new QLabel(gridFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 49));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(label_3);

        cbxDepartement = new QComboBox(gridFrame);
        cbxDepartement->setObjectName(QString::fromUtf8("cbxDepartement"));
        cbxDepartement->setMinimumSize(QSize(480, 30));
        cbxDepartement->setMaximumSize(QSize(480, 30));
        cbxDepartement->setFont(font2);
        cbxDepartement->setAutoFillBackground(false);
        cbxDepartement->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border: 2px solid rgb(112, 112, 112);\n"
"border-radius: 15px;\n"
"padding-left:20px;\n"
"background-color:white;\n"
"color:black;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border: 2px solid rgb(112, 112, 112);\n"
"top:-2px;\n"
"right:-2px;\n"
"width:25px;\n"
"height:25px;\n"
"border-radius: 14px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image: url(:/icons/res/icons/SVG/Autre.svg);\n"
"	width:19px;\n"
"	top:2px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border-style:none;\n"
"	width:450px;\n"
"}\n"
""));
        cbxDepartement->setEditable(false);
        cbxDepartement->setFrame(true);
        cbxDepartement->setModelColumn(0);

        verticalLayout_6->addWidget(cbxDepartement);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, 45, -1);
        label_4 = new QLabel(gridFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(400, 49));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(label_4);

        chbGestion = new QCheckBox(gridFrame);
        chbGestion->setObjectName(QString::fromUtf8("chbGestion"));
        chbGestion->setMaximumSize(QSize(35, 50));
        chbGestion->setCursor(QCursor(Qt::PointingHandCursor));
        chbGestion->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"border: 2px solid rgb(112, 112, 112);\n"
"width:28px;\n"
"height:28px;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/icons/res/icons/SVG/Check.svg);\n"
"	background-color:white;\n"
"	color:white;\n"
"	text-decoration:none;\n"
"}"));
        chbGestion->setChecked(false);
        chbGestion->setTristate(false);

        horizontalLayout_4->addWidget(chbGestion);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_5);

        btnQuitter = new QPushButton(gridFrame);
        btnQuitter->setObjectName(QString::fromUtf8("btnQuitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnQuitter->sizePolicy().hasHeightForWidth());
        btnQuitter->setSizePolicy(sizePolicy1);
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


        retranslateUi(ModificationEmploye);

        cbxDepartement->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ModificationEmploye);
    } // setupUi

    void retranslateUi(QWidget *ModificationEmploye)
    {
        ModificationEmploye->setWindowTitle(QCoreApplication::translate("ModificationEmploye", "Form", nullptr));
        txfRecherche->setText(QString());
        txfRecherche->setPlaceholderText(QCoreApplication::translate("ModificationEmploye", "Rechercher...", nullptr));
        btnRefresh->setText(QString());
        btnAdd->setText(QString());
        btnDel->setText(QString());
        btnMod->setText(QString());
        label_2->setText(QCoreApplication::translate("ModificationEmploye", "Code de l'employ\303\251", nullptr));
        txfEmploye->setText(QString());
        label->setText(QCoreApplication::translate("ModificationEmploye", "Pr\303\251nom et nom de l'employ\303\251", nullptr));
        txfNom->setInputMask(QString());
        txfNom->setText(QString());
        label_3->setText(QCoreApplication::translate("ModificationEmploye", "D\303\251partement de l'employ\303\251", nullptr));
        cbxDepartement->setCurrentText(QString());
        cbxDepartement->setPlaceholderText(QString());
        label_4->setText(QCoreApplication::translate("ModificationEmploye", "\303\200 acc\303\250s aux outils de gestion de cette application", nullptr));
        chbGestion->setText(QString());
        btnQuitter->setText(QCoreApplication::translate("ModificationEmploye", "Retour \303\240 l'interface de gestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificationEmploye: public Ui_ModificationEmploye {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICATIONEMPLOYE_H
