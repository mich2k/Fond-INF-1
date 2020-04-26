double pot(double x, int n){
	double ris = 1;
	if (n == 0)
		return 1;
	for (int i =0; i < n; i+=1) {
		ris *= x;
	}
	return ris;
 }
double fact(double x)
{
	double fatt = x;
	while (x > 1) {
		fatt *= x-1;
		x -= 1;
	}
	return fatt;
}
double exp(double x){
	double ris = 0;
	for (int i = 0; i < 5; i += 1) {
		ris += ( pot(x, i) / fact(i) );
	}
	return ris;
}
int main(void) {
	int ripetizioni = 1000;
	double ris=exp(ripetizioni);
}