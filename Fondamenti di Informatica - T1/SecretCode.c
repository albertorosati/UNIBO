#include <stdio.h>
#include <string.h>


int main() {
	char msg[50] = "ma che bel castello";
	char secret[20] = "cestello";

	int secret_legth = strlen(secret);
	int length_found = 0;
	int i = 0;
	while (msg[i] != '\0') {
		if (msg[i] == secret[length_found]) {
			length_found++;
		}
		i++;
	}

	if (length_found == secret_legth) {
		int j = 0;
		for (int i = 0; i < strlen(msg); i++) {
			if (msg[i] == secret[j]) {
				msg[i] -= 32;
				j++;
			}
		}
		printf("%s\nMSG:%s", msg, secret);
	}
	else {
		printf("MESSAGGIO NON TROVATO");
	}

	return 0;
}