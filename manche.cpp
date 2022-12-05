/**
 * @file manche.cpp
 * @author Rémi
 */

#include "manche.h"

void lancement_manche(Joueurs& struct_joueurs) {
    char lettre_joueur = ' ';
    char mot_manche[MAX_LETTRES_MOT+1] = "";
    char mot_propose[MAX_LETTRES_MOT+1] = "";
    for(uint h=0; h<MAX_LETTRES_MOT; h++) {
        for (uint i = 0; i < struct_joueurs.nb_total; i++) {
            cout << i + 1 << struct_joueurs.ordre_passage[i] << ", (";
            cout << mot_manche;
            cout << ") > ";
            if (struct_joueurs.ordre_passage[i] == 'H') {
                cin >> lettre_joueur;
            }
            else if (struct_joueurs.ordre_passage[i] == 'R') {
                lettre_joueur = choix_lettre_robot(mot_manche);
                cout << lettre_joueur << endl;
            }
            else {
                cout << "Erreur pour la manche. indice joueur : " << i << endl;
            }

            lettre_joueur = (char)toupper(lettre_joueur);
            if (lettre_joueur == '?') {
                cout << indice_joueur_precedent(struct_joueurs, i+1) << struct_joueurs.ordre_passage[indice_joueur_precedent(struct_joueurs, i)] << " saisir le mot > ";
                cin >> mot_propose;
                verifie_qui_perd(struct_joueurs, mot_propose, i);
                return;
            }
            else {
                strcpy(mot_manche,ajoute_lettre_au_mot(mot_manche, lettre_joueur));
            }
            if(!le_mot_peut_continuer(mot_manche)) {
                cout << "le mot " << mot_manche << " existe, " << i+1 << struct_joueurs.ordre_passage[i] <<
                     " prend un quart de singe" << endl;
                addQuartDeSinge(struct_joueurs, i);
                return;
            }
        }
    }
    cout << "Mot de plus de 25 lettres impossible" << endl;
}

void verifie_qui_perd(Joueurs& struct_joueurs, const char mot_propose[], const uint indice_joueur) {
    uint ind_joueur_perdant;
    bool existence_mot = recherche_existence_mot(mot_propose);
    if (existence_mot) {
        cout << "Le mot " << mot_propose << " existe, " << indice_joueur+1 << struct_joueurs.ordre_passage[indice_joueur] <<
             " prend un quart de singe" << endl;
        addQuartDeSinge(struct_joueurs, indice_joueur);
    }
    else if(!existence_mot) {
        ind_joueur_perdant = indice_joueur_precedent(struct_joueurs, indice_joueur);
        cout << "le mot " << mot_propose << " n’existe pas, " << ind_joueur_perdant+1 << struct_joueurs.ordre_passage[ind_joueur_perdant] <<
             " prend un quart de singe" << endl;
        addQuartDeSinge(struct_joueurs, ind_joueur_perdant);
    }
    else {
        cout << "ERREUR : bool pas bool" << endl;
    }
}


void addQuartDeSinge(Joueurs& struct_joueurs, const uint indice) {
    struct_joueurs.pointsSingeJoueur[indice].pointsDeSinge += 0.25;
}

char* ajoute_lettre_au_mot(char mot_manche[], const char lettre_joueur) {
    uint long_mot = strlen(mot_manche);
    mot_manche[long_mot] = lettre_joueur;
    //mot_manche[long_mot+1] = "\0"; // UTILE ?
    return mot_manche;
}