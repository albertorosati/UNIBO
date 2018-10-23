#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int min_to_sec(int i) {
	return i * 60;
}

int hours_to_sec(int i) {
	return min_to_sec(i * 60);
}

int main(void) {
	
	int h, m, s;

	printf("Inserisci i valori di ora, minuto e secondo separati da una virgola: ");
	scanf("%d,%d,%d", &h, &m, &s);

	int result = hours_to_sec(h) + min_to_sec(m) + s;
	
	printf("%dh %dm %ds equivalgono a %d", h, m, s, result);

	return 0;
}