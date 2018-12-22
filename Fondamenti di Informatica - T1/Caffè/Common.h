/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>

typedef enum { FALSE, TRUE } boolean;

void cleanBuffer();

void swapInt(int *a, int *b);

int getMax(int a, int b);

int getMin(int a, int b);

int countLinesInFile(FILE * file);

#endif