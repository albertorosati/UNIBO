#include "Test.h"

Test leggiUnTest(FILE * fp)
{
	Test result;
	strcpy(result.matricola, "NULL");
	if (fp != NULL && !feof(fp)) {
		fscanf(fp, "%d/%d/%d %s", &result.date.day, &result.date.month, &result.date.year, result.matricola);
		for (int i = 0; i < 4; i++) {
			fscanf(fp, "%s %d", result.punteggi[i].materia, &result.punteggi[i].punteggio);
		}
		fgetc(fp);
	}
	return result;
}

Test * leggiTutti(char * fileName, int * dim) {
	FILE * file = fopen(fileName, "r");
	Test * test = NULL;
	Test temp;
	int i = 0;
	(*dim) = 0;
	if (file != NULL) {
		while (strcmp((temp = leggiUnTest(file)).matricola, "NULL") != 0) {
			(*dim)++;
		}
		rewind(file);
		test = (Test*)malloc(sizeof(Test)*(*dim));
		while (strcmp((temp = leggiUnTest(file)).matricola, "NULL") != 0) {
			test[i] = temp;
			i++;
		}
	}
	fclose(file);
	return test;
}

void stampaTest(Test * v, int dim) {
	for (int i = 0; i < dim; i++) {
		printf("\n");
		printDate(v[i].date);
		printf(" MATRICOLA: %s\n", v[i].matricola);
		for (int j = 0; j < 4; j++) {
			printf("%s: %d\n", v[i].punteggi[j].materia, v[i].punteggi[j].punteggio);
		}
		printf("TOTALE: %d\n", getPunteggioTotale(v[i]));
		printf("\n");
	}
}

void ordina(Test * v, int dim) {
	bubbleSort(v, dim);
}

List pref(char * fileName) {
	FILE * file = fopen(fileName, "r");
	Preferenza temp;
	List l = emptyList();

	if (file != NULL) {
		while (fscanf(file, "%s %s\n", temp.matricola, temp.corso) != EOF) {
			if (!memberList(temp, l)) {
				l = cons(temp, l);
			}
		}
	}
	fclose(file);
	return l;
}

Test getTestMiglioreByMatricola(Test * haystack, char * needle, int size)
{
	Test result;
	boolean found = FALSE;
	int punteggio_temp;
	int max_punteggio = 0;
	Punteggio punt_temp[4];
	Date temp_date;


	strcpy(result.matricola, needle);

	for (int i = 0; i < size; i++) {
		if (strcmp(haystack[i].matricola, needle) == 0) {
			if ((punteggio_temp = getPunteggioTotale(haystack[i])) > max_punteggio) {
				max_punteggio = punteggio_temp;
				for (int j = 0; j < 4; j++) {
					punt_temp[j] = haystack[i].punteggi[j];
				}
				temp_date = haystack[i].date;
				found = TRUE;
			}
		}
	}
	if (!found) {
		strcpy(result.matricola, "NOT_FOUND");
	}
	else {
		result.date = temp_date;
		for (int i = 0; i < 4; i++) {
			result.punteggi[i] = punt_temp[i];
		}
	}
	return result;
}

void ammessi(Test * v, int dim, List elenco, int postiDisponibili, char * corso)
{
	int migliori_dim = getSizeByCorso(elenco, corso);
	int posti_rimasti = postiDisponibili;
	Test * migliori = (Test*)malloc(sizeof(Test) * migliori_dim);
	int c = 0;
	List temp = elenco;
	while (!isEmpty(temp)) {
		if (strcmp(corso, temp->value.corso) == 0) {
			migliori[c] = getTestMiglioreByMatricola(v, temp->value.matricola, dim);
			c++;
		}
		temp = temp->next;
	}
	ordina(migliori, migliori_dim);
	for (int i = 0; i < migliori_dim && posti_rimasti > 0; i++) {
		printf("\nLa matricola %s e' ammessa al corso di %s", migliori[i].matricola, corso);
		posti_rimasti--;
	}
	printf("\n");
	free(migliori);
}
