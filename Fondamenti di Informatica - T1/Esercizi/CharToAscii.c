#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void) {
    int end = 0;
    char c;
    while (end == 0) {
        
        printf("Inserisci un carattere dell'alfabeto: ");
        scanf("%c", &c);
        if(c == '0') {
            printf("\nProgramma Terminato");
            end = 1;
        }
        else if (c > 64 && c < 91 || c > 96 && c < 123) {
            printf("Il carattere '%c' sotto forma ASCII equivale a %d\n", c, c);
        }
        else {
            printf("Non hai inserito un carattere valido. Riprova.\n");
        }
        while ((getchar()) != '\n');
    }
	return 0;
}