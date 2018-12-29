/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "element.h"

int comparePasto(Pasto p1, Pasto p2)
{
	int result = strcmp(p1.cognome, p2.cognome);

	if (result == 0) {
		if (p1.importo > p2.importo) {
			result = -1;
		}
		else if (p1.importo < p2.importo) {
			result = 1;
		}
	}
	return result;
}

int compareDipendente(Dipendente d1, Dipendente d2)
{
	int result = strcmp(d1.azienda, d2.azienda);
	if (result == 0) {
		result = strcmp(d1.cognome, d2.cognome);
	}
	return result;
}
