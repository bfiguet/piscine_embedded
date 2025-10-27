#include <avr/io.h>

//PB0 -> Pin Data 0 for port B / LED (D1)
//PD2 -> Pin Data 2 for port D / Button (SW1)
//DDRX -> Data Direction Register for port X / 0 -> input / 1 -> output
//PORTX -> Data Register for port X / 0 -> low / 1 -> high
//PINX -> Input Pins Address for port X / read only

int main(int ac, char **av)
{
	//Retrieve the state of the button once and set the LED accordingly
	
	DDRB |= (1 << DDB0);  // Configure PB0 (LED) as output
	PORTB &= ~(1 << PORTB0); // Ensure LED is off initially

	DDRD &= ~(1 << DDD2);  // Configure PD2 (Button) as input
	PORTD |= (1 << PORTD2);  // Enable pull-up resistor on PD2

	uint8_t button_previous_state = 1; // Assume button not pressed initially
	
	while(1){
		uint8_t button_current_state = (PIND & (1 << PIND2)) ? 1 : 0;
		if (button_previous_state == 1 && button_current_state == 0){
			//Toggle LED state on button press
			PORTB ^= (1 << PORTB0);  // Compares each bit.
		}
		button_previous_state = button_current_state;
	}
	 return 0;
}