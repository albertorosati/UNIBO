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
#include "Rist.h"

int main() {
	int size_pasti;
	Pasto * pasti = leggiTutti("pasti.txt", &size_pasti);
	

	insertSort(pasti, size_pasti);

	stampaPasti(pasti, size_pasti);

	List dip = elenco("aziende.txt");

	showList(dip);

	totali(pasti, size_pasti, dip);

	free(pasti);
	freeList(dip);


    return 0;
}
