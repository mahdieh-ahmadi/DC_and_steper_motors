/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/30/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <set_dutycycle.h>
#include <runsteper.h>
#include <steper.h>

// Declare your global variables here
int side = 0;
int time = 0;
int dataStep = 0b10000000;
int duty = 0;

//// External Interrupt 0 service routine
//interrupt [EXT_INT0] void ext_int0_isr(void)
//{
//// Place your code here
//
//}

//// External Interrupt 1 service routine
//interrupt [EXT_INT1] void ext_int1_isr(void)
//{
//// Place your code here
//
//}

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Place your code here

}

// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
// Place your code here

}

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
// Reinitialize Timer2 value
//TCNT2=0xB2;
// Place your code here
steper(0x16);
runsteper();

}

// Timer2 output compare interrupt service routine
interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
// Place your code here
    

}

void main(void)
{


// Input/Output Ports initialization
// Port A initialization
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
DDRD=(1<<DDD7) | (1<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (1<<DDD1) | (1<<DDD0);
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Phase correct PWM top=0xFF
// OC0 output: Non-Inverted PWM
// Timer Period: 65.28 ms
// Output Pulse(s):
// OC0 Period: 65.28 ms Width: 6.656 ms
TCCR0=(1<<WGM00) | (1<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x00;

//// Timer/Counter 1 initialization
//// Clock source: System Clock
//// Clock value: Timer1 Stopped
//// Mode: Normal top=0xFFFF
//// OC1A output: Disconnected
//// OC1B output: Disconnected
//// Noise Canceler: Off
//// Input Capture on Falling Edge
//// Timer1 Overflow Interrupt: Off
//// Input Capture Interrupt: Off
//// Compare A Match Interrupt: Off
//// Compare B Match Interrupt: Off
//TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
//TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
//TCNT1H=0x00;
//TCNT1L=0x00;
//ICR1H=0x00;
//ICR1L=0x00;
//OCR1AH=0x00;
//OCR1AL=0x00;
//OCR1BH=0x00;
//OCR1BL=0x00;




// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Normal top=0xFF
// OC2 output: Set on compare match
// Timer Period: 9.984 ms
// Output Pulse(s):
// OC2 Period: 9.984 ms
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (1<<COM21) | (1<<COM20) | (0<<CTC2) | (1<<CS22) | (1<<CS21) | (1<<CS20);
TCNT2=0x64;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(1<<OCIE2) | (1<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (1<<OCIE0) | (1<<TOIE0);



//// External Interrupt(s) initialization
//// INT0: On
//// INT0 Mode: Falling Edge
//// INT1: On
//// INT1 Mode: Falling Edge
//// INT2: Off
//GICR|=(1<<INT1) | (1<<INT0) | (0<<INT2);
//MCUCR=(1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
//MCUCSR=(0<<ISC2);
//GIFR=(1<<INTF1) | (1<<INTF0) | (0<<INTF2);
//



// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 8
lcd_init(8);

// Global enable interrupts
#asm("sei")


while (1)
      {
      // Place your code here
       set_dutycycle(); 
      }
}
