/********************************************************************************
* header.h: Inneh�ller globala objekt och deklarationer f�r implementering av 
*           det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include "led.h"
#include "button.h"
#include "timer.h"

/* Deklaration av globala objekt: */
extern struct led l1, l2;       /* Lysdioder. */
extern struct button b1, b2;    /* Tryckknappar. */
extern struct timer t0, t1, t2; /* Timerkretsar. */

/********************************************************************************
* setup: Initierar det inbyggda systemet. Lysdioder initieras p� pin 8 - 9,
*        tryckknappar initieras med aktiverade PCI-avbrott p� pin 12 - 13
*        och samtliga timerkretsar konfigureras, d�r timer 0 s�tts till att
*        l�pa ut efter 300 ms (f�r att tempor�rt inaktivera PCI-avbrott p�
*        I/O-port B efter nedtryckning f�r att undvika multipla avbrott orsakat
*        av kontaktstudsar, medan timer 1 - 2 s�tts till att l�pa ut efter
*        100 ms (f�r blinkning via toggling av lysdioder).
********************************************************************************/
void setup(void);

#endif /* HEADER_H_ */