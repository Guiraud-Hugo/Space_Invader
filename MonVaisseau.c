#include "MonVaisseau.h"
#include "serial.h"
#include "vt100.h"

static uint8_t MinX = 2;
static uint8_t MaxX = 75;

void Mon_Vaisseau_Init(uint8_t YMonVaisseau) {
	vt100_move(38, YMonVaisseau);
	serial_puts("_/0\\_");

}

void Mon_Vaisseau(uint8_t *XMonVaisseau, uint8_t YMonVaisseau,int carac) {
	vt100_move(*XMonVaisseau, YMonVaisseau);
	serial_puts("_/0\\_");
	if (carac == 'd' && *XMonVaisseau < MaxX) {
		vt100_move(*XMonVaisseau, YMonVaisseau);
		serial_puts("     ");
		*XMonVaisseau += 1;
		vt100_move(*XMonVaisseau, YMonVaisseau);
		serial_puts("_/0\\_");
	}

	if (carac == 'q' && *XMonVaisseau > MinX) {
		vt100_move(*XMonVaisseau, YMonVaisseau);
		serial_puts("     ");
		*XMonVaisseau -= 1;
		vt100_move(*XMonVaisseau, YMonVaisseau);
		serial_puts("_/0\\_");
	}

}
