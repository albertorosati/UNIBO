#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

float perimetro(float a, float b, float c) {
	return a + b + c;
}

float area(float a, float b, float c) {
	float p = perimetro(a, b, c);
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main(void) {
	
	float a, b, c;

	printf("Inserisci il valore dei tre lati del triangolo separato da una virgola: ");
	scanf("%f,%f,%f", &a, &b, &c);

	printf("Il perimetro vale: %f\n", perimetro(a, b, c));
	printf("L'area vale: %f", area(a, b, c));

	return 0;
}