/**
 * Conversion BCD à 7 segments.
 */
static unsigned char conversionBcd[] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 
	0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};

static unsigned char *afficheur = (unsigned char __xdata *) 0x0000;

/**
 * Affiche la valeur sur l'afficheur 4x7seg.
 */
void affiche(unsigned int valeur) {
	unsigned char n;
	unsigned char decimal, bcd;

	for(n = 0; n < 4; n++) {
		decimal = valeur % 10;
		bcd = conversionBcd[decimal];
		afficheur[3 - n] = ~bcd;
		valeur /= 10;
	}
}
