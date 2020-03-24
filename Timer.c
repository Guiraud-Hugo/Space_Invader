#include "Timer.h"

void timer(unsigned long int t) {

	int ii = 0;
	unsigned long int max = t * 100000;
	do {
		ii++;
	} while (ii <= max);
}

