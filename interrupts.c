/********************************************************************************
* interrupts.c: Innehåller avbrottsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect): Avbrottsrutin som äger rum vid nedtryckning/uppsläppning
*                    av någon av tryckknapparna. Beroende på vilken tryckknapp
*                    som trycks ned så togglas antingen timer 1 eller timer 2.
*                    Vid uppsläppning av en tryckknapp görs ingenting.
*
*                    Oavsett vad som orsakade avbrottet inaktiveras PCI-avbrott
*                    på I/O-port B i 300 millisekunder via timer 0 för att
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
* ISR (TIMER0_OVF_vect): Avbrottsrutin som äger rum vid overflow av timer 0,
*                        dvs. uppräkning till 256, vilket sker var 0.128:e
*                        millisekund när timern är aktiverad.
*
*                        Timern räknas upp via uppräkning av varje passerat
*                        avbrott. När timern löper ut (när beräknat antal
*                        avbrott för specificerad tid har räknats upp) så
*                        återaktiveras PCI-avbrott på I/O-port B (som har
*                        stängts av i 300 millisekunder för att undvika
*                        multipla avbrott orsakat av kontaktstudsar), följt
*                        av att timern stängs av.
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
* ISR (TIMER1_COMPA_vect): Avbrottsrutin som äger rum vid uppräkning till 256 av
*                          timer 1 i CTC Mode, vilket sker var 0.128:e
*                          millisekund när timern är aktiverad.
*
*                          Timern räknas upp via uppräkning av varje passerat
*                          avbrott. När timern löper ut (när beräknat antal
*                          avbrott för specificerad tid har räknats upp) så
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
* ISR (TIMER2_OVF_vect): Avbrottsrutin som äger rum vid overflow av timer 2,
*                        dvs. uppräkning till 256, vilket sker var 0.128:e
*                        millisekund när timern är aktiverad.
*
*                        Timern räknas upp via uppräkning av varje passerat
*                        avbrott. När timern löper ut (när beräknat antal
*                        avbrott för specificerad tid har räknats upp) så
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
