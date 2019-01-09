#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

int address(char cognome[], char nome[], char indirizzo[], int dim) {
	int result = -1;
	if (dim >= strlen(cognome) + strlen(nome)) {
		strcpy(indirizzo, cognome);
		indirizzo[strlen(cognome)] = ' ';
		indirizzo[strlen(cognome) + 1] = '\0';
		strcat(indirizzo, nome);
		result = 1;
	}
	else if (dim == strlen(cognome) + 3) {
		strncpy(indirizzo, cognome, strlen(cognome));
		indirizzo[strlen(cognome)] = ' ';
		indirizzo[strlen(cognome) + 1] = nome[0];
		indirizzo[strlen(cognome) + 2] = '.';
		indirizzo[strlen(cognome) + 3] = '\0';
		result = 2;
	}
	return result;
}

int main() {
	
	char nome[20] = "Alberto", cognome[20] = "Rosati", indirizzo[20];

	printf("test");
	printf("%d", address(cognome, nome, indirizzo, 19));

	return 0;
}