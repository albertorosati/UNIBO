#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int potenza(int n, int exp) {
	if (exp == 0)
		return 1;
	int result = n;
	for (int i = 1; i < exp; i++) {
		result *= n;
	}
	return result;
}

int sommaPotenze(int n, int limite) {
	int result = 0;
	for (int i = 0; i <= limite; i++) {
		result += potenza(n, i);
	}
	return result;
}

int main(void) {
	
	int base, limite;
	
	printf("Inserisci una base e un limite: ");
	scanf("%d,%d", &base, &limite);
	printf("La sommatoria restituisce come risultato %d", sommaPotenze(base, limite));

	return 0;
}