QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CSVBD.cpp \
    Departement.cpp \
    Employe.cpp \
    InterfaceGestion.cpp \
    ModificationEmploye.cpp \
    ObjetType.cpp \
    Objets.cpp \
    Registre.cpp \
    main.cpp \
    FenPrincipale.cpp

HEADERS += \
    CSVBD.h \
    Departement.h \
    Employe.h \
    FenPrincipale.h \
    InterfaceGestion.h \
    ModificationEmploye.h \
    ObjetType.h \
    Objets.h \
    Registre.h

FORMS += \
    FenPrincipale.ui \
    InterfaceGestion.ui \
    ModificationEmploye.ui

TRANSLATIONS += \
    PM-GEST_fr_CA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/files/Departements.csv \
    res/files/Employe.csv \
    res/files/Objets.csv \
    res/files/Registre.csv \
    res/files/TypeObjets.csv \
    res/icons/PNG - Fond blanc/Ajout.png \
    res/icons/PNG - Fond blanc/Autre.png \
    res/icons/PNG - Fond blanc/Batiment.png \
    res/icons/PNG - Fond blanc/Cartes.png \
    res/icons/PNG - Fond blanc/Delete.png \
    res/icons/PNG - Fond blanc/Guilde.png \
    res/icons/PNG - Fond blanc/Modify.png \
    res/icons/PNG - Fond blanc/Personnage.png \
    res/icons/PNG - Fond blanc/Refresh.png \
    res/icons/PNG - Fond blanc/Territoire.png \
    res/icons/SVG/Ajout.svg \
    res/icons/SVG/Autre.svg \
    res/icons/SVG/Batiment.svg \
    res/icons/SVG/Cartes.svg \
    res/icons/SVG/Delete.svg \
    res/icons/SVG/Guilde.svg \
    res/icons/SVG/Modify.svg \
    res/icons/SVG/Personnage.svg \
    res/icons/SVG/Refresh.svg \
    res/icons/SVG/Territoire.svg \
    res/images/radio.png

RESOURCES += \
    ressources.qrc
