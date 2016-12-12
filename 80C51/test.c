static unsigned char echecs = 0;

#ifdef TEST
void initialiseTests() {
	echecs = 0;
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
