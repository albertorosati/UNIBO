#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void msToMin(int *ms, int *sec, int *min) {
	while (*ms - 1000 >= 1000 || *ms - 1000 == 0) {
		*ms -= 1000;
		*sec += 1;
		while (*sec - 60 > 60 || *sec - 60 == 0) {
			*sec -= 60;
			*min += 1;
		}
	}
}


int main(void) {

	int ms, sec = 0, min = 0;
	printf("Inserisci i ms: ");
	scanf("%d", &ms);

	msToMin(&ms, &sec, &min);

	printf("MIN: %d, SEC: %d, MS: %d", min, sec, ms);

 	return 0;
}