#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include "MCM.h";

int main(void) {
	int result, n;
	printf("Inserisci il primo valore: ");
	scanf("%d", &result);
	while (result < 100) {
		printf("Inserisci un valore: ");
		scanf("%d", &n);
		result = mcm(result, n);
		printf("mcm: %d\n", result);
	}
	return 0;
}