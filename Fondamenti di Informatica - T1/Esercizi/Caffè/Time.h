/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _TIME_H
#define _TIME_H

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

int compareDates(Date d1, Date d2);

#endif 