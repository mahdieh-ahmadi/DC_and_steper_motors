
#include <mega16.h>
#include <delay.h>

 void steper (int speed){

   //OCR2 = speed;  
   TCNT2 = speed;
   
 }