#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

float ipotenusa(float c1, float c2) {
	return sqrt((c1*c1) + (c2*c2));
}

int main(void) {
	float c1, c2;

	printf("Inserisci i valori dei due cateti separati da una virgola per calcolarne l'ipotenusa: ");
	scanf("%f,%f", &c1, &c2);

	printf("L'ipotenusa vale %f", ipotenusa(c1, c2));

	return 0;
}