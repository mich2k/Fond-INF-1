
// z=1 se è multiplo
// ctrl + f10 = esegui debug fino a cursore

int mult(int x, int y) {
	if (x % y == 0)
		return 1;
	return 0;
}
int main(void) {
	int x=6, y=3, z=0;
	z = mult(x, y);
	return 0;
}