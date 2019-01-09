/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _RIST_H
#define _RIST_H

#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "Common.h"
#include "List.h"

Pasto leggiPasto(FILE * fp);

Pasto * leggiTutti(char * fileName, int * dim);

void stampaPasti(Pasto * v, int dim);

List elenco(char * fileName);
float totaleAzienda(Pasto * v, int dim, List elenco, char * azienda);

void totali(Pasto * v, int dim, List elenco);

#endif 