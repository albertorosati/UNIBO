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
		if (n != 0) {
			a[i] = n;
			i++;
		}
	}
	
	int b[10];
	int j = -1;
	for (int k = i; k >= 0; k--) {
		b[j] = a[k];
		j++;
	}

	for (int k = 0; k <= i-1; k++) {
		printf("%d", b[k]);
	}

	

	return 0;
}