/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef ELEMENT_H
#define ELEMENT_H

#include <string.h>
#include "Common.h"

typedef struct Libro {
	int id;
	int user_id;
	char title[512];
	float price;
} Libro;

typedef Libro element;

boolean areBooksEqual(Libro l1, Libro l2);

#endif 