#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Registratore.h"
#define TRANSACTION_DIM 10

int readArray(Transaction transaction[], int dim) {
	int i = 0;
	printf("INIZIALIZZO L'ARRAY:\n");
	char customer[DIM];
	int transactionId;
	float value;
	while (strcmp(customer, "0") != 0 && i < dim) {
		printf("\n--- LETTURA %d ---\n", i + 1);
		printf("Inserisci il nome di un cliente: ");
		scanf_s("%s", customer, DIM);
		if (strcmp(customer, "0") == 0 && i == 0) {
			printf("Non hai inserito nesssun valore. Riprova.\n");
			customer[0] = 'c';
		}
		else if (strcmp(customer, "0") == 0) {
			printf("\nLettura completata. %d valori letti.\n", i);
		}
		else {
			printf("Inserisci l'id della transazione: ");
			scanf("%d", &transactionId);
			if (transactionId != 0) {
				printf("Inserisci l'importo: ");
				scanf("%f", &value);
				if (value != 0) {
					strcpy(transaction[i].customer, customer);
					transaction[i].transactionId = transactionId;
					transaction[i].value = value;
					i++;
				}
				else {
					printf("Hai inserito un valore non valido. Riprova.\n");
				}
			}
			else {
				printf("Hai inserito un valore non valido. Riprova.\n");
			}
		}
	}
	return i;
}

int main() {
	FILE * registratore = fopen("log.txt", "w+b");

	if (registratore == NULL) {
		perror("Ho riscontrato un errore durante l'apertura del file 'log.dat'");
		exit(1);
	}
	Transaction transaction[TRANSACTION_DIM];
	int transaction_logic_dim = readArray(transaction, TRANSACTION_DIM);

	for (int i = 0; i < transaction_logic_dim; i++) {
		int returnvalue = fwrite(&transaction[i], sizeof(Transaction), 1, registratore);
	}

	

	char customer_name[DIM];
	printf("Inserisci il nome di un cliente: ");
	scanf_s("%s", customer_name, DIM);

	char txt_file_name[DIM + 4];
	strcpy(txt_file_name, customer_name);
	strcat(txt_file_name, ".txt");

	FILE * customer_file = fopen(txt_file_name, "w");
	if (customer_file == NULL) {
		printf("Ho riscontrato un errore durante l'apertura del file '%s.txt'\n", customer_name);
		perror("CODICE:");
		exit(1);
	}
	else {
		rewind(registratore);
		int result = copy(registratore, customer_file, customer_name);
		printf("Ho scritto con successo %d entries nel file", result);
	}
	fclose(customer_file);
	fclose(registratore);

	return 0;
}