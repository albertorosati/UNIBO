/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _TEST_H
#define _TEST_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Element.h"
#include "Common.h"
#include "Sort.h"
#include "List.h"

Test leggiUnTest(FILE * fp);
Test * leggiTutti(char * fileName, int * dim);
void stampaTest(Test * v, int dim);
void ordina(Test * v, int dim);

List pref(char * fileName);

Test getTestMiglioreByMatricola(Test * haystack, char * needle, int size);

void ammessi(Test * v, int dim, List elenco, int postiDisponibili, char* corso);

#endif 