#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define DIM 10

int main() {

	int i = 0, n = 1;


	int a1[DIM], a2[DIM];


	while (i < DIM && n != 0) {
		printf("Inserisci un numero per l'array A1: ");
		scanf("%d", &n);
		if (n != 0) {
			a1[i] = n;
			i++;
		}
	}


	int j = 0;
	n = 1;

	while (j < DIM && n != 0) {
		printf("Inserisci un numero per l'array A2: ");
		scanf("%d", &n);
		if (n != 0) {
			a2[j] = n;
			j++;
		}
	}

	int array_size = i + j;
	i = 0, j = 0;

	for (int k = 0; k < array_size; k++) {
		if (a1[i] <= a2[j] && i < array_size/2) {
			printf("%d\n", a1[i]);
			i++;
		}
		else {
			printf("%d\n", a2[j]);
			j++;
		}
	}

	
	return 0;
}