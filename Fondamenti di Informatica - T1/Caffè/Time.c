/*
NOME: Alberto Giuseppe
COGNOME: Rosati
MATRICOLA: s0000873315
*/
#include "Time.h"

int compareDates(Date d1, Date d2)
{
	int result = 0;
	if (d1.year > d2.year) {
		result = 1;
	}
	else if (d1.year < d2.year) {
		result = -1;
	}
	else {
		if (d1.month > d2.month) {
			result = 1;
		}
		else if (d1.month < d2.month) {
			result = -1;
		}
		else {
			if (d1.day > d2.day) {
				result = 1;
			}
			else if (d1.day < d2.day) {
				result = -1;
			}
		}
	}
	return result;
}
