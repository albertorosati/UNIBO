/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Common.h"

void cleanBuffer()
{
	while ((getchar()) != '\n');
}

void swapInt(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int getMax(int a, int b)
{
	return (a > b) ? a : b;
}

int getMin(int a, int b)
{
	return (a < b) ? a : b;
}

int countLinesInFile(FILE * file)
{
	int result = 1;
	char bin;
	rewind(file);
	while ((bin = fgetc(file)) != EOF) {
		if (bin == '\n') {
			result++;
		}
	}
	rewind(file);
	return result;
}
