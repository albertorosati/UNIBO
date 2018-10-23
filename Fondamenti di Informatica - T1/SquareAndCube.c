#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

float square(float i) {
	return i*i;
}

float cube(float i) {
	return i * i * i;
}

int main(void) {
	
	float n;

	printf("Inserisci un numero per calcolarne il suo quadrato e il suo cubo:");
	scanf("%f", &n);
	printf("\nIl quadrato del numero %f equivale a: %f\n", n, square(n));
	printf("Il cubo del numero %f equivale a: %f", n, cube(n));

	return 0;
}