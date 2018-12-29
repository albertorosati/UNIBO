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

int compareTimestamp(Timestamp t1, Timestamp t2)
{
	int result = 0;
	if (t1.h > t2.h) {
		result = 1;
	}
	else if (t1.h < t2.h) {
		result = -1;
	}
	else {
		if (t1.m > t2.m) {
			result = 1;
		}
		else if (t1.m < t2.m) {
			result = -1;
		}
		else {
			if (t1.s > t2.s) {
				result = 1;
			}
			else if (t1.s < t2.s) {
				result = -1;
			}
		}
	}
	return result;
}

	  Timestamp getNullTime()
	  {
		  Timestamp result = { 0,0,0 };
		  return result;
	  }

	  boolean isTimeNull(Timestamp t)
	  {
		  if (t.h == 0 && t.m == 0 && t.s == 0) {
			  return TRUE;
		  }
		  else {
			  return FALSE;
		  }
	  }

	  void printTimestamp(Timestamp t)
	  {
		  if (t.h / 10 == 0) {
			  printf("0");
		  }
		  printf("%d:", t.h);
		  if (t.m / 10 == 0) {
			  printf("0");
		  }
		  printf("%d:", t.m);
		  if (t.s / 10 == 0) {
			  printf("0");
		  }
		  printf("%d", t.s);
	  }
