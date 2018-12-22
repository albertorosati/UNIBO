#include "Libri.h"

List leggi(char * fileName)
{
	List result = emptyList();
	Libro temp;
	FILE * file = fopen(fileName, "r");
	if (file == NULL) {
		perror("Errore durante l'apertura del file");
	}
	else {
		//123 45 Recommender_Systems_The_Textbook 51.42
		while (fscanf(file, "%d %d %s %f\n", &temp.id, &temp.user_id, temp.title, &temp.price) != EOF) {
			result = cons(temp, result);
		}
		fclose(file);
	}
	return result;
}

void stampaLibri(List elencoLibri)
{
	if (!isEmpty(elencoLibri)) {
		printf("\n*id libro: %d\n*id utente: %d\n*titolo: %s\n*prezzo: %f\n",
			elencoLibri->value.id, elencoLibri->value.user_id, elencoLibri->value.title, elencoLibri->value.price);
		stampaLibri(elencoLibri->next);
	}
}

List filtra(List elencoLibri)
{
	List result = emptyList();

	while (!isEmpty(elencoLibri)) {
		if (!memberList(elencoLibri->value, result)) {
			result = cons(elencoLibri->value, result);
		}
		elencoLibri = elencoLibri->next;
	}

	return result;
}

boolean isMember(Ordine * haystack, int id, int dim) {
	boolean result = FALSE;
	for (int i = 0; i < dim && !result; i++) {
		if (haystack[i].id == id) {
			result = TRUE;
		}
	}
	return result;
}

Ordine estrai(List elencoLibri, int idOrdine)
{
	Ordine result;
	List list_ordine = emptyList();
	boolean found = FALSE;
	while (!isEmpty(elencoLibri)) {
		if (elencoLibri->value.id == idOrdine) {
			list_ordine = cons(elencoLibri->value, list_ordine);
			if (!found) {
				result.user_id = elencoLibri->value.user_id;
			}
		}
		elencoLibri = elencoLibri->next;
	}
	result.id = idOrdine;
	result.books = list_ordine;
	return result;
}

Ordine * getOrdiniByList(List l, int * dim) {
	Ordine * ordini_temp = (Ordine*) malloc(sizeof(Ordine)*countElements(l));
	Ordine * result;
	l = filtra(l);
	List temp = l;
	int i = 0;
	(*dim) = 0;
	while (!isEmpty(l)) {
		if (!isMember(ordini_temp, l->value.id, (*dim))) {
			ordini_temp[(*dim)].id = l->value.id;
			(*dim)++;
		}
		l = l->next;
	}
	result = (Ordine*)malloc(sizeof(Ordine)*(*dim));
	l = temp;
	while (!isEmpty(l)) {
		if (!isMember(result, l->value.id, (*dim))) {
			result[i] = estrai(temp, l->value.id);
			i++;
		}
		l = l->next;
	}

	free(ordini_temp);
	return result;
}

int compareOrdini(Ordine o1, Ordine o2)
{
	int result = 0;
	if (o1.id > o2.id) {
		result = 1;
	}
	else if (o1.id < o2.id) {
		result = -1;
	}
	else {
		if (countElements(o1.books) > countElements(o2.books)) {
			result = 1;
		}
		else if (countElements(o1.books) < countElements(o2.books)) {
			result = -1;
		}
	}
	return result;
}

void ordina(Ordine * v, int dim) {
	bubbleSort(v, dim);
}
