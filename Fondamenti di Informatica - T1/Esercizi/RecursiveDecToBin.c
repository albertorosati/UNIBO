#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>


void printDecToBin(int n) {
	if (n / 2 == 0) {
		printf("Il risultato e' ");
		printf("%d", n % 2);
	}
	else {
		printDecToBin(n / 2);
		printf("%d", n % 2);
	}
}


int main(void) {
	int n;
	printf("Inserisci un numero per convertirlo in binario: ");
	scanf("%d", &n);
	printDecToBin(n);
	return 0;
}