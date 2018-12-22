#include <stdio.h>

typedef struct Azione {
	char name[64];
	float open_value;
	float close_value;
	int day;
} Azione;

int leggi(FILE * file, Azione azione[], int dim, char name[]);
