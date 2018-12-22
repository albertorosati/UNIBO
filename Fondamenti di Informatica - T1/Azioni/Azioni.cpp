#define _CRT_SECURE_NO_DEPRECATE
#include "Azioni.h"
#include <string.h>

int leggi(FILE * file, Azione azione[], int dim, char name[])
{
	Azione azione_temp;
	int i = 0;
	while (i < dim && fscanf(file, "%s %f %f %d\n", azione_temp.name, &azione_temp.open_value, &azione_temp.close_value, &azione_temp.day) != EOF) {
		if (strcmp(azione_temp.name, name) == 0) {
			azione[i] = azione_temp;
			i++;
		}
	}

	return i;
}
