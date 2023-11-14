#include "complexe.h"
#include <math.h>           // Pour certaines fonctions trigo notamment

// Implantations de reelle et imaginaire
double reelle(complexe_t z) {
    return z.re;
}

double imaginaire(complexe_t z) {
    return z.im;
}

// Implantations de set_reelle et set_imaginaire
void set_reelle(complexe_t* z, double x) {
    (*z).re = x;
}

void set_imaginaire(complexe_t* z, double y) {
    (*z).im = y;
}

void init(complexe_t* z, double x, double y) {
    set_reelle(z, x);
    set_imaginaire(z, y);
}

// Implantation de copie
void copie(complexe_t* resultat, complexe_t autre) {
    init(resultat, reelle(autre), imaginaire(autre));
}

// Implantations des fonctions algébriques sur les complexes
void conjugue(complexe_t* resultat, complexe_t op) {
    init(resultat, reelle(op), -imaginaire(op));
}

void ajouter(complexe_t* resultat, complexe_t gauche, complexe_t droite) {
    init(
        resultat,
        reelle(gauche) + reelle(droite),
        imaginaire(gauche) + imaginaire(droite)
    );
}

void soustraire(complexe_t* resultat, complexe_t gauche, complexe_t droite) {
    init(
        resultat,
        reelle(gauche) - reelle(droite),
        imaginaire(gauche) - imaginaire(droite)
    );
}

void multiplier(complexe_t* resultat, complexe_t gauche, complexe_t droite) {
    init(
        resultat,
        reelle(gauche) * reelle(droite) - imaginaire(gauche) * imaginaire(droite),
        reelle(gauche) * imaginaire(droite) + reelle(droite) * imaginaire(gauche)
    );
}

void echelle(complexe_t* resultat, complexe_t op, double facteur) {
    init(
        resultat,
        reelle(op) * facteur,
        imaginaire(op) * facteur
    );
}

void puissance(complexe_t* resultat, complexe_t op, int exposant) {
    if (exposant == 0) {
        init(resultat, 1, 0);
    } else if (exposant == 1) {
        copie(resultat, op);
    } else if (exposant % 2 == 0) {
        multiplier(resultat, *resultat, op);
        multiplier(resultat, *resultat, op);
        puissance(resultat, op, exposant / 2);
    } else {
        multiplier(resultat, *resultat, op);
        multiplier(resultat, *resultat, op);
        puissance(resultat, op, (exposant-1) / 2);
        multiplier(resultat, *resultat, op);
    }
}

// Implantations du module et de l'argument
double module_carre(complexe_t z) {
    return pow(reelle(z),2) + pow(imaginaire(z),2);
}

double module(complexe_t z) {
    return sqrt(module_carre(z));
}

double argument(complexe_t z) {
    if (imaginaire(z) == 0 && reelle(z) <= 0) {
        return M_PI;
    } else {
        return 2*atan(imaginaire(z)/(reelle(z)+module(z)));
    }
}


