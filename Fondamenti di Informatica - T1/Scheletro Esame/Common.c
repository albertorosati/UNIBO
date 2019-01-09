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

void fgetstring_s(FILE * file, char * string, int size, char end_char)
{
	string[0] = '\0';
	int i = 0;
	char temp;
	if (!feof(file) && size > 0) {
		while ((temp = fgetc(file)) != end_char && i < size-1) {
			string[i] = temp;
			i++;
		}
		string[i] = '\0';
		if (temp != end_char) {
			while ((temp = fgetc(file)) != end_char);
		}
	}
}
