#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define DIM 10

int array_contains(int a[], int size, int needle) {
	int end = 0;
	int result = -1;
	for (int i = 0; i < size && end == 0; i++) {
		if (a[i] == needle) {
			end = 1;
			result = i;
		}
	}
	return result;
}

int intersectionArray(int a1[], int size, int a2[]) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (j == 0) {
			a2[j] = a1[i];
			j++;
		}
		else {
			if (array_contains(a2, size, a1[i]) == -1) {
				printf("%d\n", a1[i]);
				j++;
			}
		}
	}
	return j;
}

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


	i = 0, n = 1;

	while (i < DIM && n != 0) {
		printf("Inserisci un numero per l'array A2: ");
		scanf("%d", &n);
		if (n != 0) {
			a1[i] = n;
			i++;
		}
	}

	intersectionArray(a1, DIM, a2);


	
	return 0;
}