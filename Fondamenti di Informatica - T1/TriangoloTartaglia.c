#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

void printTartaglia(int rows) {
	int spaces = rows;
	for (int n = 0; n < rows; n++) {
		//for (int r = 0; r < spaces/2; r++) {
			printf("%*c", spaces, ' ');
		//}
		for (int k = 0; k < n + 1; k++) {
			printf("  %d	", fact(n) / (fact(k)*fact(n - k)));
		}
		printf("\n");
		spaces--;
	}
}


int main(void) {

	
	printTartaglia(5);

	return 0;
}