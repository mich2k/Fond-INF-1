typedef long long int lint;

double potenza(float a, float b) {
	/*if (a == -1) {
		if (b % 2 == 0)
			return 1;
		else
			return -1;
	}*/
	int i = 0;
	double ris = 1;
	for (; i < b; i += 1) {
		ris *= a;
	}
	return ris;
}

double fattoriale(float a) {
	int i = 0;
	double ris = 1;
	for (; a > 1; a -= 1) {
		ris *= a;
	}
	return ris;
}

extern double calcola_seno(double x) {
    int i = 0;
	double seno = 0, nominatore = 0, denominatore = 0, fattore = 0, tmpsen = 0;
	while(1) {
		if (i != 0 && tmpsen == seno)
			return seno;
	    nominatore = potenza(-1, i);
		denominatore = fattoriale(2 * i + 1);
		fattore = potenza(x, (2 * i) + 1);
		tmpsen = seno;
		seno += (nominatore / denominatore) * fattore;
		i += 1;
	}
}