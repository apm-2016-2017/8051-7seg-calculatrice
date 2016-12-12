#include <mcs51reg.h>
#include "file.h"
#include "clavier.h"
#include "calc.h"
#include "test.h"
#include "affiche.h"

void exploreClavier() {
	static unsigned char *clavier = (unsigned char __xdata *) 0x1000;
	unsigned char ligne;

	for(ligne = 0; ligne < 4; ligne++) {
		notifieEtatDuClavier(ligne, clavier[ligne]);
	}
}

#ifndef TEST

void temporisateur0() __interrupt 1 {
	TL0 = 0xDF;
	TH0 = 0xB1;
	exploreClavier();
}

/**
 * Point d'entrée.
 */
void main(void) {
	unsigned char c;

	// Initialisation:
	TCON = 0b00010000;	// Active le temporisateur 0
	TMOD = 0b00000001;	// Temporisateur 0 en mode 01.
	IE =   0b10000010;	// Active les interruptions du temporisateur 0.


	while(1) {
		if (fileContientDonnees()) {
			c = defile();
			calculatrice(c);
		}
		exploreClavier();
	}
}
#else
void main() {
	initialiseTests();
	testeFile();
	testeCalculatrice();
	affiche(nombreDeTestsEnEchec());
}
#endif