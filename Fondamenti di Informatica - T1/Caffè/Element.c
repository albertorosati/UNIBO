/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "element.h"

int compareOrdine(Ordine el1, Ordine el2){
	int result = 0;
	if (el1.id_cliente < el2.id_cliente) {
		result = -1;
	}
	else if (el1.id_cliente > el2.id_cliente) {
		result = 1;
	}
	else {
		result = compareDates(el1.data, el2.data);
	}
	return result;
}

void swap(element * el1, element * el2) {
	element tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}