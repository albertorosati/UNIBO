/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "element.h"

void swap(Test * t1, Test * t2)
{
	Test tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

int getPunteggioTotale(Test t)
{
	int totale = 0;
	for (int i = 0; i < 4; i++) {
		totale += t.punteggi[i].punteggio;
	}
	return totale;
}

int compareTest(Test t1, Test t2)
{
	int result = 0;
	if (getPunteggioTotale(t1) > getPunteggioTotale(t2)) {
		result = -1;
	}
	else if (getPunteggioTotale(t1) < getPunteggioTotale(t2)) {
		result = 1;
	}
	return result;
}
