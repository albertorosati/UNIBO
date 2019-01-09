/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef LIBRI_H
#define LIBRI_H
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "List.h"
#include "Sort.h"

typedef struct Ordine {
	int id;
	int user_id;
	List books;
} Ordine;

List leggi(char * fileName);

void stampaLibri(List elencoLibri);

Ordine * getOrdiniByList(List l, int * dim);

List filtra(List elencoLibri);

Ordine estrai(List elencoLibri, int idOrdine);

int compareOrdini(Ordine o1, Ordine o2);

void ordina(Ordine * v, int dim);

#endif