#include "affiche.h"
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

void calculatrice(unsigned char ascii) {
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
			break;

		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
			accumulateur = executeOperation(accumulateur, operation, valeur);
			operation = ascii;
			valeur = 0;
			affiche(accumulateur);
			break;
	}
}

#ifdef TEST
void testeAddition() {
	reinitialiseCalculatrice();

	calculatrice('1');
	calculatrice('6');
	calculatrice('+');
	calculatrice('5');
	calculatrice('7');
	calculatrice('=');

	verifie(accumulateur, 73);
}

void testeAdditionEtMultiplication() {
	reinitialiseCalculatrice();

	calculatrice('3');
	calculatrice('*');
	calculatrice('2');
	calculatrice('+');
	calculatrice('4');
	calculatrice('=');

	verifie(accumulateur, 10);
}

void testeDeuxOperations() {
	reinitialiseCalculatrice();

	calculatrice('6');
	calculatrice('/');
	calculatrice('2');
	calculatrice('=');
	verifie(accumulateur, 3);

	calculatrice('2');
	calculatrice('+');
	calculatrice('7');
	calculatrice('=');
	verifie(accumulateur, 9);
}

void testeCalculatrice() {
	testeAddition();
	testeAdditionEtMultiplication();
	testeDeuxOperations();
}
#endif