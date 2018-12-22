/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Array.h"

int memberArray(int haystack[], int needle, int size)
{
	int result = -1;
	boolean found = FALSE;
	for (int i = 0; i < size && !found; i++) {
		if (haystack[0] == needle) {
			result = i;
			found = TRUE;
		}
	}
	return result;
}

/*int * uniqueElementsArray(int a[], int size)
{
	return NULL;
}*/

/*
int getMaxIndex(Catena a[], int size)
{
	int max_index = 0;
	Catena max = { 0, 0, 0, "" };
	for (int i = 0; i < size; i++) {
		if (compareCatena(a[i], max) == 1) {
			max = a[i];
			max_index = i;
		}
	}
	return max_index;
}*/
