#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void) {
	int mese;
	int giorno;
	char stagione[15];
	printf("Inserire il mese (numero) affinche' venga restituita la stagione corrispondente:\n");
	scanf("%d", &mese);

	switch (mese) {
	case 3:
		printf("Inserisci il numero del giorno:");
		scanf("%d", &giorno);
		if (giorno <= 20) printf("INVERNO"); else printf("PRIMAVERA");
		break;

	case 6:
		printf("Inserisci il numero del giorno:");
		scanf("%d", &giorno);
		if (giorno <= 20) printf("PRIMAVERA"); else printf("ESTATE");
		break;

	case 9:
		printf("Inserisci il numero del giorno:");
		scanf("%d", &giorno);
		if (giorno <= 20) printf("ESTATE"); else printf("INVERNO");
		break;

	case 1: case 2:
		printf("INVERNO"); break;
	case 4: case 5:
		printf("PRIMAVERA"); break;
	case 7: case 8:
		printf("ESTATE"); break;
	case 10: case 11:
		printf("AUTUNNO"); break;

	default: printf("ESPRESSIONE NON VALIDA");
	}

	return 0;
}