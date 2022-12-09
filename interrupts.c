/********************************************************************************
* interrupts.c: Inneh�ller avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som �ger rum vid nedtryckning/uppsl�ppning
*                    av n�gon av tryckknapparna. Beroende p� vilken tryckknapp
*                    som trycks ned s� togglas antingen timer 1 eller timer 2.
*                    Vid uppsl�ppning av en tryckknapp g�rs ingenting.
*
*                    Oavsett vad som orsakade avbrottet inaktiveras PCI-avbrott
*                    p� I/O-port B i 300 millisekunder via timer 0 f�r att
*                    undvika multipla avbrott orsakade av kontaktstudsar.
********************************************************************************/
ISR (PCINT0_vect)
{
   disable_pin_change_interrupt(IO_PORTB);
   timer_enable_interrupt(&t0);

   if (button_is_pressed(&b1))
   {
      timer_toggle_interrupt(&t1);
      if (!timer_interrupt_enabled(&t1))
      {
         led_off(&l1);
      }
   }
   else if (button_is_pressed(&b2))
   {
      timer_toggle_interrupt(&t2);
      if (!timer_interrupt_enabled(&t2))
      {
         led_off(&l2);
      }
   }

   return;
}

/********************************************************************************
* ISR (TIMER0_OVF_vect): Avbrottsrutin som �ger rum vid overflow av timer 0,
*                        dvs. uppr�kning till 256, vilket sker var 0.128:e
*                        millisekund n�r timern �r aktiverad.
*
*                        Timern r�knas upp via uppr�kning av varje passerat
*                        avbrott. N�r timern l�per ut (n�r ber�knat antal
*                        avbrott f�r specificerad tid har r�knats upp) s�
*                        �teraktiveras PCI-avbrott p� I/O-port B (som har
*                        st�ngts av i 300 millisekunder f�r att undvika
*                        multipla avbrott orsakat av kontaktstudsar), f�ljt
*                        av att timern st�ngs av.
********************************************************************************/
ISR (TIMER0_OVF_vect)
{
   timer_count(&t0);

   if (timer_elapsed(&t0))
   {
      enable_pin_change_interrupt(IO_PORTB);
      timer_disable_interrupt(&t0);
   }

   return;
}

/********************************************************************************
* ISR (TIMER1_COMPA_vect): Avbrottsrutin som �ger rum vid uppr�kning till 256 av
*                          timer 1 i CTC Mode, vilket sker var 0.128:e
*                          millisekund n�r timern �r aktiverad.
*
*                          Timern r�knas upp via uppr�kning av varje passerat
*                          avbrott. N�r timern l�per ut (n�r ber�knat antal
*                          avbrott f�r specificerad tid har r�knats upp) s�
*                          togglas lysdiod 1.
********************************************************************************/
ISR (TIMER1_COMPA_vect)
{
   timer_count(&t1);

   if (timer_elapsed(&t1))
   {
      led_toggle(&l1);
   }

   return;
}

/********************************************************************************
* ISR (TIMER2_OVF_vect): Avbrottsrutin som �ger rum vid overflow av timer 2,
*                        dvs. uppr�kning till 256, vilket sker var 0.128:e
*                        millisekund n�r timern �r aktiverad.
*
*                        Timern r�knas upp via uppr�kning av varje passerat
*                        avbrott. N�r timern l�per ut (n�r ber�knat antal
*                        avbrott f�r specificerad tid har r�knats upp) s�
*                        togglas lysdiod 2.
********************************************************************************/
ISR (TIMER2_OVF_vect)
{
   timer_count(&t2);

   if (timer_elapsed(&t2))
   {
      led_toggle(&l2);
   }

   return;
}
