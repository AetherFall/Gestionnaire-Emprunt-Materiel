#ifndef MESSAGES_H
#define MESSAGES_H

#include <QString>

enum ERROR{
    DEP_CHAMPVIDE_TOADD = 0,
    DEP_NOSELECTION_TODELETE = 1,
    DEP_NOSELECTION_TOMODIFY = 2,
    DEP_NOITEM_TODELETE = 3,
    DEP_NOITEM_TOMODIFY = 4,
    DEP_CHAMPVIDE_TOMOD = 5,
    AFFECT_CHAMPVIDE = 6,
    AFFECT_EMP_INEXISTANT = 7,
    AFFECT_OBJ_INEXISTANT = 8,
    DESAFFECT_CHAMPVIDE = 9,
    DESAFFECT_OBJ_INEXISTANT = 8,
    DESAFFECT_NOLINK = 10,
    DEP_INTEGRITE_REFERENTIELLE = 11,
    EMP_INTEGRITE_REFERENTIELLE = 12,
    EMP_NOSELECTION_TODELETE = 13,
    EMP_NOITEM_TODELETE = 3,
    EMP_NOITEM_TOMODIFY = 4,
    EMP_NOSELECTION_TOMODIFY = 14,
    EMP_CHAMPVIDE_TOMOD = 15,
    EMP_CHAMPVIDE_TOADD = 16,
    TYP_CHAMPVIDE_TOADD = 16,
    TYP_INTEGRITE_REFERENTIELLE = 17,
    TYP_NOSELECTION_TODELETE = 18,
    TYP_NOITEM_TODELETE = 3,
    TYP_NOITEM_TOMODIFY = 4,
    TYP_CHAMPVIDE_TOMOD = 15,
    TYP_NOSELECTION_TOMODIFY = 19,
    OBJ_INTEGRITE_REFERENTIELLE = 20,
    OBJ_NOSELECTION_TODELETE = 21,
    OBJ_NOSELECTION_TOMODIFY = 22,
    OBJ_NOITEM_TODELETE = 3,
    OBJ_NOITEM_TOMODIFY = 4,
    OBJ_CHAMPVIDE_TOMOD = 15,
    OBJ_CHAMPVIDE_TOADD = 16,
    DEP_EXISTANT_TOADD = 23,
    EMP_EXISTANT_TOADD = 24,
    TYP_EXISTANT_TOADD = 25,
    OBJ_EXISTANT_TOADD = 26,
    DEP_EXISTANT_TOMOD = 27,
    EMP_EXISTANT_TOMOD = 28,
    TYP_EXISTANT_TOMOD = 29,
    OBJ_EXISTANT_TOMOD = 30,
    EMP_COMBOBOX_VIDE = 31,
    OBJ_COMBOBOX_VIDE = 32
};

enum TITLE{
    ERROR = 0,
    INFORMATION = 1,
    INTEGRITE_REFERENTIELLE = 2
};

enum INFORMATION {
    DEP_DELETE = 0,
    EMP_DELETE = 1,
    OBJ_DELETE = 2,
    TYP_DELETE = 3
};

static QString getTitle(enum TITLE type) {
    switch(type){
        case 0: return "Erreur";
        case 1: return "Information";
        case 2: return "Erreur d'intégrité référentielle";
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
        case 6: return "Veuillez remplir les champs afin de pouvoir affecter un appareil.";
        case 7: return "Le numéro d'employé est invalide, \n Veuillez vérifier cette erreur auprès d'un administrateur.";
        case 8: return "Le code de l'appareil n'existe pas, \n Veuillez vérifier cette erreur auprès d'un administrateur.";
        case 9: return "Veuillez remplir le champs [Code barre de l'objet], afin de pouvoir le désaffecter";
        case 10: return "Vous ne pouvez désafecter un appareil qui n'est pas déjà affecter au préalable.";
        case 11: return "Vous ne pouvez supprimer ce département tant qu'il y a un employé associé à ce département.";
        case 12: return "Vous ne pouvez supprimer cet employé tant qu'il est affecté à un appareil dans le registre. \n Dans la section Modification d'appareil décochez la case [En cours d'utilisation] de l'appareil.";
        case 13: return "Veuillez sélectionner un employé a supprimer.";
        case 14: return "Veuillez sélectionner un employé a modifier.";
        case 15: return "Veuillez remplir les champs afin de pouvoir effectuer une modification.";
        case 16: return "Veuillez remplir les champs afin de pouvoir effectuer un ajout.";
        case 17: return "Vous ne pouvez supprimer ce type d'appareil tant qu'il y a un appareil associé à ce type.";
        case 18: return "Veuillez sélectionner un type d'appareil à supprimer.";
        case 19: return "Veuillez sélectionner un type d'appareil à modifier.";
        case 20: return "Vous ne pouvez supprimer cet appareil tant qu'il est affecté à un employé dans le registre. \n Décochez la case [En cours d'utilisation] de l'appareil.";
        case 21: return "Veuillez sélectionner un appareil à supprimer.";
        case 22: return "Veuillez sélectionner un appareil à modifier.";
        case 23: return "Le département que vous tentez d'ajouter existe déjà.";
        case 24: return "L'employé que vous tentez d'ajouter existe déjà.";
        case 25: return "Le type d'appareil que vous tentez d'ajouter existe déjà.";
        case 26: return "L'appareil que vous tentez d'ajouter existe déjà.";
        case 27: return "Les modifications que vous tentez d'apporter existe déjà dans un autre département";
        case 28: return "Les modifications que vous tentez d'apporter existe déjà dans un autre employé";
        case 29: return "Les modifications que vous tentez d'apporter existe déjà dans un autre type d'appareil";
        case 30: return "Les modifications que vous tentez d'apporter existe déjà dans un autre appareil";
        case 31: return "Veuillez sélectionner un département principal auquel l'employé appartient.";
        case 32: return "Veuillez sélectionner un type d'appareil auquel cet appareil appartient.";
    }
}

static QString getInfo(enum INFORMATION type){
    switch(type){
        case 0: return "Souhaitez-vous vraiment supprimer ce departement?";
        case 1: return "Souhaitez-vous vraiment supprimer cet employé?";
        case 2: return "Souhaitez-vous vraiment supprimer cet appareil?";
        case 3: return "Souhaitez-vous vraiment supprimer ce type d'appareil?";
    }
}


#endif // MESSAGES_H
