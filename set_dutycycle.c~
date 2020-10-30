
#include <mega16.h>

void set_dutycycle (void){

    int pina;
    float duty;

    pina = PINA;
    duty = (90*pina/255)+5;
    OCR0 = duty;

}