/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _ELEMENT_H
#define _ELEMENT_H
#include "Common.h"
#include "Time.h"


typedef struct Punteggio {
	char materia[16];
	int punteggio;
} Punteggio;

typedef struct Test {
	Date date;
	char matricola[16];
	Punteggio punteggi[4];
} Test;

typedef struct Preferenza {
	char matricola[16];
	char corso[16];
} Preferenza;

typedef Preferenza element;


void swap(Test * t1, Test * t2);

int getPunteggioTotale(Test t);

int compareTest(Test t1, Test t2);




#endif 