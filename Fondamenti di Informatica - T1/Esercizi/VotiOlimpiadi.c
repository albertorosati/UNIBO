#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void swap(float *a, float *b) {
	float tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	float f[5];
	float tmp;
	printf("Inserisci i quattro voti separati da una virgola:");
	scanf("%f,%f,%f,%f", &f[0], &f[1], &f[2], &f[3]);

	for (int i = 0; i < 4; i++) {
		if (f[i] > 10 || f[i] < 0) {
			printf("PROGRAMMA TERMINATO. ERRORE: Voto non valido");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (f[i] > f[i + 1]) {
			swap(&f[i], &f[i + 1]);
		}
	}
	float media = (f[0] + f[1] + f[2]) / 3;
	printf("La media dei voti '%f', '%f' e '%f' e' '%f'", f[0], f[1], f[2], media);


	return 0;
}