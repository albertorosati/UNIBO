/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#ifndef SORT_H
#define SORT_H

#include "Libri.h"
#include <stdio.h>

typedef struct Ordine Ordine;

typedef Ordine sort_element;


//void naiveSort(sort_element a[], int size);


void bubbleSort(sort_element a[], int size);


//void insOrd(sort_element a[], int pos);
//void insertSort(sort_element a[], int size);


//void merge(sort_element a[], int i1, int i2, int end, sort_element out[]);
//end = size dell'array meno uno
//void mergeSort(sort_element a[], int start, int end, sort_element out[]);


//void quickSort(sort_element a[], int size);
//void quickSortR(sort_element a[], int start, int end);

#endif