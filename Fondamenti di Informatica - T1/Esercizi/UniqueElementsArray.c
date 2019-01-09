#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define boolean int
#define FALSE 0
#define TRUE 1
#define DIM 10

boolean array_contains(int a[], int size, int needle) {
	int end = 0;
	boolean result = FALSE;
	for (int i = 0; i < size && end == 0; i++) {
		if (a[i] == needle) {
			end = 1;
			result = TRUE;
		}
	}
	return result;
}

int uniqueArray(int a1[], int size, int a2[]) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (j == 0) {
			a2[j] = a1[i];
			j++;
		}
		else {
			if (!array_contains(a2, size, a1[i])) {
				a2[j] = a1[i];
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
		printf("Inserisci un numero: ");
		scanf("%d", &n);
		if (n != 0) {
			a1[i] = n;
			i++;
		}
	}

	int j = uniqueArray(a1, DIM, a2);
	printf("\n\n");
	for (int i = 0; i < j; i++) {
		printf("%d\n", a2[i]);
	}


	
	return 0;
}