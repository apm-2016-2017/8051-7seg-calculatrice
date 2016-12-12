#include "file.h"

#define LIGNES 4
#define COLONNES 4

static unsigned char matriceClavier[LIGNES * COLONNES] = {
	'7', '8', '9', '/',
	'4', '5', '6', '*',
	'1', '2', '3', '-',
	'C', '0', '=', '+'
};

void notifieTouche(unsigned char ascii) {
	enfile(ascii);
}

void notifiePulsation(unsigned char ligne, unsigned char colonne) {
	unsigned char c;
	c = ligne * COLONNES + colonne;
	c = matriceClavier[c];
	notifieTouche(c);
}

void notifieEtatDuClavier(unsigned char ligne, unsigned char etatLigne) {
	static char etatPrecedent[4] = {0, 0, 0, 0};
	unsigned char changements = etatPrecedent[ligne] ^ etatLigne;
	unsigned char etat;
	unsigned char colonne = 0;

	if (changements != 0) {
		etat = etatLigne & changements;
		do {
			if ( etat & 1) {
				notifiePulsation(ligne, colonne);
			}
			etat >>= 1;
			colonne ++;
		} while (etat);

		etatPrecedent[ligne] = etatLigne;
	}
}
