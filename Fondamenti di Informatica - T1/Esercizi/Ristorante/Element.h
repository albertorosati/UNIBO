/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _ELEMENT_H
#define _ELEMENT_H
#include <string.h>
#include "Common.h"
#include "Time.h"


typedef struct Pasto {
	char cognome[32];
	int num_persone;
	float importo;
} Pasto;

typedef struct Dipendente {
	char cognome[32];
	char azienda[64];
} Dipendente;

typedef Dipendente element;

int comparePasto(Pasto p1, Pasto p2);

int compareDipendente(Dipendente d1, Dipendente d2);


#endif 