#include "serial.h"
#include "vt100.h"

#ifndef ENNEMIS_H_
#define ENNEMIS_H_

void Gros_Adversaire(uint8_t **a, uint8_t **b, unsigned long int t);
void GA1(uint8_t *Pos1GV, uint8_t *PosY1GV, uint8_t *VieVaisseau,
		unsigned long int t);
void GA2(uint8_t *Pos2GV, uint8_t *PosY1GV, uint8_t *VieVaisseau2,
		unsigned long int t);
void GA3(uint8_t *Pos3GV, uint8_t *PosY1GV, uint8_t *VieVaisseau3,
		unsigned long int t);
void GA4(uint8_t *Pos1GV, uint8_t *PosY2GV, uint8_t *VieVaisseau4,
		unsigned long int t);
void GA5(uint8_t *Pos2GV, uint8_t *PosY2GV, uint8_t *VieVaisseau5,
		unsigned long int t);
void GA6(uint8_t *Pos3GV, uint8_t *PosY2GV, uint8_t *VieVaisseau6,
		unsigned long int t);
void Vaisseau_Adverse();

#endif /* ENNEMIS_H_ */
