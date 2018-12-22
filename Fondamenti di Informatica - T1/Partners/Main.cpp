#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SURNAME_DIM 21
#define PEOPLE_ARRAY_DIM 20

typedef enum { FALSE, TRUE } boolean;

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char surname[NAME_SURNAME_DIM];
	char name[NAME_SURNAME_DIM];
	Date birth_date;
	char gender;
} People;

int getMax(int a, int b) {
	return (a > b) ? a : b;
}

int getMin(int a, int b) {
	return (a < b) ? a : b;
}

boolean areCompatible(People p1, People p2) {
	boolean result = FALSE;
	if (p1.gender != p2.gender) {
		if (p1.birth_date.year == p2.birth_date.year) {
			result = TRUE;
		}
		else {
			int min = getMin(p1.birth_date.year, p2.birth_date.year);
			int max = getMax(p1.birth_date.year, p2.birth_date.year);
			if (max - min <= 5) {
				result = TRUE;
			}
		}
	}
	return result;
}

int readFile(FILE * file, People people[], int dim) {
	People temp;
	int i = 0;
	while (fscanf(file, "%[^;];%[^;];%d/%d/%d %c\n", temp.surname, temp.name, &temp.birth_date.day, &temp.birth_date.month,
		&temp.birth_date.year, &temp.gender) != EOF && i < dim) {

		people[i] = temp;
		i++;
	}
	return i;
}

boolean arePeopleEqual(People p1, People p2) {
	boolean result = FALSE;
	if (strcmp(p1.name, p2.name) == 0 && strcmp(p1.surname, p2.surname) == 0
		&& p1.gender == p2.gender && p1.birth_date.day == p2.birth_date.day
		&& p1.birth_date.month == p2.birth_date.month
		&& p1.birth_date.year == p2.birth_date.year) {

		result = TRUE;
	}
	return result;
}

int memberPeople(People haystack[], People needle, int dim) {
	boolean trovato = FALSE;
	int result = -1;
	for (int i = 0; i < dim && !trovato; i++) {
		if (arePeopleEqual(haystack[i], needle)) {
			trovato = TRUE;
			result = i;
		}
	}
	return result;
}

int main() {
	FILE * people_txt = fopen("people.txt", "r");

	People people[PEOPLE_ARRAY_DIM];

	if (people_txt == NULL) {
		perror("Non sono riuscito ad aprire il file 'people.txt");
		exit(1);
	}

	int people_logic_dim = readFile(people_txt, people, PEOPLE_ARRAY_DIM);

	FILE * partners_dat = fopen("partners.dat", "wb");

	if (partners_dat == NULL) {
		perror("Errore durante l'apertura del file 'partners.dat'");
		exit(1);
	}

	People person_input;
	printf("Inserisci i dati di una persona per calcolare la compatibilita' con il database.\n");

	printf("COGNOME: ");
	scanf_s("%[^\n]", person_input.surname, NAME_SURNAME_DIM);
	while ((getchar()) != '\n');
	printf("NOME: ");
	scanf_s("%[^\n]", person_input.name, NAME_SURNAME_DIM);
	while ((getchar()) != '\n');
	printf("SESSO: ");
	scanf("%c", &person_input.gender);
	while ((getchar()) != '\n');
	printf("DATA DI NASCITA: ");
	scanf("%d/%d/%d", &person_input.birth_date.day, &person_input.birth_date.month, &person_input.birth_date.year);
	while ((getchar()) != '\n');
	printf("\n");
	for (int i = 0; i < people_logic_dim; i++) {
		if (areCompatible(person_input, people[i])) {
			printf("RISULTATO N. %d: %s %s, %c, nato il %d/%d/%d\n", i + 1, people[i].surname, people[i].name,
				people[i].gender, people[i].birth_date.day, people[i].birth_date.month, people[i].birth_date.year);
			fwrite(&people[i], sizeof(People), 1, partners_dat);
		}
	}

	system("PAUSE");
	fclose(partners_dat);
	fclose(people_txt);
	return 0;
}