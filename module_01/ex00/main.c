#include <avr/io.h>

//1Hz == 1 cycle per second / 0.5s ON / 0.5s OFF

void delay_0_5s(void){
	// The volatile keyword in C tells the compiler that the value 
	//of the variable can change unpredictably
	for (volatile uint32_t i = 0; i < 50000; i++); // Adjust loop count for accurate timing
}

int main(int ac, char **av)
{
	//Alternate the state of the LED every 1/2 second
	
	DDRB |= (1 << DDB1);  // Configure PB1 (LED D2) as output
	
	while(1){
		PORTB ^= (1 << PORTB1);  // Toggle PB1 (LED D2)
		delay_0_5s();            // Wait for 0.5 second
	}
	 return 0;
}