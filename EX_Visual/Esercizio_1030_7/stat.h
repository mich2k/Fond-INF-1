#if !defined(STAT_H)
	extern double media(double* x, unsigned int n);
	extern double varianza(double* x, double avg, unsigned int n);
#else
	#error "Include Guard"
#endif