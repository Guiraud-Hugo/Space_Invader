#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "serial.h"
#include "vt100.h"
#include "Tir.h"
#include "Timer.h"
#include "AffichageMenus.h"
#include "Ennemis.h"
#include "MonVaisseau.h"

int i = 0;
int carac = -1;

uint8_t XMissile = 0;
uint8_t YMissile = 21;

uint8_t XMonVaisseau = 38;
uint8_t YMonVaisseau = 21;

uint8_t Timer = 10;
uint8_t TimerTir = 5;
uint8_t Timerclignoting = 30;

uint8_t VieVaisseau1 = 1;
uint8_t VieVaisseau2 = 1;
uint8_t VieVaisseau3 = 1;

uint8_t Pos1GV = 6;
uint8_t Pos2GV = 36;
uint8_t Pos3GV = 66;
uint8_t PosYGV1 = 4;
uint8_t PosYGV2 = 4;
uint8_t PosYGV3 = 4;

uint8_t XMissileEnnemis1;
uint8_t XMissileEnnemis2;
uint8_t XMissileEnnemis3;
uint8_t YMissileEnnemis1;
uint8_t YMissileEnnemis2;
uint8_t YMissileEnnemis3;
uint8_t Ennemis1Tir = 0;
uint8_t Ennemis2Tir = 0;
uint8_t Ennemis3Tir = 0;

uint8_t MaVie =1;
uint8_t Fin = 0;

int main(void) {
	while (1) {
		serial_init(115200);
		Bordures();
		Menu();
		Attendre(0, Timerclignoting);
		Bordures();
		Commandes();
		Attendre(1, Timerclignoting);
		Bordures();
		Pos1GV = 6;
		Pos2GV = 36;
		Pos3GV = 66;
		PosYGV1 = 4;
		PosYGV2 = 4;
		PosYGV3 = 4;
		VieVaisseau1 = 1;
		VieVaisseau2 = 1;
		VieVaisseau3 = 1;
		XMonVaisseau = 38;
		Fin = 0;
		STM_EVAL_LEDInit(LED3);
		STM_EVAL_LEDInit(LED4);
		STM_EVAL_LEDInit(LED5);
		STM_EVAL_LEDInit(LED6);

		/* Turn on LEDs */
		STM_EVAL_LEDOn(LED3);
		STM_EVAL_LEDOn(LED4);
		STM_EVAL_LEDOn(LED5);
		STM_EVAL_LEDOn(LED6);

		/* Infinite loop */

		while (Fin == 0) {
			i++;
			int carac = serial_get_last_char();
			Mon_Vaisseau(&XMonVaisseau, YMonVaisseau, carac);
			if (YMissile != YMonVaisseau) {
				Tir(&XMissile, &YMissile, TimerTir, YMonVaisseau, carac);
			}
			if (carac == 'z' && YMissile == YMonVaisseau) {
				XMissile = XMonVaisseau + 2;
				Tir(&XMissile, &YMissile, TimerTir, YMonVaisseau, carac);
			}

			GA1(&Pos1GV, &PosYGV1, &VieVaisseau1, Timer);
			HitBoxV1(&XMissile, &YMissile, &Pos1GV, &PosYGV1, &VieVaisseau1);
			GA2(&Pos2GV, &PosYGV2, &VieVaisseau2, Timer);
			HitBoxV2(&XMissile, &YMissile, &Pos2GV, &PosYGV2, &VieVaisseau2);
			GA3(&Pos3GV, &PosYGV3, &VieVaisseau3, Timer);
			HitBoxV3(&XMissile, &YMissile, &Pos3GV, &PosYGV3, &VieVaisseau3);
			Pause(Timerclignoting, carac);
			FinPerdu(YMonVaisseau, PosYGV1, PosYGV2, PosYGV3, Timerclignoting,MaVie,
					&Fin);
			FinGagne(VieVaisseau1, VieVaisseau2, VieVaisseau3, Timerclignoting,
					&Fin);

			//Gestion du tir du premier ennemis
			if (YMissileEnnemis1 != (YMonVaisseau+1) && Ennemis1Tir == 1) {
				Ennemis1Tir = TirEnnemis(i, &XMissileEnnemis1, &YMissileEnnemis1,XMonVaisseau,
						YMonVaisseau, PosYGV1, Ennemis1Tir,&MaVie, Timer);
			}
			if ((i % 9) == 0 && Ennemis1Tir == 0) {
				XMissileEnnemis1 = Pos1GV;
				YMissileEnnemis1 = PosYGV1;
				Ennemis1Tir++;
				Ennemis1Tir = TirEnnemis(i, &XMissileEnnemis1, &YMissileEnnemis1,XMonVaisseau,
						YMonVaisseau, PosYGV1, Ennemis1Tir,&MaVie, Timer);
			}

			//Gestion du tir du deuxième ennemis
			if (YMissileEnnemis2 != (YMonVaisseau+1) && Ennemis2Tir == 1) {
				Ennemis2Tir = TirEnnemis(i, &XMissileEnnemis2, &YMissileEnnemis2,XMonVaisseau,
						YMonVaisseau, PosYGV2, Ennemis2Tir,&MaVie, Timer);
			}
			if ((i % 12) == 0 && Ennemis2Tir == 0) {
				XMissileEnnemis2 = Pos2GV;
				YMissileEnnemis2 = PosYGV1;
				Ennemis2Tir++;
				Ennemis2Tir = TirEnnemis(i, &XMissileEnnemis2, &YMissileEnnemis2,XMonVaisseau,
						YMonVaisseau, PosYGV2, Ennemis2Tir,&MaVie, Timer);
			}

			if (YMissileEnnemis3 != (YMonVaisseau+1) && Ennemis3Tir == 1) {
				Ennemis3Tir = TirEnnemis(i, &XMissileEnnemis3, &YMissileEnnemis3,XMonVaisseau,
						YMonVaisseau, PosYGV3, Ennemis3Tir,&MaVie, Timer);
			}
			if ((i % 10) == 0 && Ennemis3Tir == 0) {
				XMissileEnnemis3 = Pos3GV;
				YMissileEnnemis3 = PosYGV3;
				Ennemis3Tir++;
				Ennemis3Tir = TirEnnemis(i, &XMissileEnnemis3, &YMissileEnnemis3,XMonVaisseau,
						YMonVaisseau, PosYGV3, Ennemis3Tir,&MaVie, Timer);
			}
		}

	}
}
/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size) {
	/* TODO, implement your code here */
	return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void) {
	/* TODO, implement your code here */
	return -1;
}
