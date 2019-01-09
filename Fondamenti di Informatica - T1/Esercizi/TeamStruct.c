#include <stdio.h>

#define DIM 3
typedef struct {
	char name[20];
	int code;
	int goal_scored;
	int goal_received;
} Team;

void readTeam(Team team[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Inserisci il nome della squadra: ");
		scanf_s("%s", team[i].name, 20);
		printf("\nInserisci il codice della squadra: ");
		scanf_s("%d", &team[i].code);
		printf("\nInserisci il numero di goal segnati: ");
		scanf_s("%d", &team[i].goal_scored);
		printf("\nInserisci il numero di goal ricevuti: ");
		scanf_s("%d", &team[i].goal_received);
	}
}

int main() {

	Team team[DIM];

	readTeam(team, DIM);

	int n = 1;

	while (n != 0) {
		printf("Inserisci il codice di una squadra per visualizzarne le informazioni: ");
		scanf_s("%d", &n);
		if (n != 0) {
			printf("\n--- SQUADRA N. %d ---\n", n);
			printf("NOME:          %s\n", team[n].name);
			printf("GOAL SEGNATI:  %d\n", team[n].goal_scored);
			printf("GOAL RICEVUTI: %d\n", team[n].goal_received);
		}
	}
	
	

	return 0;
}