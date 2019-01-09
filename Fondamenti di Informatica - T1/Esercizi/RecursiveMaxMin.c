#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void returnMaxMin(int *max, int *min) {
	int n;
	printf("Inserisci un numero: ");
	scanf("%d", &n);
	if (n == 0) {
		return;
	}
	else {
		if (n >= *max)
			*max = n;
		if (n <= *min)
			*min = n;
		returnMaxMin(max, min);
	}	
}

int main(void) {
	int max = 0, min = 1;
	returnMaxMin(&max, &min);
	printf("MAX: %d\nMIN: %d", max, min);
	return 0;
}