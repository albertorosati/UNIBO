/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"
#include "Array.h"
#include "Sort.h"
#include "List.h"
#include "Ordini.h"

int main() {
	int dim_ordini;
	Ordine * ordini = leggiTutti("ordini.txt", &dim_ordini);
	stampa(ordini, dim_ordini);

	List costi = leggiCosti("costi.txt");

	fatture(ordini, dim_ordini, costi);

	free(ordini);
	freeList(costi);
	return 0;
}
