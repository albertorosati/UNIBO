#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MATRICOLA_SIZE 7

typedef enum { FALSE, TRUE } boolean;

void cleanBuffer() {
	while ((getchar()) != '\n');
}

typedef struct {
	int id;
	char tipo[1024];
	float importo;
} Spesa;

typedef struct {
	int id;
	Spesa * spesa;
	int spesa_dim;
} Rimborso;

int compareSpesa(Spesa s1, Spesa s2) {
	int result = -1;
	if (s1.id > s2.id) {
		result = 1;
	}
	else if (s1.id == s2.id) {
		if (strcmp(s1.tipo, s2.tipo) > 0) {
			result = 1;
		}
		if (strcmp(s1.tipo, s2.tipo) == 0) {
			if (s1.importo > s2.importo) {
				result = 1;
			}
			else if (s1.importo == s2.importo) {
				result = 0;
			}
		}
	}
	return result;
}

void merge(Spesa v[], int i1, int i2, int fine, Spesa vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compareSpesa(v[i], v[j]) == -1) {
			vout[k] = v[i];
			i++;
		}
		else {
			vout[k] = v[j];
			j++;
		}
		k++;
	}
	while (i <= i2 - 1) {
		vout[k] = v[i];
		i++; k++;
	}
	while (j <= fine) {
		vout[k] = v[j];
		j++; k++;
	}
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort(Spesa v[], int iniz, int fine, Spesa vout[]) {
	int mid;
	if (iniz < fine) {
		mid = (fine + iniz) / 2;
		mergeSort(v, iniz, mid, vout);
		mergeSort(v, mid + 1, fine, vout);
		merge(v, iniz, mid + 1, fine, vout);
	}
}



void scriviSpese(char * nomeFile) {
	FILE * file = fopen(nomeFile, "w");
	if (file == NULL) {
		perror("\nErrore durante l'apertura del file");
		exit(1);
	}
	printf("\nINIZIO LA FASE DI SCRITTURA\n");
	int i = 0;
	Spesa temp;
	int end = FALSE;
	while (!end) {
		printf("\n- ELEMENTO %d:\n", i + 1);
		printf("\nInserisci l'id della spesa: ");

		while (scanf("%d", &temp.id) != 1) {
			printf("\n\nInput non valido. Riprova.");
			printf("\nInserisci l'id della spesa: ");
			cleanBuffer();
		}
		cleanBuffer();
		if (temp.id == -1) {
			end = TRUE;
			printf("\nLettura completata\n");
		}
		else {
			printf("\nInserisci il tipo della spesa: ");
			while (scanf_s("%s", temp.tipo, 1024) != 1) {
				printf("\n\nInput non valido. Riprova.");
				printf("\nInserisci il tipo della spesa: ");
				cleanBuffer();
			}
			cleanBuffer();

			printf("\nInserisci l'importo della spesa: ");
			while (scanf("%f", &temp.importo) != 1) {
				printf("\n\nInput non valido. Riprova.");
				printf("\nInserisci l'importo della spesa: ");
				cleanBuffer();
			}
			fprintf(file, "%d %s %f\n", temp.id, temp.tipo, temp.importo);
			i++;
		}
	}
	fclose(file);
}

Spesa * leggiSpese(char * nomeFile, int * dim) {
	FILE * file = fopen(nomeFile, "r");
	if (file == NULL) {
		printf("\nImpossibile aprire il file '%s'.", nomeFile);
		exit(1);
	}
	Spesa temp;
	*dim = 0;
	while (fscanf(file, "%d %s %f\n", &temp.id, temp.tipo, &temp.importo) != EOF) {
		(*dim)++;
	}
	rewind(file);
	Spesa * array = (Spesa*)malloc((*dim) * sizeof(Spesa));
	int i = 0;
	while (fscanf(file, "%d %s %f\n", &array[i].id, array[i].tipo, &array[i].importo) != EOF) {
		i++;
	}
	fclose(file);
	return array;
}

Spesa * eliminaDuplicati(Spesa * s, int dim, int * dimNew) {
	*dimNew = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = i + 1; j < dim; j++) {
			if (compareSpesa(s[i], s[j]) == 0) {
				(*dimNew)++;
			}
		}
	}
	Spesa * new_spesa = (Spesa*)malloc(sizeof(Spesa) * (*dimNew));
	int counter = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = i + 1; j < dim; j++) {
			if (compareSpesa(s[i], s[j]) == 0) {
				new_spesa[counter] = s[i];
				counter++;
			}
		}
	}
	return new_spesa;
}

int idMemberRimborso(Rimborso rimborsi[], int id, int dim) {
	int result = -1;
	boolean found = FALSE;
	for (int i = 0; i < dim && !found; i++) {
		if (rimborsi[i].id == id) {
			result = i;
			found = TRUE;
		}
	}
	return result;
}

int memberOfInt(int * haystack, int needle, int size) {
	int result = -1;
	boolean found = FALSE;
	for (int i = 0; i < size && !found; i++) {
		if (haystack[i] == needle) {
			result = i;
			found = TRUE;
		}
	}
	return result;
}

Rimborso * generateRimborso(Spesa * spese, int dim, int * dim_rimborso) {
	*dim_rimborso = 0;
	for (int i = 0; i < dim; i++) {
		boolean appears = FALSE;
		for (int j = 0; j < i && !appears; j++) {
			if (spese[j].id == spese[i].id) {
				appears = TRUE;
			}
		}

		if (!appears) {
			(*dim_rimborso)++;
		}
	}

	int * unique_ids = (int*)malloc(sizeof(int)*(*dim_rimborso));
	int unique_ids_counter = 0;
	for (int i = 0; i < dim; i++) {
		boolean appears = FALSE;
		for (int j = 0; j < i && !appears; j++) {
			if (spese[j].id == spese[i].id) {
				appears = TRUE;
			}
		}

		if (!appears) {
			unique_ids[unique_ids_counter] = spese[i].id;
			unique_ids_counter++;
		}
	}


	Rimborso * rimborsi = (Rimborso*)malloc(sizeof(Rimborso)*(*dim_rimborso));
	int rimborsi_counter = 0;
	for (int i = 0; i < (*dim_rimborso); i++) {

		int counter = 0;
		for (int j = 0; j < dim; j++) {
			if (spese[j].id == unique_ids[i]) {
				counter++;
			}
		}

		Spesa * spesa_new = (Spesa*)malloc(sizeof(Spesa) * counter);
		int counter_spesa_new = 0;
		for (int j = 0; j < dim; j++) {
			if (spese[j].id == unique_ids[i]) {
				spesa_new[counter_spesa_new].id = spese[j].id;
				spesa_new[counter_spesa_new].importo = spese[j].importo;
				strcpy(spesa_new[counter_spesa_new].tipo, spese[j].tipo);
				counter_spesa_new++;
			}
		}

		rimborsi[i].id = unique_ids[i];
		rimborsi[i].spesa = spesa_new;
		rimborsi[i].spesa_dim = counter_spesa_new;

	}

	free(unique_ids);

	return rimborsi;
}


int main() {
	char matricola[MATRICOLA_SIZE];
	char matricola_txt[MATRICOLA_SIZE + 4];

	printf("__________________ SISTEMA AUTOMATIZZATO 2.0 MIAO.EXE__________________");
	printf("\nInserisci il numero di matricola: ");
	scanf_s("%s", &matricola, MATRICOLA_SIZE);
	strcpy(matricola_txt, matricola);
	strcat(matricola_txt, ".txt");

	scriviSpese(matricola_txt);
	int spese_dim;
	Spesa * spese = leggiSpese(matricola_txt, &spese_dim);

	int rimborso_size;
	Rimborso * rimborsi = generateRimborso(spese, spese_dim, &rimborso_size);

	for (int i = 0; i < rimborso_size; i++) {
		printf("\n______________________________\n\n");
		printf("RIMBORSO DEL VIAGGIO n. %d\n", rimborsi[i].id);
		printf("\n%d spese trovate\n\n", rimborsi[i].spesa_dim);

		for (int j = 0; j < rimborsi[i].spesa_dim; j++) {
			printf("* SPESA n.%d:\n- TIPOLOGIA: %s\n- IMPORTO: %f\n\n", j+1, rimborsi[i].spesa[j].tipo, rimborsi[i].spesa[j].importo);
		}
		printf("\n______________________________\n");
		free(rimborsi[i].spesa);
	}

	Spesa * spese_sorted = (Spesa*)malloc(sizeof(Spesa)*spese_dim);

	mergeSort(spese, 0, spese_dim - 1, spese_sorted);

	int spese_newDim;
	Spesa * spese_noDuplicates = eliminaDuplicati(spese_sorted, spese_dim, &spese_newDim);

	printf("test");
	free(spese_noDuplicates);
	free(spese_sorted);
	free(spese);
	free(rimborsi);

	return 0;
}