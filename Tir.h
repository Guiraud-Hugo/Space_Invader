#include "vt100.h"
#include "serial.h"

#ifndef TIR_H_
#define TIR_H_

void Tir(uint8_t *XMissile, uint8_t *YMissile, unsigned long int Timer,
		uint8_t YMonVaisseau, int carac);
void HitBoxV1(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos1GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau1);
void HitBoxV2(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos2GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau2);
void HitBoxV3(uint8_t *XMissile, uint8_t *YMissile, uint8_t *Pos3GV,
		uint8_t *PosY1GV, uint8_t *VieVaisseau3);
int TirEnnemis(uint8_t i, uint8_t *XMissileEnnemis, uint8_t *YMissileEnnemis,
		uint8_t XMonVaisseau, uint8_t YMonVaisseau, uint8_t PosYGV,
		uint8_t EnnemisTir, uint8_t *MaVie, unsigned long int Timer);
#endif /* TIR_H_ */
