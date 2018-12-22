#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trova.h"

#define DIM 100


int main() {
	FILE * azioni_txt = fopen("azioni.txt", "r");

	if (azioni_txt == NULL) {
		perror("Ho riscontrato un errore durante l'apertura del file 'azioni.txt'");
		exit(1);
	}
	else {

		Azione azioni[DIM];

		char name_azione[30];

		printf("Inserisci il titolo di un azione: ");
		scanf_s("%s", name_azione, 30);

		int result = leggi(azioni_txt, azioni, DIM, name_azione);

		if (result == 0) {
			printf("Non sono riuscito a trovare azioni per il valore '%s'", name_azione);
		}
		else {
			printf("Sono riuscito a trovare %d azioni per l'azienda '%s'", result, name_azione);
			float max_value;
			float min_value;
			Azione max_azione = trovaMax(azioni, result, &max_value);
			Azione min_azione = trovaMin(azioni, result, &min_value);;
			printf("\nVALORE MIN: %f", min_value);
			printf("\nVALORE MAX: %f", max_value);
			float med = media(azioni, result);
			printf("\n\nMEDIA VALORE AZIONARIO: %f", med);
			printf("\nVolatilita': %.2f  \\\  %.2f", (min_value - med) / med * 100, (max_value - med) / med * 100);
		}
	}

	fclose(azioni_txt);

	return 0;
}