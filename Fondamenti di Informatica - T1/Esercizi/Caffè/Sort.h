/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef _SORT_H
#define _SORT_H

#include "Common.h"
#include "Array.h"
#include "Element.h"

/*
void naiveSort(element a[], int size);

void bubbleSort(element a[], int size);

void insOrd(element a[], int pos);

void insertSort(element a[], int size);

*/
void merge(Ordine a[], int i1, int i2, int end, Ordine out[]);
//end = size dell'array meno uno
void mergeSort(Ordine a[], int start, int end, Ordine out[]);
/*
void quickSort(element a[], int size);

void quickSortR(element a[], int start, int end);
*/
#endif