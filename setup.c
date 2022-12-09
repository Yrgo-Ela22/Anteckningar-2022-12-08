/********************************************************************************
* setup.c: Inneh�ller funktionalitet f�r initiering av det inbyggda systemet.
********************************************************************************/
#include "header.h"

/* Definition av globala objekt: */
struct led l1, l2;       /* Lysdioder. */
struct button b1, b2;    /* Tryckknappar. */
struct timer t0, t1, t2; /* Timerkretsar. */

/********************************************************************************
* setup: Initierar det inbyggda systemet. Lysdioder initieras p� pin 8 - 9,
*        tryckknappar initieras med aktiverade PCI-avbrott p� pin 12 - 13
*        och samtliga timerkretsar konfigureras, d�r timer 0 s�tts till att
*        l�pa ut efter 300 ms (f�r att tempor�rt inaktivera PCI-avbrott p�
*        I/O-port B efter nedtryckning f�r att undvika multipla avbrott orsakat
*        av kontaktstudsar, medan timer 1 - 2 s�tts till att l�pa ut efter
*        100 ms (f�r blinkning via toggling av lysdioder).
********************************************************************************/
void setup(void)
{
   led_init(&l1, 8);
   led_init(&l2, 9);

   button_init(&b1, 12);
   button_init(&b2, 13);

   button_enable_interrupt(&b1);
   button_enable_interrupt(&b2);

   timer_init(&t0, TIMER_SEL_0, 300);
   timer_init(&t1, TIMER_SEL_1, 100);
   timer_init(&t2, TIMER_SEL_2, 100);

   return;
}