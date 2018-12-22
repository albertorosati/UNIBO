#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_SIZE 20
#define BOOK_MAX 10

typedef enum { FALSE, TRUE } boolean;

typedef struct {
	char name[ARR_SIZE];
	char surname[ARR_SIZE];
} Author;

typedef struct { 
	int code;
	char title[ARR_SIZE];
	Author author;
	int stock;
} Book;

void cleanBuffer() {
	while ((getchar()) != '\n');
}

int readArray(Book books[], int dim) {
	int input_value = 1;
	int i = 0;
	Book temp;
	printf("INIZIALIZZO LA LETTURA DELL'ARRAY");
	while (input_value != 0 && i < dim) {
		printf("\nInserisci il codice del libro: ");
		while (scanf("%d", &input_value) != 1) {
			printf("\nInput non valido. Riprova: ");
			cleanBuffer();
		}

		if (input_value != 0) {
			temp.code = input_value;
			cleanBuffer();
			
			printf("Inserisci il titolo del libro: ");
			while (scanf_s("%[^\n]", temp.title, ARR_SIZE) != 1) {
				printf("\nInput non valido. Riprova: ");
				cleanBuffer();
			}
			cleanBuffer();
			
			printf("Inserisci il nome dell'autore: ");
			while (scanf_s("%[^\n]", temp.author.name, ARR_SIZE) != 1) {
				printf("\nInput non valido. Riprova: ");
				cleanBuffer();
			}
			cleanBuffer();
			
			printf("Inserisci il cognome dell'autore: ");
			while (scanf_s("%[^\n]", temp.author.surname, ARR_SIZE) != 1) {
				printf("\nInput non valido. Riprova: ");
				cleanBuffer();
			}
			cleanBuffer();

			printf("Inserisci la quantita' disponibile: ");
			while (scanf("%d", &temp.stock) != 1) {
				printf("\nInput non valido. Riprova: ");
				cleanBuffer();
			}
			books[i] = temp;
			i++;
		}
		else {
			printf("\nLETTURA COMPLETATA.\n%d LIBRI LETTI CON SUCCESSO\n", i);
		}
	}
	return i;
}

void printBook(Book book) {
	printf("CODICE:		%d\n", book.code);
	printf("TITOLO:		%s\n", book.title);
	printf("AUTORE:		%s %s\n", book.author.name, book.author.surname);
	printf("IN STOCK:	%d\n", book.stock);
}

void showBooks(Book books[], int size) {
	printf("\n\n///////////////////////////////\n\n");
	for (int i = 0; i < size; i++) {
		printf("\n_______ LIBRO N. %d _______\n\n", i + 1);
		printBook(books[i]);
		printf("___________________________\n");
	}
	printf("\n\n///////////////////////////////\n\n");
}

void searchBook(Book books[], int size) {
	printf("\n\nInserisci il codice di un libro: ");
	int code;
	scanf("%d", &code);
	boolean found = FALSE;
	int i;
	for (i = 0; i < size && !found; i++) {
		if (books[i].code == code) {
			found = TRUE;
		}
	}
	if (found) {
		printf("\n_______ RISULTATO _________\n\n");
		printBook(books[i]);
		printf(  "___________________________\n");
	}
	else {
		printf("\n\nNon ho trovato il codice che hai inserito. Riprova.\n\n");
	}
}

void showLastBooks(Book books[], int size) {
	printf("\n\nInserisci il numero soglia: ");
	int threshold;
	scanf("%d", &threshold);
	int c = 0;
	if (threshold > 0) {
		printf("\n\n///////////////////////////////\n\n");
		for (int i = 0; i < size; i++) {
			if (books[i].stock <= threshold) {
				printf("\n_______ LIBRO N. %d _______\n\n", i + 1);
				printBook(books[i]);
				printf("___________________________\n");
				c++;
			}
		}
		if (c < 0) {
			printf("\n\nNon sono riuscito a trovare nessun libro con il codice da te selezionato.\nRiprova\n\n");
		}
		printf("\n\n///////////////////////////////\n\n");
	}
}

void close() {
	printf("\nProgramma terminato con successo.\n");
	system("PAUSE");
}

void initializeMenu(Book books[], int books_size) {
	int input = 0;
	while (input != 4) {
		printf("\n_________ GESTIONE LIBRERIA _________\n\n");
		printf("1.	Visualizza l'elenco dei libri\n");
		printf("2.	Ricerca un libro\n");
		printf("3.	Visualizza libri in esaurimento\n");
		printf("4.	Chiudi\n");

		printf("\nCOMANDO: ");
		scanf("%d", &input);
		switch (input) {
		case 1: showBooks(books, books_size);  break;
		case 2: searchBook(books, books_size); break;
		case 3: showLastBooks(books, books_size); break;
		case 4: close(); break;
		default: printf("\nInserisci un comando valido.\n"); input = 0;  break;
		}
	}
}

int main() {
	Book books[BOOK_MAX];
	int books_size = readArray(books, ARR_SIZE);
	initializeMenu(books, books_size);
	return 0;
}