/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _TIME_H
#define _TIME_H

#include <stdio.h>
#include "Common.h"

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct Timestamp {
	int h;
	int m;
	int s;
} Timestamp;

int compareDates(Date d1, Date d2);

int compareTimestamp(Timestamp t1, Timestamp t2);

Timestamp getNullTime();

boolean isTimeNull(Timestamp t);

void printTimestamp(Timestamp t);

void printDate(Date d);

#endif 