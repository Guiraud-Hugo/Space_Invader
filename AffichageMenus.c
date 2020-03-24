#include <AffichageMenus.h>
#include "serial.h"
#include "vt100.h"
#include "Timer.h"

void Menu() {
	vt100_move(28, 9);
	serial_puts("Bonjour défenseur spatial");
	vt100_move(20, 12);
	serial_puts("Une vague d'alien veut envahir la Terre ");
	vt100_move(16, 13);
	serial_puts("Prends ton vaisseau et aide nous à la défendre");
	vt100_move(24, 16);
	serial_puts("Appuyer sur 'Espace' pour commencer");
}

void Defaite() {
	vt100_move(31, 9);
	serial_puts("Rebonjour incapable");
	vt100_move(20, 12);
	serial_puts("Les aliens ont envahie la planète Terre ");
	vt100_move(26, 13);
	serial_puts("Tu as échoué dans ta tâche");
	vt100_move(24, 16);
	serial_puts("Appuyer sur 'Espace' pour continuer");
}

void Victoire() {
	vt100_move(31, 9);
	serial_puts("Rebonjour Héros");
	vt100_move(20, 12);
	serial_puts("Les aliens ont été repoussé avec succés ");
	vt100_move(24, 13);
	serial_puts("Tu as brillament réussi ta tâche");
	vt100_move(24, 16);
	serial_puts("Appuyer sur 'Espace' pour continuer");
}

void Commandes() {
	vt100_move(20, 9);
	serial_puts("Voilà comment contrôler ton vaisseau");
	vt100_move(6, 12);
	serial_puts(
			"Appuie sur 'q' pour te déplacer vers la droite et 'd' vers la gauche ");
	vt100_move(24, 13);
	serial_puts("Appuie sur 'z' pour tirer");
	vt100_move(18, 14);
	serial_puts("Appuie sur 'Espace' pour mettre pause");
	vt100_move(24, 16);
	serial_puts("Appuyer sur 'Espace' pour continuer");

}

void Pause(unsigned long int t, int carac) {
	if (carac == ' ') {
		Bordures();
		vt100_move(19, 7);
		serial_puts("######      #     #     # ###### ######");
		vt100_move(19, 8);
		serial_puts("#    #     # #    #     # #      #     ");
		vt100_move(19, 9);
		serial_puts("######    #####   #     # ###### ####  ");
		vt100_move(19, 10);
		serial_puts("#        #     #  #     #      # #     ");
		vt100_move(19, 11);
		serial_puts("#       #       # ####### ###### ######");
		Attendre(1, t);
		Bordures();
	}
}

void Attendre(uint8_t clignoting, unsigned long int t) {
	if (clignoting == 0) {
		while (serial_get_last_char() != ' ') {
			vt100_move(24, 16);
			serial_puts("Appuyer sur 'Espace' pour commencer");
			timer(t);
			vt100_move(24, 16);
			serial_puts("                                   ");
			timer(t);
		}
	} else if (clignoting == 1) {
		while (serial_get_last_char() != ' ') {
			vt100_move(24, 16);
			serial_puts("Appuyer sur 'Espace' pour continuer");
			timer(t);
			vt100_move(24, 16);
			serial_puts("                                   ");
			timer(t);
		}
	}
}

void Bordures() {
	uint8_t x = 1;
	uint8_t y = 1;
	vt100_clear_screen();
	for (x = 1; x < 81; x++) {
		vt100_move(x, 1);
		serial_putchar(42);
		vt100_move(x, 24);
		serial_putchar(42);
	}
	for (y = 1; y < 25; y++) {
		vt100_move(1, y);
		serial_putchar(42);
		vt100_move(80, y);
		serial_putchar(42);
	}
}

void FinPerdu(uint8_t YMonVaisseau, uint8_t PosY1GV1, uint8_t PosY1GV2,
		uint8_t PosY1GV3, unsigned long int t,uint8_t MaVie, uint8_t *Fin) {
	if (PosY1GV1 == YMonVaisseau || PosY1GV2 == YMonVaisseau
			|| PosY1GV3 == YMonVaisseau || MaVie ==0) {
		Bordures();
		Defaite();
		Attendre(1, t);
		vt100_clear_screen();
		(*Fin)++;
	}
}

void FinGagne(uint8_t VieVaisseau1, uint8_t VieVaisseau2, uint8_t VieVaisseau3,
		unsigned long int t, uint8_t *Fin) {
	if (VieVaisseau1 == 0 && VieVaisseau2 == 0 && VieVaisseau3 == 0) {
		Bordures();
		Victoire();
		Attendre(1, t);
		vt100_clear_screen();
		(*Fin)++;
	}
}

