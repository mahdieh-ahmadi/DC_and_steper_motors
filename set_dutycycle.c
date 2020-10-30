
#include <mega16.h>

void set_dutycycle (void){

    int pina;
    float duty;
    int y;

    pina = PINA;
    duty = (90*pina/255)+5;
    y = (203/8)*duty-(203/8)+26;
    OCR0 = y;

}