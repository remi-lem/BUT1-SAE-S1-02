/**
 * @file joueurs.h
 * @author Rémi
 */

#ifndef BUT1_SAE_S1_02_JOUEURS_H
#define BUT1_SAE_S1_02_JOUEURS_H

#include <iostream>
#include <cstring>

#include <cassert>

/**
 * @brief pour éviter d'écrire std::cin et std::cout
 */
using namespace std;

/**
 * @brief déclaration de type uint pour ne pas avoir à écrire unsigned int
 */
typedef unsigned int uint;

/**
 * @brief Pour chaque joueur : stockage des points
 */
struct PointsSinge {
    float pointsDeSinge = 00.00f;
};

/**
 * @brief Stucture de stokage des joueurs et de leurs points
 */
struct Joueurs {
    uint nb_total = 0;
    char* ordre_passage = NULL;
    PointsSinge* pointsSingeJoueur = NULL;
    uint indice_dernier_perdant = 0;
};

/**
 * @brief Enumération dont les valeurs sont renvoyées par la fonction de traitement des arguments
 * @see fonction traitement_arguments dans joueurs.h
 */
enum {
    DICO_PAS_OUVERT,
    PAS_DE_PARAM,
    NB_JOUEURS_PAS_CORRECT,
    JOUEUR_NI_H_NI_R,
    CORRECT
};

/**
 * Au moins deux joueurs (au total) jouent
 */
const int MIN_JOUEURS = 2;

/**
 * @brief Initialisation de la structure des joueurs
 * @param[in,out] struct_joueurs une référence vers la structure
 * @param[in] taille_char_args la taille de la chaine des caractères contenant les H et les R
 * @pre taille_char_args >= 0
 */
void initialiser_struct_joueurs(Joueurs &struct_joueurs, const uint taille_char_args);

/**
 * @brief Recherche de l'indice du joueur précédent
 * @param[in] struct_joueurs une référence vers la structure des étudiants
 * @param[in] indice_joueur l'indice du joueur actuel
 * @pre indice compris entre 0 et le nombre de joueurs
 * @return l'indice du joueur précédent, sinon -1
 */
uint indice_joueur_precedent(const Joueurs& struct_joueurs, const uint indice_joueur);

/**
 * @brief Recherche de le numéro du joueur précédent
 * @param[in] struct_joueurs une référence vers la structure des étudiants
 * @param[in] indice_joueur l'indice du joueur actuel
 * @pre indice compris entre 0 et le nombre de joueurs
 * @return le numero du joueur précédent, sinon -1
 */
uint numero_joueur_precedent(const Joueurs& struct_joueurs, const uint indice_joueur);

#endif //BUT1_SAE_S1_02_JOUEURS_H
