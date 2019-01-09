#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

bool isPrimo(int n) {
	if (n < 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	
	int n;

	printf("Inserisci un numero per calcolare i numeri primi tra 0 e N: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (isPrimo(i))
			printf("Il numero %d e' primo\n", i);
		else
			printf("Il numero %d non e' primo\n", i);
	}

	return 0;
}