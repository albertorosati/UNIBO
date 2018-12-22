#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

typedef struct Film {
	char nome[30];
	char sala[20];
	int orari[3];
	float costo;
} Film;

typedef struct Sala {
	char nome[30];
	float costo;
} Sala ;

int searchSala(Sala sale[], char needle[], int logic_dim) {
	int end = 0;
	int result = -1;
	for (int i = 0; i < logic_dim && !end; i++) {
		if (strcmp(sale[i].nome, needle) == 0) {
			end = 1;
			result = i;
		}
	}
	return result;
}

int load(FILE* cineprogrammatxt, FILE* saletxt, Film film[], Sala sale[]) {
	int i, j;
	for (i = 0; fscanf(cineprogrammatxt, "%s %s %d-%d-%d\n", film[i].nome, film[i].sala,
		&film[i].orari[0], &film[i].orari[1], &film[i].orari[2]) != EOF; i++);
	for (j = 0; fscanf(saletxt, "%s %f", sale[j].nome, &sale[j].costo) != EOF; j++);

	for (int k = 0; k < i; k++) {
		int sala = searchSala(sale, film[k].sala, j);
		if (sala != -1) {
			film[k].costo = sale[sala].costo;
		}
	}

	return i;
}



int main() {
	FILE * cineprogrammatxt = fopen("cineprogramma.txt", "r");
	FILE * saletxt = fopen("sale.txt", "r");

	Film film[10];
	Sala sale[10];

	if (cineprogrammatxt == NULL) {
		perror("Errore durante l'apertura del file 'cineprogramma.txt'");
	}
	if (saletxt == NULL) {
		perror("Errore durante l'apertura del file 'sale.txt'");
	}
	if (cineprogrammatxt != NULL && sale != NULL) {
		int film_logic_dim = load(cineprogrammatxt, saletxt, film, sale);
		float media = 0;
		for (int i = 0; i < film_logic_dim; i++) {
			media += film[i].costo;
		}
		media = (float) media / film_logic_dim;
		for (int i = 0; i < film_logic_dim; i++) {
			if (film[i].costo < media) {
				printf("Il film %s presso il cinema %s e' stato rilevato con un prezzo di %f inferiore alla media", film[i].nome, film[i].sala, film[i].costo);
			}
		}
	}

	return 0;
}