/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

typedef enum { FALSE, TRUE } boolean;

void cleanBuffer();

int getMaxInt(int a, int b);

int getMinInt(int a, int b);

int countLinesInFile(FILE * file);

#endif