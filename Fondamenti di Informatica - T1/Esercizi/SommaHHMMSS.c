#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void secToHour(int *sec, int *min, int *hour) {
	while (*sec - 60 >= 0) {
		*sec -= 60;
		*min += 1;
		while (*min - 60 >= 0) {
			*min -= 60;
			*hour += 1;
		}
	}
}

int hourToSec(int sec, int min, int hour) {
	return (hour * 60 * 60) + (min * 60) + sec;
}


int main(void) {

	int sec, min, hour;
	int result = 0;
	printf("Inserisci i valori nel seguente formato 'HH MM SS' | Interrompi inserendo 00:00:00\n");
	do {
		printf("Inserisci il valore:\n");
		scanf("%d %d %d", &hour, &min, &sec);
 		result += hourToSec(sec, min, hour);	
	} while (sec != 0 && min != 0 && hour != 0);
	//} while (!(sec == 0 && min == 0 && hour == 0));

	int result_sec = result, result_min = 0, result_hour = 0;
	secToHour(&result_sec, &result_min, &result_hour);

	printf("HOUR: %d, MIN: %d, SEC: %d", result_hour, result_min, result_sec);

 	return 0;
}