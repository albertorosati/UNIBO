/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Gara.h"

Gara leggiUno(FILE * fp)
{
	Gara result;
	char temp;
	if (fp == NULL || feof(fp)) {
		strcpy(result.nome, "");
	}
	else {
		//Federico Chesani;CUBO A.P.S.;controlloStart controlloA controlloB controlloC controlloEnd
		fscanf(fp, "%[^;];%[^;];", result.nome, result.squadra);
		while ((temp = fgetc(fp)) != '\n' && !feof(fp)) {
			if (temp == 'S') {
				result.controlloStart = 1;
			}
			else if (temp == 'A') {
				result.controlloA = 1;
			}
			else if (temp == 'B') {
				result.controlloB = 1;
			}
			else if (temp == 'C') {
				result.controlloC = 1;
			}
			else if (temp == 'E') {
				result.controlloEnd = 1;
			}
		}
		if (result.controlloStart != 1) result.controlloStart = 0;
		if (result.controlloA != 1) result.controlloA = 0;
		if (result.controlloB != 1) result.controlloB = 0;
		if (result.controlloC != 1) result.controlloC = 0;
		if (result.controlloEnd != 1) result.controlloEnd = 0;

	}
	return result;
}

List leggi(char * fileName)
{
	List result = emptyList();
	FILE * file = fopen(fileName, "r");
	Gara temp;
	if (file == NULL) {
		perror("Errore durante l'apertura del file");
	}
	else {
		while (strcmp("", (temp = leggiUno(file)).nome) != 0) {
			result = cons(temp, result);
		}
	}
	return result;
}

int punti(Gara g)
{
	int result = 0;
	if (g.controlloStart == 1 && g.controlloEnd == 1 && g.controlloA == 1) {
		result += 50;
		if (g.controlloB == 0 && g.controlloC == 1) {
			result = 0;
		}
		else {
			result += 105;
			if (g.controlloC == 1) {
				result += 157;
			}
		}
	}
	return result;
}

void ordina(Squadra * v, int dim)
{
	bubbleSort(v, dim);
}


Squadra * estrai(List elenco, int * dim)
{
	List squadre_unique_list = emptyList();
	List squadre_unique_list_temp;
	int i = 0;
	Squadra * squadre;
	(*dim) = 0;
	
	while (!isEmpty(elenco)) {
		if (!memberList(elenco->value, squadre_unique_list)) {
			squadre_unique_list = cons(elenco->value, squadre_unique_list);
		}
		elenco = elenco->next;
	}

	squadre_unique_list_temp = squadre_unique_list;

	while (!isEmpty(squadre_unique_list)) {
		(*dim)++;
		squadre_unique_list = squadre_unique_list->next;
	}

	squadre = (Squadra*)malloc(sizeof(Squadra) * (*dim));

	squadre_unique_list = squadre_unique_list_temp;

	while (!isEmpty(squadre_unique_list)) {
		strcpy(squadre[i].nome, squadre_unique_list->value.squadra);
		
		squadre_unique_list = squadre_unique_list->next;
		i++;
	}
	freeList(squadre_unique_list);
	return squadre;
}

void totale(Squadra * classifica, int dim, List elenco) {
	List temp = elenco;
	int cont_punti;
	for (int i = 0; i < dim; i++) {
		cont_punti = 0;
		while (!isEmpty(elenco)) {
			if (strcmp(elenco->value.squadra, classifica[i].nome) == 0) {
				cont_punti += punti(elenco->value);
			}
			elenco = elenco->next;
		}
		classifica[i].punti = cont_punti;
		printf("Squadra '%s' ha classificato %d punti\n", classifica[i].nome, classifica[i].punti);
	}
}