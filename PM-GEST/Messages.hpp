#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>

enum ERROR{
    DEP_CHAMPVIDE_TOADD = 0,
    DEP_NOSELECTION_TODELETE = 1,
    DEP_NOSELECTION_TOMODIFY = 2,
    DEP_NOITEM_TODELETE = 3,
    DEP_NOITEM_TOMODIFY = 4,
    DEP_CHAMPVIDE_TOMOD = 5
};

enum TITLE{
    ERROR = 0,
    INFORMATION = 1
};

enum INFORMATION {
    DEP_DELETE = 0
};

static QString getTitle(enum TITLE type) {
    switch(type){
        case 0: return "Erreur";
        case 1: return "Information";
    }
}

static QString getError(enum ERROR type){
    switch(type){
        case 0: return "Veuillez saisir un nom de departement a ajouter";
        case 1: return "Veuillez sélectionner un département a supprimer.";
        case 2: return "Veuillez sélectionner un département a modifier.";
        case 3: return "Il n'y a aucun item a supprimer.";
        case 4: return "Il n'y a aucun item a modifier.";
        case 5: return "Veuillez saisir un nom de departement pour effectuer la modification.";
    }
}

static QString getInfo(enum INFORMATION type){
    switch(type){
        case 0: return "Souhaitez-vous vraiment supprimer ce departement?";
    }
}


#endif // MESSAGES_H
