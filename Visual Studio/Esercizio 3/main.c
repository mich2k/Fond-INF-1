double square_dist(double x1, double y1, double x2, double y2) {
	return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

int main(void) {
	double x1 = 3, x2 = 5, y1 = 7, y2 = 9, ris;
	ris=square_dist(x1, y1, x2, y2);
}