/*
 * Profsouysy_motor.c
 *
 * Created: 4/5/2022 2:47:37 PM
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void initPorts() {
  DDRD = 0b00000011; PORTD |= (1<<3) | (1<<4) | (1<<5) | (1<<6);
  DDRC &= ~(1 << 7); 
}

int main(void)
{
  initPorts();

  while (1)
  {
	  if(PINC & (1 << 7)) {
			if (!(PIND & (1 << 5))) {
				PORTD |= (1 << 0);
				PORTD |= (1 << 1);
			}
			else {
				PORTD |=  (1 << 0);
				PORTD &= ~(1 << 1);
			}
	  }
	  else {
		  if (!(PIND & (1 << 6))) {
				PORTD |= (1 << 0);
				PORTD |= (1 << 1);
			}
			else {
				PORTD &= ~(1 << 0);
				PORTD |=  (1 << 1);	
			}
	  }
  }
}
