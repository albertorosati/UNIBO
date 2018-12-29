/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* OPERAZIONI PRIMITIVE */
List emptyList(void) /* costruttore Lista vuota */
{
	return NULL;
}

boolean isEmpty(List l) /* verifica se Lista vuota */
{
	return (l == NULL);
}

List cons(element e, List l)
{
	List t; /* costruttore che aggiunge in testa alla Lista */
	t = (List)malloc(sizeof(Item));
	t->value = e;
	t->next = l;
	return(t);
}

element head(List l) /* selettore testa Lista */
{
if (isEmpty(l)) exit(-2);
else return (l->value);
}

List tail(List l) /* selettore coda Lista */
{
	if (isEmpty(l)) exit(-1);
	else return (l->next);
}

void showList(List l) { // NON PRIMITIVE
	printf("{\n");
	while (!isEmpty(l)) {
		printf("[ azi: %s, cogn: %s]", l->value.azienda, l->value.cognome);
		l = tail(l);
		//Se la lista non è terminata, inserisco una virgola separatrice
		if (!isEmpty(l)) printf(",\n ");
	} 
	printf("\n}\n");
}


int memberList(element el, List l) {
	int result = 0;
	while (!isEmpty(l) && !result) {
		result = (strcmp(el.azienda, head(l).azienda) == 0);
		if (!result)
			l = tail(l);
	}
	return result;
}


List insert(element el, List l)
{
	List t;
	t = (List)malloc(sizeof(Item));
	t->value = el; t->next = l;
	return t;
}

List subList(int n, List l)
{
	int i = 1;
	while ((l != NULL) && (i < n)) {
		l = l->next; i++;
	}
	return l;
}

void freeList(List l) {
	if (isEmpty(l))
		return;
	else {
		freeList(tail(l));
		free(l);
	}
	return;
}
/*
List intersect(List l1, List l2) {
	List result = emptyList();
	while (!isEmpty(l1)) {
		if (memberList(l1->value, l2)) {
			result = insert(l1->value, result);
		}
		l1 = l1->next;
	}
	return result;
}*/
/*
List diff(List l1, List l2) {
	List result = emptyList();
	while (!isEmpty(l1)) {
		if (!memberList(l1->value, l2)) {
			result = insert(l1->value, result);
		}
		l1 = l1->next;
		
	}
	return result;
}*/

List insord(element el, List l) {
	if (isEmpty(l)) return cons(el, l);
	else if (compareDipendente(el, head(l)) == 1) return cons(el, l);
	else return cons(head(l), insord(el, tail(l)));
}

/*
element select(List l, int index) {
	if (l == NULL) return -1;
	else if (index == 0) return l->value;
	else return select(l->next, index - 1);
}*/