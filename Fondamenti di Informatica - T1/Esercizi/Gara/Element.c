/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "element.h"

int compareSquadre(Squadra s1, Squadra s2)
{
	int result = 0;
	if (s1.punti > s2.punti) {
		result = 1;
	}
	else if (s1.punti < s2.punti) {
		result = -1;
	}
	else {
		result = strcmp(s1.nome, s2.nome);
	}
	return result;
}

void swap(Squadra * s1, Squadra * s2)
{
	Squadra tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
