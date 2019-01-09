#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

void printChar(char c[]) {
	if (c[0] != '\0') {
		printf("%c\n", c[0]);
		printChar((c + 1));
	}
}

int main() {
	char string[5] = "Ciao";
	printChar(string);
	return 0;
}