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
#include "Gara.h"

int main() {

	List gare = leggi("gara.txt");
	showList(gare);

	int sizeof_squadre;

	Squadra * squadre = estrai(gare, &sizeof_squadre);

	totale(squadre, sizeof_squadre, gare);
	
    return 0;
}
