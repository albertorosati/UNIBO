#include "Trova.h"

Azione trovaMin(Azione src[], int dim, float * val)
{
	float min;
	int i_min = 0;
	for (int i = 0; i < dim; i++) {
		if (i == 0) {
			if (src[i].open_value < src[i].close_value) {
				min = src[i].open_value;
			}
			else {
				min = src[i].close_value;
			}
		}

		if (src[i].open_value < min) {
			min = src[i].open_value;
			i_min = i;
		}
		else if (src[i].close_value < min) {
			min = src[i].close_value;
			i_min = i;
		}

	}
	*val = min;
	return src[i_min];
}

Azione trovaMax(Azione src[], int dim, float * val)
{
	float max = 0;
	int i_max = 0;
	for (int i = 0; i < dim; i++) {
		if (src[i].open_value > max) {
			max = src[i].open_value;
			i_max = i;
		}
		else if (src[i].close_value > max) {
			max = src[i].close_value;
			i_max = i;
		}
	}
	*val = max;
	return src[i_max];
}

float media(Azione azioni[], int dim) {
	int c = 0;
	float media = 0;
	for (int i = 0; i < dim; i++) {
		media += azioni[i].close_value;
		media += azioni[i].open_value;
		c += 2;
	}
	return media / c;
}
