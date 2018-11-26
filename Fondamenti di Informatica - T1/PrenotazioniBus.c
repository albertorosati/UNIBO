#include <stdio.h>
#include <string.h>
#define DIM 3
#define SAME_STRING 0
#define FINE 0
#define STAMPA -1
#define INVALID_COMMAND -2
#define SUCCESS 1
#define OCCUPATO 0
#define LIBERO 1

char fine_uc[5] = "FINE";
char fine_lc[5] = "fine";
char stampa_uc[7] = "STAMPA";
char stampa_lc[7] = "stampa";
int isArrayFull = 0;

typedef struct {
	char name[1024];
	int seat;
} booking;

int readBooking(booking *b) {
	int result = SUCCESS;
	if (!isArrayFull) {
		printf("\nInserisci il nome del cliente: ");
		
	}
	else {
		printf("\nInserisci il comando FINE o STAMPA: ");
	}
	
	scanf_s("%s", &(*b).name, 1024);

	if (strcmp((*b).name, fine_uc) == SAME_STRING || strcmp((*b).name, fine_lc) == SAME_STRING) {
		result = FINE;
	}
	else if (strcmp((*b).name, stampa_uc) == SAME_STRING || strcmp((*b).name, stampa_lc) == SAME_STRING) {
		result = STAMPA;
	}
	else {
		if (!isArrayFull) {
			printf("Insersci il numero del posto: ");
			scanf_s("%d", &(*b).seat);
		}
		else {
			result = INVALID_COMMAND;
		}
	}
	return result;
}

int assegna(booking b[], int dim, int *logic_dim, char name[], int seat_num) {
	int assegnato = LIBERO;
	for (int i = 0; i < *logic_dim && assegnato != OCCUPATO; i++) {
		if (b[i].seat == seat_num) {
			assegnato = OCCUPATO;
		}
	}

	if (assegnato == LIBERO) {
		strcpy_s(b[(*logic_dim)].name, name);
		b[(*logic_dim)].seat = seat_num;
		*logic_dim = *logic_dim + 1;
	}

	return assegnato;
}

int main() {
	booking b[DIM];
	int b_logic_dim = 0;
	booking b_temp = { "t", 0 };
	
	int status = 1;

	while (status != FINE) {
		status = readBooking(&b_temp);
		if (status == STAMPA) {
			if (b_logic_dim == 0) {
				printf("\nATTENZIONE!\nIl database e' ancora vuoto. Inserisci almeno un dato.\n");
			}
			else {
				for (int i = 0; i < b_logic_dim; i++) {
					printf("\nPRENOTAZIONE N. %d\n", i + 1);
					printf("NOME:	%s\n", b[i].name);
					printf("POSTO:	%d\n", b[i].seat);
				}
				printf("\nPOSTI RIMANENTI: %d\n", DIM - b_logic_dim);
			}
		}
		else if (status == FINE) {
			printf("Programma terminato.");
		}
		else if (status == INVALID_COMMAND) {
			printf("\nATTENZIONE!\nIl comando che hai inserito non e' valido. Riprova.\n");
		}
		else {
			if (b_logic_dim != DIM) {
				if (status == SUCCESS) {
					int seat_status = assegna(b, DIM, &b_logic_dim, b_temp.name, b_temp.seat);
					if (seat_status == OCCUPATO) {
						printf("\nATTENZIONE!\nIl posto da te inserito e' gia' occupato. Riprova.\n");
					}
				}
				else {
					printf("EXCEPTION INTERNA. RESTART");
				}
			}
			if (b_logic_dim == DIM) {
				isArrayFull = 1;
				printf("\n------------\nI posti sono terminati.\n------------\n");
			}
		}
		printf("");
	}

	return 0;
}