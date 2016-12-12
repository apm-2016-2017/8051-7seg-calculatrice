#include "test.h"

static unsigned char *file = (unsigned char __xdata *) 0x2000;
static unsigned char entree = 0;
static unsigned char sortie = 0;

void reinitialiseFile() {
	entree = 0;
	sortie = 0;
}

void enfile(unsigned char c) {
	file[entree] = c;
	entree++;
}

unsigned char fileContientDonnees() {
	if (entree == sortie) {
		return 0;
	}
	return 0xFF;
}

unsigned char defile() {
	unsigned char c = 0;
	if (fileContientDonnees()) {
		c = file[sortie];
		sortie++;
	}
	return c;
}

#ifdef TEST

void testeFileEstVide() {
	reinitialiseFile();
	verifie(fileContientDonnees(), 0);
	enfile(1);
	verifie(fileContientDonnees(), 0xFF);
	defile();
	verifie(fileContientDonnees(), 0);
}

void testeFileEnfileDefileDeuxCaracteres() {
	reinitialiseFile();
	enfile(1);
	enfile(10);
	verifie(defile(), 1);
	verifie(defile(), 10);
}

void testeFile() {
	testeFileEnfileDefileDeuxCaracteres();
	testeFileEstVide();
}

#endif
