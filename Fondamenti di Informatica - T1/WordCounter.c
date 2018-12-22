#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE * parole_txt = fopen("PAROLE.txt", "r");

	if (parole_txt == NULL) {
		perror("Errore durante l'apertura del file 'PAROLE.txt'");
		exit(1);
	}
	int caratteri = 0, linee = 1, parole = -1;
	char prec = ' ', temp_c;

	while (fscanf(parole_txt, "%c", &temp_c) != EOF) {
		caratteri++;
		if (temp_c == '\n') {
			linee++;
		}
		if (prec == ' ' && temp_c != ' ' || prec != ' ' && prec != '\n' && temp_c == '\n') {
			parole++;
		}
		prec = temp_c;
	}

	printf("\nCARATTERI: %d", caratteri);
	printf("\nPAROLE: %d", parole);
	printf("\nLINEE: %d", linee);
	fclose(parole_txt);
	return 0;
}