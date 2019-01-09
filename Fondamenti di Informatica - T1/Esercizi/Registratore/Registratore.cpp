#include "Registratore.h"
#include <string.h>

int copy(FILE * source, FILE * dest, char name[])
{
	Transaction temp;
	int i = 0;
	int miao;
	while (fread(&temp, sizeof(Transaction), 1, source) > 0) {
		if (_stricmp(name, temp.customer) == 0) {
			i++;
			fprintf(dest, "%s %d %f\n", temp.customer, temp.transactionId, temp.value);
		}
	}
	return i;
}
