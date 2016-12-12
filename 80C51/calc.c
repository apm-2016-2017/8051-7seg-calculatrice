#include "affiche.h"
#include "test.h"

void calculatrice(unsigned char ascii) {
	affiche(ascii - '0');
}

#ifdef TEST
void testeCalculatrice() {
}
#endif