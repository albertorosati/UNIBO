#include "Rist.h"

Pasto leggiPasto(FILE * fp)
{
	Pasto result;
	Pasto temp;
	boolean found = FALSE;
	strcpy(result.cognome, "NULL");
	if (fp != NULL) {
		if (!feof(fp)) {
			while (fscanf(fp, "%s %d %f\n", temp.cognome, &temp.num_persone, &temp.importo) != 1 && !found) {
				result = temp;
				found = TRUE;
			}
		}
	}
	return result;
}


Pasto * leggiTutti(char * fileName, int * dim) {
	FILE * file = fopen(fileName, "r");
	(*dim) = 0;
	Pasto * pasti;
	Pasto temp;
	int i = 0;
	if (file != NULL) {
		while (strcmp((temp = leggiPasto(file)).cognome, "NULL") != 0) {
			(*dim)++;
		}
		rewind(file);
		pasti = (Pasto*)malloc(sizeof(Pasto) * (*dim));
		while (strcmp((temp = leggiPasto(file)).cognome, "NULL") != 0L) {
			pasti[i] = temp;
			i++;
		}
	}
	else {
		perror("Errore durante l'apertura del file");
		pasti = NULL;
	}
	return pasti;
}

void stampaPasti(Pasto * v, int dim) {
	for (int i = 0; i < dim; i++) {
		printf("\n-----------\nNome: %s\nNumero: %d\nImporto: %f\n----------\n", 
			v[i].cognome, v[i].num_persone, v[i].importo);
	}
}

List elenco(char * fileName)
{
	FILE * file = fopen(fileName, "r");
	List list = emptyList();
	List result = emptyList();
	Dipendente temp;
	if (file != NULL) {
		while (fscanf(file, "%s %s\n", temp.cognome, temp.azienda) != EOF) {
			list = insord(temp, list);
		}
		while (!isEmpty(list)) {
			result = cons(list->value, result);
			list = list->next;
		}
	}
	
	return result;
}

float totaleAzienda(Pasto * v, int dim, List elenco, char * azienda)
{
	float result = 0;
	while (!isEmpty(elenco)) {
		if (strcmp(azienda, elenco->value.azienda) == 0) {
			for (int i = 0; i < dim; i++) {
				if (strcmp(v[i].cognome, elenco->value.cognome)) {
					result += v[i].importo * (float) v[i].num_persone;
				}
			}
		}
		elenco = elenco->next;
	}
	return result;
}

void totali(Pasto * v, int dim, List elenco) {
	while (!isEmpty(elenco)) {
		if (!memberList(elenco->value, elenco->next)) {
			float importo = totaleAzienda(v, dim, elenco, elenco->value.azienda);
			printf("\nTotale dovuto dall'azienda '%s': %f", elenco->value.azienda, importo);
		}
		elenco = elenco->next;
	}
}