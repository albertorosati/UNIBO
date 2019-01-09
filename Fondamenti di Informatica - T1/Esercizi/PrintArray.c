#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define DIM 10


void printArray(int a[], int size, int i) {
	if (i == size) {
		printf("  %d  ", a[i]);
	}
	else {
		printf("  %d  ", a[i]);
		i++;
		printArray(a, size, i);
	}
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7 };
	printArray(a, 6, 0);
	return 0;
}