#include <mega16.h>
#include <delay.h>

extern int side;
extern int time; 
extern int dataStep; 
extern int duty;

void runsteper (void){

            
   PORTB = dataStep ;  
   
   
   time++;
   if(time == 300){
     delay_ms(2000);
     time = 0;
     if(side == 0) side = 1;
     else side = 0;
   } 
   
   if(side == 0 ){     // right
       dataStep = 0b10000000 >> duty;  
       PORTD.0 = 0;
       PORTD.1 = 1;
   }else if (side == 1){   // left
     dataStep = 1 << 4+duty;    
     PORTD.0 = 1;
     PORTD.1 = 0;
   }  
   
    duty = duty + 1;
    if(duty == 4){
          duty = 0;
    } 
}