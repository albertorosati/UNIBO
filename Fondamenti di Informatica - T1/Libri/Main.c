/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Libri.h"


int main() {

	List libri = leggi("libri.txt");
	stampaLibri(libri);

	int sizeof_ordini;
	Ordine * ordini = getOrdiniByList(libri, &sizeof_ordini);

	for (int i = 0; i < sizeof_ordini; i++) {
		printf("\n* Ordine n. %d\n", ordini[i].id);
		printf("* ID utente: %d\n", ordini[i].user_id);
		printf("Libri acquistati:\n");
		printf("-------------------\n");
		showList(ordini[i].books);
		freeList(ordini[i].books);
		printf("-------------------\n");
	}

	freeList(libri);
	free(ordini);
	
    return 0;
}
