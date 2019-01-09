#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
int main() {
	int a[10];

	int i = 0;
	int n = 1;
	while (i < 10 && n != 0) {
		printf("Inserisci un numero: ");
		scanf("%d", &n);
		if (n > 0) {
			a[i] = n;
			i++;
		}
	}
	
	for (int k = 0; k < i; k++) {
		if (a[k] == k) {
			printf("%d\n", k);
		}
	}

	return 0;
}