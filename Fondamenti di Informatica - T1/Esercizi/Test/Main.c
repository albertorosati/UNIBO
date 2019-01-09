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
#include "Test.h"

int main() {
	int size_test;
	Test * test = leggiTutti("risultati.txt", &size_test);
	ordina(test, size_test);
	stampaTest(test, size_test);
	List l = pref("preferenze.txt");
	showList(l);

	ammessi(test, size_test, l, 5, "Ingegneria");

	free(test);
	freeList(l);
    return 0;
}
