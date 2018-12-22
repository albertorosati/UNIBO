/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _GARA_H
#define _GARA_H

#define _CRT_SECURE_NO_DEPRECATE
#include "Common.h"
#include "Array.h"
#include "Element.h"
#include "List.h"
#include "Sort.h"
#include <string.h>
#include <stdlib.h>

Gara leggiUno(FILE * fp);
List leggi(char * fileName);
int punti(Gara g);
void ordina(Squadra * v, int dim);
Squadra * estrai(List elenco, int * dim);

int memberOfSquadra(Squadra * a, int dim);

void totale(Squadra * classifica, int dim, List elenco);

#endif