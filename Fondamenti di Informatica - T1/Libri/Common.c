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

int getMaxInt(int a, int b)
{
	return (a > b) ? a : b;
}

int getMinInt(int a, int b)
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
