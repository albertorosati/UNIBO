/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Element.h"

boolean areBooksEqual(Libro l1, Libro l2)
{
	boolean result = FALSE;
	if (l1.id == l2.id && l1.user_id == l2.user_id && strcmp(l1.title, l2.title) == 0) {
		result = TRUE;
	}
	return result;
}