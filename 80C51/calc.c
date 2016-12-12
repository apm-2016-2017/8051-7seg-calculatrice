#include "test.h"

unsigned char operation = '=';
unsigned int accumulateur = 0;
unsigned int valeur = 0;

void reinitialiseCalculatrice() {
	operation = '=';
	accumulateur = 0;
	valeur = 0;
}
unsigned int executeOperation(unsigned int a, unsigned char operation, unsigned int b) {
	switch(operation) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return b;
	}
}

unsigned int calculatrice(unsigned char ascii) {
	switch (ascii) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			valeur *= 10;
			valeur += ascii - '0';
			return valeur;

		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
			accumulateur = executeOperation(accumulateur, operation, valeur);
			operation = ascii;
			valeur = 0;
			return accumulateur;
	}
	return 0;
}

#ifdef TEST
void testeAddition() {
	reinitialiseCalculatrice();

	verifie(calculatrice('1'),  1);
	verifie(calculatrice('6'), 16);
	verifie(calculatrice('+'), 16);
	verifie(calculatrice('5'),  5);
	verifie(calculatrice('7'), 57);
	verifie(calculatrice('='), 73);
}

void testeDeuxOperationsChainees() {
	reinitialiseCalculatrice();

	verifie(calculatrice('3'), 3);
	verifie(calculatrice('*'), 3);
	verifie(calculatrice('2'), 2);
	verifie(calculatrice('+'), 6);
	verifie(calculatrice('4'), 4);
	verifie(calculatrice('='), 10);
}

void testeDeuxOperationsSeparees() {
	reinitialiseCalculatrice();

	verifie(calculatrice('6'), 6);
	verifie(calculatrice('/'), 6);
	verifie(calculatrice('2'), 2);
	verifie(calculatrice('='), 3);

	verifie(calculatrice('2'), 2);
	verifie(calculatrice('+'), 2);
	verifie(calculatrice('7'), 7);
	verifie(calculatrice('='), 9);
}

void testeDeuxOperationsChainessAvecEgal() {
	reinitialiseCalculatrice();

	verifie(calculatrice('8'), 8);
	verifie(calculatrice('/'), 8);
	verifie(calculatrice('2'), 2);
	verifie(calculatrice('='), 4);

	verifie(calculatrice('+'), 4);
	verifie(calculatrice('1'), 1);
	verifie(calculatrice('='), 5);
}

void testeCalculatrice() {
	testeAddition();
	testeDeuxOperationsSeparees();
	testeDeuxOperationsChainees();
	testeDeuxOperationsChainessAvecEgal();
}
#endif