#include <stdlib.h> 
#include <stdbool.h>

typedef unsigned int uint;

int potenza(uint a, uint i) {
	uint _pot = 1;
	for (uint n=0; n < i; n += 1) {
		_pot *= a;
	}
	return _pot;
}

bool is_terna_pitagorica(uint a, uint b, uint c) {
	uint pot_a = potenza(a, 2);
	uint pot_b = potenza(b, 2);
	uint pot_c = potenza(c, 2);
	
	if ((pot_a == (pot_b + pot_c)) || (pot_b == (pot_a + pot_c)) || (pot_c == (pot_a + pot_b)))
		return true;
	return false;
}