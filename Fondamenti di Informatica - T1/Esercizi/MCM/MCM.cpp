int MCD(int m, int n) {
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	return m;
}

int mcm(int a, int b) {
	return (a*b) / MCD(a, b);
}