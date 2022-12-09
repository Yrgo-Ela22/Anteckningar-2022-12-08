/********************************************************************************
* main.c: Demonstration av datastruktur f�r implementering av timerkretsar
*         f�r inbyggda system. Tv� lysdioder anslutna till pin 8 - 9 (PORTB0 -
*         PORTB1) togglas mellan att vara avst�ngda samt blinka via toggling
*         med timerkretsar timer1 samt timer2, d�r timer1 togglar lysdioden
*         ansluten till pin 8 (PORTB0) och timer2 togglar lysdioden ansluten
*         till pin 9 (PORTB1). N�r timergenererat avbrott �r aktiverat p� en 
*         given timer blinkar motsvarande lysdiod, annars h�lls denna sl�ckt. 
*
*         F�r att toggla aktivering av timergenererade avbrott p� timerkretsarna 
*         anv�nds tv� tryckknappar anslutna till pin 12 - 13 (PORTB4 - PORTB4), 
*         som PCI-avbrott har aktiverats p�. Vid nedtryckning av tryckknappen 
*         ansluten till pin 12 (PORTB4) togglas timergenererat avbrott p� timer1, 
*         medan nedtryckning av tryckknappen ansluten till pin 13 (PORTB5) medf�r
*         toggling av timergenererat avbrott p� timer2.
*
*         F�r att undvika multipla avbrott p� grund av kontaktstudsar vid 
*         nedtryckning av tryckknapparna inaktiveras PCI-avbrott p� I/O-port B
*         i 300 ms efter att avbrott sker. R�kningen genomf�rs av timerkrets
*         timer 0, som timergenererat avbrott aktiveras d� aktiveras p�.
*         Efter 300 ms har passerat �terst�lls PCI-avbrott p� I/O-port B
*         och timergenererat avbrott p� timer 0 inaktiveras inf�r n�sta 
*         nedtryckning av tryckknapparna.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar systemet vid start, vilket innefattar initiering av lysdioder,
*       tryckknappar och timerkretsar. Programmet �r i �vrigt avbrottsgenererat.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
      
   }

   return 0;
}

