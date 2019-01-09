/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef LIST_H
#define LIST_H

#include "Element.h"
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_element
{
	element value;
	struct list_element *next;
} Item;

typedef Item* List;

/* PRIMITIVE */

List emptyList(void);

boolean isEmpty(List l);

List cons(element el, List l);

element head(List l);

List tail(List l);

/* NON PRIMITIVE */

void freeList(List l);

void showList(List l);

int memberList(element el, List l);

List insert(element el, List l);

List subList(int n, List l);

int countElements(List l);

//List intersect(List l1, List l2);

//List diff(List l1, List l2);

//List insord(element el, List l);

//element select(List l, int index);



#endif 