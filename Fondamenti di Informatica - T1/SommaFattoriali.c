#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void) {
	
	int index, result, fact;
	result = 0;

	printf("Quanti numeri vuoi inserire? ");
	scanf("%d", &index);

	for (int i = 0; i < index; i++) {
		int display = i + 1;
		printf("Inserisci il %d° numero: ", display);
		scanf("%d", &fact);

		if (fact == 0) {
			result += 1;
		}
		else {
			int temp = 1;
			for (int j = 1; j <= fact; j++) {
				temp *= j;
			}
			result += temp;
		}
	}
	printf("Il fattoriale equivale a %d", result);

	return 0;
}