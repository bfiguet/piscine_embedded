#include <avr/io.h>

//PB0 -> Pin Data 0 for port B / LED (D1)
//PD2 -> Pin Data 2 for port D / Button (SW1)
//DDRX -> Data Direction Register for port X / 0 -> input / 1 -> output
//PORTX -> Data Register for port X / 0 -> low / 1 -> high
//PINX -> Input Pins Address for port X / read only

int main(int ac, char **av)
{
	//If the button is pressed, turn on the LED, else turn it off

	//Configure PB0 (LED) as output : set bit 0 in DDRB to 1
	DDRB |= (1 << DDB0);

	//Configure PD2 (Button) as input : clear bit 2 in DDRD to 0
	DDRD &= ~(1 << DDD2);

	//Enable pull-up resistor on PD2 : set bit 2 in PORTD to 1
	PORTD |= (1 << PORTD2);

	while(1){
		//Read button state on PD2
		if (!(PIND & (1 << PIND2))){
			//Button pressed (input low), turn  on LED (PB0)
			PORTB |= (1 << PORTB0);
			
		} else {
			//Turn off LED on PB0
			PORTB &= ~(1 << PORTB0);
		}
	}
	 return 0;
}