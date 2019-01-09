#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

double f(double x) {
	return x * x;
}

double trapezi(double a, double b, double N) {
	double prec = (b - a) / N;
	double it_n = prec;
	double result = 0;
	for (int i = 0; i < N; i++) {
		result += (f(a + i * prec) + f(a + (i + 1)*prec)) * (prec / 2);
	}
	return result;
}

int main(void) {

	double a, b, N;

	printf("Inserisci due numeri separati da uno spazio: ");
	scanf("%lf %lf", &a, &b);

	printf("Inserisci un intervallo N: ");
	scanf("%lf", &N);

	printf("Integrale: %lf", trapezi(a, b, N));

 	return 0;
}