#ifdef TEST
static unsigned char echecs = 0;

void initialiseTests() {
}

void verifie(int valeurObtenue, int valeurAttendue) {
	if (valeurObtenue != valeurAttendue) {
		echecs ++;
	}
}

unsigned char nombreDeTestsEnEchec() {
	return echecs;
}

#endif