#ifndef COMPLEX_H
#define COMPLEX_H

// Type utilisateur complexe_t
struct complexe_t {
    double re;
    double im;
};

typedef struct complexe_t complexe_t;

// Fonctions reelle et imaginaire
/**
 * reelle
 * Retourne la partie réelle du nombre complexe donné en argument
 *
 * Paramètres :
 *   z              [in]  Complexe dont on veut retourner la partie réelle
 * 
 * Pré-conditions : aucune
 * Post-conditions : aucune
 */
double reelle(complexe_t z);

/**
 * imaginaire
 * Retourne la partie imaginaire du nombre complexe donné en argument
 *
 * Paramètres :
 *   z              [in]  Complexe dont on veut retourner la partie imaginaire
 * 
 * Pré-conditions : aucune
 * Post-conditions : aucune
 */
double imaginaire(complexe_t z);

// Procédures set_reelle, set_imaginaire et init
/**
 * set_reelle
 * Modifie la partie réelle du nombre complexe passé en argument
 *
 * Paramètres :
 *   z              [out] Complexe dont on modifie la partie réelle
 *   x              [in]  Nouvelle valeur de la partie réelle
 * 
 * Pré-conditions : aucune
 * Post-conditions : set_reelle(*z, x) => reelle(z) == x
 */
void set_reelle(complexe_t* z, double x);

/**
 * set_imaginaire
 * Modifie la partie imaginaire du nombre complexe passé en argument
 *
 * Paramètres :
 *   z              [out] Complexe dont on modifie la partie imaginaire
 *   y              [in]  Nouvelle valeur de la partie imaginaire
 * 
 * Pré-conditions : aucune
 * Post-conditions : set_imaginaire(*z, y) => imaginaire(z) == y
 */
void set_imaginaire(complexe_t* z, double y);

/**
 * init
 * Modifie les parties réelles et imaginaires d'un nombre complexe passé en argument
 * 
 * Paramètres :
 *   z              [out] Complexe que l'on modifie
 *   x              [in]  Nouvelle valeur de la partie réelle
 *   y              [in]  Nouvelle valeur de la partie imaginaire
 * 
 * Pré-conditions : aucune
 * Post-conditions : init(*z, x, y) => reelle(z) == x /\ imaginaire(z) == y
 */
void init(complexe_t* z, double x, double y);

// Procédure copie
/**
 * copie
 * Copie les composantes du complexe donné en second argument dans celles du premier
 * argument
 *
 * Paramètres :
 *   resultat       [out] Complexe dans lequel copier les composantes
 *   autre          [in]  Complexe à copier
 *
 * Pré-conditions : resultat non null
 * Post-conditions : resultat et autre ont les mêmes composantes
 */
void copie(complexe_t* resultat, complexe_t autre);

// Algèbre des nombres complexes
/**
 * conjugue
 * Calcule le conjugué du nombre complexe op et le sotocke dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut le conjugué
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : reelle(*resultat) = reelle(op), imaginaire(*resultat) = - imaginaire(op)
 */
void conjugue(complexe_t* resultat, complexe_t op);

/**
 * ajouter
 * Réalise l'addition des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche + droite
 */
void ajouter(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * soustraire
 * Réalise la soustraction des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche - droite
 */
void soustraire(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * multiplier
 * Réalise le produit des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche * droite
 */
void multiplier(complexe_t* resultat, complexe_t gauche, complexe_t droite);

/**
 * echelle
 * Calcule la mise à l'échelle d'un nombre complexe avec le nombre réel donné (multiplication
 * de op par le facteur réel facteur).
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe à mettre à l'échelle
 *   facteur        [in]  Nombre réel à multiplier
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = op * facteur
 */
void echelle(complexe_t* resultat, complexe_t op, double facteur);

/**
 * puissance
 * Calcule la puissance entière du complexe donné et stocke le résultat dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut la puissance
 *   exposant       [in]  Exposant de la puissance
 *
 * Pré-conditions : resultat non-null, exposant >= 0
 * Post-conditions : *resultat = op * op * ... * op
 *                                      { n fois }
 */
void puissance(complexe_t* resultat, complexe_t op, int exposant);

// Module et argument
/**
 * module_carre
 * Calcule le carré du module d'un nombre complexe
 * 
 * Paramètres :
 *   z              [in]  Complexe dont on calcule le carré du module
 *
 * Pré-conditions : aucune
 * Post-conditions : resultat >= 0
 */
double module_carre(complexe_t z);

/**
 * module
 * Calcule le module d'un nombre complexe
 *
 * Paramètres :
 *   z              [in]  Complexe dont on calcule le module
 *
 * Pré-conditions : aucune
 * Post-conditions : resultat >= 0
 */
double module(complexe_t z);

/**
 * argument
 * Calcule l'argument d'un nombre complexe
 *
 * Paramètres :
 *   z              [in]  Complexe dont on calcule l'argument
 *
 * Pré-conditions : z =/= 0
 * Post-conditions : -π < resultat <= π
 */
double argument(complexe_t z);


#endif // COMPLEXE_H



