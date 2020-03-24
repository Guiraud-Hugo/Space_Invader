#include "Ennemis.h"
#include "serial.h"
#include "vt100.h"
#include "Timer.h"

uint8_t MinX = 2;
uint8_t MaxX = 75;

void Gros_Adversaire(uint8_t **a, uint8_t **b, unsigned long int t) {
	vt100_move(**a, **b);
	serial_puts("     ");
	if (**b % 2 == 0) {
		if (**a < MaxX) {
			(**a)++;
		} else {
			(**b)++;
		}
	} else {
		if (**a > MinX) {
			(**a)--;
		} else {
			(**b)++;
		}
	}
	vt100_move(**a, **b);
	serial_puts("(=0=)");
	timer(t);
}

void GA1(uint8_t *Pos1GV, uint8_t *PosY1GV, uint8_t *VieVaisseau1,
		unsigned long int t) {
	if (*VieVaisseau1 == 1) {
		Gros_Adversaire(&Pos1GV, &PosY1GV, t);
	} else {
		vt100_move(*Pos1GV, *PosY1GV);
		serial_puts("      ");
	}
}

void GA2(uint8_t *Pos2GV, uint8_t *PosY1GV, uint8_t *VieVaisseau2,
		unsigned long int t) {
	if (*VieVaisseau2 == 1) {
		Gros_Adversaire(&Pos2GV, &PosY1GV, t);
	} else {
		vt100_move(*Pos2GV, *PosY1GV);
		serial_puts("      ");
	}
}

void GA3(uint8_t *Pos3GV, uint8_t *PosY1GV, uint8_t *VieVaisseau3,
		unsigned long int t) {
	if (*VieVaisseau3 == 1) {
		Gros_Adversaire(&Pos3GV, &PosY1GV, t);
	} else {
		vt100_move(*Pos3GV, *PosY1GV);
		serial_puts("      ");
	}
}



