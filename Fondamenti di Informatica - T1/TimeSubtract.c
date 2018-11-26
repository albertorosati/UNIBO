#include <stdio.h>

typedef struct {
	int h = 0;
	int m = 0;
	int s = 0;
} Time;

Time subtractTime(Time t1, Time t2) {
	int t1_plain = (t1.h * 60 * 60) + (t1.m * 60) + t1.s;
	int t2_plain = (t2.h * 60 * 60) + (t2.m * 60) + t2.s;
	Time result;
	result.s = t1_plain - t2_plain;
	
	while (result.s >= 60) {
		result.s -= 60;
		result.m++;
		while (result.m >= 60) {
			result.m -= 60;
			result.h++;;
		}
	}

	return result;
}

int main() {

	Time t1 = { 2, 15, 20 };
	Time t2 = { 0, 15, 20 };

	Time t3 = subtractTime(t1, t2);

	return 0;
}