#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#define NO_SOLUTION -1
#define SAME_RESULT 0
#define SUCCESS 1

int secondoGrado(double a, double b, double c, double *x1, double *x2) {
	double delta = (b*b) - 4 * a * c;
	if (delta < 0) {
		return NO_SOLUTION;
	}
	else {
		*x1 = (-b + sqrt(delta)) / 2 * a;
		*x2 = (-b - sqrt(delta)) / 2 * a;
		if (delta == 0) {
			return SAME_RESULT;
		}
		else {
			return SUCCESS;
		}
	}
}

int main(void) {
	double a, b, c, x1, x2;
	printf("Inserisci i coefficienti 'a b c' dell'equazione di secondo grado: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	int code = secondoGrado(a, b, c, &x1, &x2);

	if (code == NO_SOLUTION) {
		printf("L'equazione non ha soluzioni reali");
	}
	else if (code == SAME_RESULT) {
		printf("x1=x2=%lf", x1);
	}
	else if (code == SUCCESS) {
		printf("x1 = %lf\nx2 = %lf", x1, x2);
	}
	else {
		printf("ERRORE MIAO");
	}

	return 0;
}