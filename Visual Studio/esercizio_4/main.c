int primo(unsigned int val) {
	int count = 0, div =0;
	for (count = 1; count < val; count += 1) {
		if (val % count == 0)
			div += 1;
		if (div > 2)
			return 0;
	}
		return 1;
}

int main(void){
	int num = 10000;
	int _primo = primo(num);
	return 0;
}