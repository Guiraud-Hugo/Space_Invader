#include "Tir.h"
#include "vt100.h"
#include "serial.h"
#include "Timer.h"

void Tir(uint8_t *XMissile, uint8_t *YMissile, unsigned long int Timer,
		uint8_t YMonVaisseau, int carac) {
	vt100_move(*XMissile, *YMissile);
	serial_puts("|");
	timer(Timer);
	vt100_move(*XMissile, *YMissile);
	serial_puts(" ");
	timer(Timer);
	(*YMissile)--;
	if (*YMissile == 1) {
		*YMissile = 21;
	}
}

void HitBoxV1(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos1GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau1) {
	if ((*XMissile <= (*Pos1GV + 4)) && (*XMissile >= *Pos1GV)
			&& (*YMissile == *PosY1GV)) {
		*VieVaisseau1 = 0;
		*YMissile = 21;

	}
}
void HitBoxV2(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos2GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau2) {
	if ((*XMissile <= (*Pos2GV + 4)) && (*XMissile >= *Pos2GV)
			&& (*YMissile == *PosY1GV)) {
		*VieVaisseau2 = 0;
		*YMissile = 21;
	}
}

void HitBoxV3(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos3GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau3) {
	if ((*XMissile <= (*Pos3GV + 4)) && (*XMissile >= *Pos3GV)
			&& (*YMissile == *PosY1GV)) {
		*VieVaisseau3 = 0;
		*YMissile = 21;
	}
}

int TirEnnemis(uint8_t i, uint8_t *XMissileEnnemis, uint8_t *YMissileEnnemis,
		uint8_t XMonVaisseau, uint8_t YMonVaisseau, uint8_t PosYGV,
		uint8_t EnnemisTir, uint8_t *MaVie, unsigned long int Timer) {
	vt100_move(*XMissileEnnemis, *YMissileEnnemis);
	serial_puts("|");
	timer(Timer);
	vt100_move(*XMissileEnnemis, *YMissileEnnemis);
	serial_puts(" ");
	timer(Timer);
	(*YMissileEnnemis)++;
	if (*YMissileEnnemis == YMonVaisseau+1) {
		*YMissileEnnemis = PosYGV;
		EnnemisTir = 0;
	}
	if (*XMissileEnnemis >= XMonVaisseau && *XMissileEnnemis <= (XMonVaisseau + 5)
			&& *YMissileEnnemis == YMonVaisseau) {
		*MaVie = 0;
	}
	return EnnemisTir;
}

