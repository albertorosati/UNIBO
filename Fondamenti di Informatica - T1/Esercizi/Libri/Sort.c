 /*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Sort.h"

/*
--------------------
---- NAIVE SORT ----
--------------------
*/

/*
void naiveSort(sort_element a[], int size) {
	int p;
	while (size > 1) {
		p = getMaxIndex(a, size);
		if (p < size - 1) swap(&a[p], &a[size - 1]);
		size--;
	}
}
*/

/*
--------------------
---- BUBBLE SORT ---
--------------------
*/

void swap(Ordine * o1, Ordine * o2) {
	Ordine tmp = *o1;
	*o1 = *o2;
	*o2 = tmp;
}


void bubbleSort(sort_element a[], int size) {
	int i;
	boolean sorted = FALSE;
	while (size > 1 && !sorted) {
		sorted = TRUE;
		for (i = 0; i < size - 1; i++) {
			if (compareOrdini(a[i], a[i + 1]) == 1) {
				swap(&a[i], &a[i + 1]);
				sorted = FALSE;
			}
		}
		size--;
	}
}



/*
--------------------
---- INSERT SORT ---
--------------------
*/


/*
void insOrd(sort_element a[], int pos) {
	int i = pos - 1, x = a[pos];
	while (i >= 0 && x < a[i]) {
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = x;
}
void insertSort(element a[], int size) {
	int i;
	for (i = 1; i < size; i++)
		insOrd(a, i);
}
*/


/*
--------------------
---- MERGE SORT ----
--------------------
*/


/*
void merge(sort_element a[], int i1, int i2, int end, sort_element out[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= end) {
		if (compareProdotto(a[i], a[j]) == -1) {
			out[k] = a[i];
			i++;
		}
		else {
			out[k] = a[j];
			j++;
		}
		k++;
	}
	while (i <= i2 - 1) {
		out[k] = a[i];
		i++; k++;
	}
	while (j <= end) {
		out[k] = a[j];
		j++; k++;
	}
	for (i = i1; i <= end; i++) a[i] = out[i];
}
*/
//end = size dell'array meno uno
/*
void mergeSort(sort_element a[], int start, int end, sort_element out[]) {
	int mid;
	if (start < end) {
		mid = (end + start) / 2;
		mergeSort(a, start, mid, out);
		mergeSort(a, mid + 1, end, out);
		merge(a, start, mid + 1, end, out);
	}
}
*/


/*
--------------------
---- QUICK SORT ----
--------------------
*/


/*
void quickSort(element a[], int size)
{
	quickSortR(a, 0, size - 1);
}

void quickSortR(element a[], int start, int end)
{
	int i, j, iPivot, pivot;
	if (start < end)
	{
		i = start;
		j = end;
		iPivot = end;
		pivot = a[iPivot];
		do
		{
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		if (start < iPivot - 1)
			quickSortR(a, start, iPivot - 1);
		if (iPivot + 1 < end)
			quickSortR(a, iPivot + 1, end);
	}
}*/