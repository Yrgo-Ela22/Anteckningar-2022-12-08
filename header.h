/********************************************************************************
* header.h: Innehåller globala objekt och deklarationer för implementering av 
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
* setup: Initierar det inbyggda systemet. Lysdioder initieras på pin 8 - 9,
*        tryckknappar initieras med aktiverade PCI-avbrott på pin 12 - 13
*        och samtliga timerkretsar konfigureras, där timer 0 sätts till att
*        löpa ut efter 300 ms (för att temporärt inaktivera PCI-avbrott på
*        I/O-port B efter nedtryckning för att undvika multipla avbrott orsakat
*        av kontaktstudsar, medan timer 1 - 2 sätts till att löpa ut efter
*        100 ms (för blinkning via toggling av lysdioder).
********************************************************************************/
void setup(void);

#endif /* HEADER_H_ */