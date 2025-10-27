#include <avr/io.h>

//DDRX -> Data Direction Register for port X / 0 -> input / 1 -> output
//PORTX -> Data Register for port X / 0 -> low / 1 -> high
//PINX -> Input Pins Address for port X / read only

int main(int ac, char **av)
{
	// Configure PB0 as output: set bit 0 in DDRB to 1
	DDRB |= (1 << DDB0);  // DDRB = DDRX for port B

	//Set PB0 to 1 to turn on the LED: set bit 0 in PORTB to 1
	PORTB |= (1 << PORTB0);  //PORTB = PORTX for port B

	//Loop ensures that the microcontroller remains in a defined state 
	//and does not abruptly step outside the intended code.
	while(1){
		//Do nothing, the LED stays on
	}

	 return 0;
}