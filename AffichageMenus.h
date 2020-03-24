#include "serial.h"
#include "vt100.h"

#ifndef AFFICHAGEMENUS_H_
#define AFFICHAGEMENUS_H_

void Menu();
void Defaite();
void Attendre(uint8_t clignoting, unsigned long int t);
void Bordures();
void Commandes();
void Pause(unsigned long int t, int carac);
void FinPerdu(uint8_t YMonVaisseau, uint8_t PosY1GV1, uint8_t PosY1GV2,
		uint8_t PosY1GV3, unsigned long int t,uint8_t MaVie, uint8_t *Perds);
void Victoire();
void FinGagne(uint8_t VieVaisseau1, uint8_t VieVaisseau2, uint8_t VieVaisseau3,
		unsigned long int t, uint8_t *Fin);

#endif /* AFFICHAGEMENUS_H_ */
