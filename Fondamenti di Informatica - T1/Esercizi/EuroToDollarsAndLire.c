#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

float euro_to_dollars(int euro) {
	return euro * 0.87;
}

float lire_to_euro(int euro) {
	return euro * 1936.27;
}

int main(void) {
	
	float n;

	printf("Inserisci un importo in euro per calcolarne in valore in dollari e lire: ");
	scanf("%f", &n);
	printf("\n%f EURO = %f DOLLARI\n", n, euro_to_dollars(n));
	printf("%f EURO = : %f LIRE", n, lire_to_euro(n));

	return 0;
}