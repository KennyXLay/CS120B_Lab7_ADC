/*	Author: lab
 *  Partner(s) Name: Kenny
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



unsigned short my_short = 0xABCD;
unsigned char my_char1 = 0x00;
unsigned char my_char2 = 0x00;

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
    /* Insert your solution below */
    while (1) {
	my_short = ADC;
	my_char1 = (my_short >> 8);
	PORTD = my_char1;
	my_char2 = (my_short);
	PORTB = my_char2;
    }
    return 1;
}
