/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _ORDINI_H
#define _ORDINI_H
#define _CRT_SECURE_NO_DEPRECATE
#include "Element.h"
#include <stdlib.h>
#include "Common.h"
#include <string.h>
#include "List.h"
#include "Sort.h"

boolean isNotMalformed(Ordine o);

Ordine * leggiTutti(char * fileName, int * dim);

void stampa(Ordine * v, int dim);

List leggiCosti(char * fileName);

float getPriceByList(List l, char * tipo, char * gusto);

void fatture(Ordine * v, int dim, List costi);


#endif 