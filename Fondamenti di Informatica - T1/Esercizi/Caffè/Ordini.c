#include "Ordini.h"

boolean isNotMalformed(Ordine o)
{
	boolean result = FALSE;
	if (strcmp(o.tipo, "cialda") == 0 || strcmp(o.tipo, "capsula") == 0) {
		if (o.id_cliente > 0 && o.conf_richieste > 0) {
			result = TRUE;
		}
	}
	return result;
}

Ordine * leggiTutti(char * fileName, int * dim)
{
	FILE * file = fopen(fileName, "r");
	Ordine temp;
	Ordine * ordini;
	int i = 0;
	(*dim) = 0;
	if (file == NULL) {
		perror("Errore durante l'apertura del file");
		ordini = NULL;

	}
	else {
		while (fscanf(file, "%d/%d/%d %s %s %d %d\n", &temp.data.year, &temp.data.month, &temp.data.day,
			temp.tipo, temp.gusto, &temp.conf_richieste, &temp.id_cliente) != EOF) {
			if (isNotMalformed(temp)) {
				(*dim)++;
			}
		}

		ordini = (Ordine*)malloc(sizeof(Ordine) * (*dim));

		rewind(file);

		while (fscanf(file, "%d/%d/%d %s %s %d %d\n", &temp.data.year, &temp.data.month, &temp.data.day,
			temp.tipo, temp.gusto, &temp.conf_richieste, &temp.id_cliente) != EOF) {
			if (isNotMalformed(temp)) {
				ordini[i] = temp;
				i++;
			}
		}
	}
	return ordini;
}

void stampa(Ordine * v, int dim)
{
	for (int i = 0; i < dim; i++) {
		printf("\n* ORDINE N. %d:", i + 1);
		printf("\n- DATA:		%d/%d/%d", v[i].data.year, v[i].data.month, v[i].data.day);
		printf("\n- TIPO:		%s", v[i].tipo);
		printf("\n- NUM CONF:	%d", v[i].conf_richieste);
		printf("\n- ID CLIENTE:	%d\n", v[i].id_cliente);
	}
}

List leggiCosti(char * fileName)
{
	List result = emptyList();
	FILE * file = fopen(fileName, "r");
	Costo temp;
	if (file != NULL) {
		while (fscanf(file, "%s %s %f\n", temp.tipo, temp.gusto, &temp.prezzo) != EOF) {
			result = cons(temp, result);
		}
		fclose(file);
	}
	return result;
}

float getPriceByList(List l, char * tipo, char * gusto) {
	float result = 0;
	boolean found = FALSE;
	while (!isEmpty(l) && !found) {
		if (strcmp(tipo, l->value.tipo) == 0 && strcmp(gusto, l->value.gusto) == 0) {
			result = l->value.prezzo;
			found = TRUE;
		}
		l = l->next;
	}
	return result;
}

void fatture(Ordine * v, int dim, List costi)
{
	int temp_mese;
	float importo = 0;
	Ordine * ordini_sorted = (Ordine*)malloc(sizeof(Ordine)*dim);
	mergeSort(v, 0, dim - 1, ordini_sorted);

	temp_mese = ordini_sorted[0].data.month;

	for (int i = 0; i < dim; i++) {
		if (temp_mese == ordini_sorted[i].data.month) {
			importo += getPriceByList(costi, ordini_sorted[i].tipo, ordini_sorted[i].gusto) * ordini_sorted[i].conf_richieste;
			if (i == dim-1) {
				printf("Cliente %d, Mese: %d/%d, Totale dovuto:		%f\n", ordini_sorted[i].id_cliente, ordini_sorted[i].data.year, ordini_sorted[i].data.month, importo);
			}
		}
		else {
			temp_mese = ordini_sorted[i].data.month;
			printf("Cliente %d, Mese: %d/%d, Totale dovuto:		%f\n", ordini_sorted[i-1].id_cliente, ordini_sorted[i-1].data.year, ordini_sorted[i-1].data.month, importo);
			importo = 0;
			importo += getPriceByList(costi, ordini_sorted[i].tipo, ordini_sorted[i].gusto) * ordini_sorted[i].conf_richieste;
		}
	}
}