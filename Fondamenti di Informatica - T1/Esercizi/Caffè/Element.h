/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _ELEMENT_H
#define _ELEMENT_H
#include "Common.h"
#include "Time.h"
#define DIM_DITTA 256

typedef struct Ordine
{
	Date data;
	char tipo[8];
	char gusto[256];
	int conf_richieste;
	int id_cliente;
} Ordine;

typedef struct Costo {
	char tipo[8];
	char gusto[256];
	float prezzo;
} Costo;

typedef Costo element;

int compareOrdine(Ordine el1, Ordine el2);

boolean equals(element el1, element el2);

void swap(element * el1, element * el2);

#endif 