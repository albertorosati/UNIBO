#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

typedef struct Debito {
	char nome[31];
	float importo;
} Debito;

int load(FILE * anagrafe_txt, FILE * fatture_txt, Debito debito[], char debitori[]) {
	char debitore[31];
	char bin[21];
	int id_debitore_anagrafe;
	int i = 0;
	int counter = 0;
	while (fscanf(anagrafe_txt, "%d %s %s\n", &id_debitore_anagrafe, debitore, bin) != EOF) {
		int j = 0;
		int id_debitore_fatture;
		int bin;
		float importo_temp;
		float importo_tot = 0;
		char payment_status;
		while (fscanf(fatture_txt, "%d %d %f %c\n", &id_debitore_fatture, &bin, &importo_temp, &payment_status) != EOF) {
			if (id_debitore_anagrafe == id_debitore_fatture) {
				if (payment_status == 'n') {
					importo_tot += importo_temp;
				}
			}
		}
		if (importo_tot > 0) {
			debito[i].importo = importo_tot;
			strcpy(debito[i].nome, debitore);
			counter++;
		}
		rewind(fatture_txt);
	}
	return counter;
}

int array_Debito_contains_nome(Debito debito[], char needle[], int size) {
	int end = 0;
	int result = -1;
	for (int i = 0; i < size && !end; i++) {
		if (strcmp(debito[i].nome, needle) == 0) {
			result = i;
			end = 1;
		}
	}
	return result;
}

int main() {
	FILE * anagrafe_txt = fopen("anagrafe.txt", "r");
	FILE * fatture_txt = fopen("fatture.txt", "r");

	Debito debito[30];
	char debitori[30];

	int debito_size;

	if (anagrafe_txt == NULL) {
		perror("Errore durante l'apertura del file 'anagrafe.txt'");
	}
	if (fatture_txt == NULL) {
		perror("Errore durante l'apertura del file 'fatture.txt'");
	}
	if (anagrafe_txt != NULL && fatture_txt != NULL) {
		debito_size = load(anagrafe_txt, fatture_txt, debito, debitori);

		char cliente[31];

		printf("Inserisci il nome di un cliente per visualizzare le fatture non pagate: ");
		scanf("%s", cliente);

		int clienteIndex = array_Debito_contains_nome(debito, cliente, debito_size);

		if (clienteIndex != -1) {
			Debito singolo_debito = debito[clienteIndex];
			printf("Il cliente '%s' deve pagare %f euro", cliente, singolo_debito.importo);
		}
		else {
			printf("Il cliente '%s' non e' stato trovato all'interno dei nostri registri", cliente);
		}
	}


	fclose(anagrafe_txt);
	fclose(fatture_txt);
	

	return 0;
}