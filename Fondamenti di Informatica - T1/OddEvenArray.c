#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void countOddEven(int a[], int size, int *pari, int *dispari) {
	for (int i = 0; i <= size; i++) {
		if (a[i] % 2 == 0) {
			*pari = *pari++;
		}
		else {
			*dispari = *dispari + 1;
		}
	}
}

int main() {
	int pari = 0, dispari = 0;

	int i = 0, n = 1;

	int a[10];

	while (i < 10 && n != 0) {
		printf("Inserisci un numero: ");
		scanf("%d", &n);
		if (n != 0) {
			a[i] = n;
			i++;
		}
	}

	countOddEven(a, i, &pari, &dispari);

	printf("\nPARI: %d\n", pari);
	printf("\nDISPARI: %d\n", dispari);


	
	return 0;
}