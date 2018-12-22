/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _ELEMENT_H
#define _ELEMENT_H
#include "Common.h"
#include "Time.h"

typedef struct Gara {
	char nome[256];
	char squadra[256];
	int controlloStart;
	int controlloA;
	int controlloB;
	int controlloC;
	int controlloEnd;
} Gara;

typedef struct Squadra {
	char nome[256];
	int punti;
} Squadra;

typedef Gara element;

int compareSquadre(Squadra s1, Squadra s2);

void swap(Squadra * s1, Squadra * s2);

#endif 