#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define DIM 10

int arrayContains(int a[], int size, int needle) {
	int i = 0;
	int end = 0;
	int result = -1;
	while (i < size && !end) {
		if (a[i] == needle) {
			end = 1;
			result = i;
		}
		i++;
	}
	return result;
}

int readArray(int a[], int size, int code) {
	int i = 0, n = 1;
	while (i < size && n != 0) {
		printf("Inserisci un numero per l'array A%d: ", code);
		scanf("%d", &n);
		if (n != 0) {
			a[i] = n;
			i++;
		}
	}
	return i;
}

int array_interval(int v[], int *size, int a, int b) {
	int t = *size;
	*size= arrayContains(v, t, b) - arrayContains(v, t, a);
	return  arrayContains(v, t, a);
}

int main() {
	int v[DIM];
	int a, b;
	int logicDim_v = readArray(v, DIM, 1);


	printf("Inserisci due estremi separati da uno spazio: ");
	scanf("%d %d", &a, &b);

	

	int first_index = array_interval(v, &logicDim_v, a, b);
	for (int i = first_index; i <= logicDim_v + first_index; i++) {
		printf(" %d ", v[i]);
	}	


	return 0;
}