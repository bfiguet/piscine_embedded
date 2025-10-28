#include <avr/io.h>

// Using Timer1 to toggle an LED at 1Hz (0.5s ON, 0.5s OFF) on PB1 (OC1A pin)
//An AVR's Timer1 is controlled by several registers, including TCCR1A and TCCR1B.
//These registers contain several bits that determine the operation of the timer, 
//	including its counting mode (normal, CTC, PWM, etc.).
//The WGM13, WGM12, WGM11, WGM10 (Waveform Generation Mode) bits distributed between 
//	TCCR1A and TCCR1B define the mode.
//CTC mode automatically resets the counter when the timer value reaches a value defined 
//	in the OCR1A register. This allows for accurate frequency generation without CPU intervention.

int main(int ac, char **av)
{
	// Configure PB1 (OC1A) as output
	DDRB |= (1 << DDB1);

	//Mode CTC (Clear Timer on Compare Match) : WGM12 = 1
	// TCCR = Timer/Counter Control register
	TCCR1A = 0;  //Sets all bits in the TCCR1A register to 0. // No PWM, no advanced mode, normal output.
	TCCR1B = (1 << WGM12);  //Only sets the WGM12 bit to 1 in TCCR1B, which enables CTC mode.
	//TCCR1A mainly manages the configuration of the OC1A/OC1B outputs (the physical outputs 
	//	linked to the timer) and certain PWM modes.
	//TCCR1B manages the prescaler (timer frequency division), the counting mode 
	//	(Waveform Generation Mode via WGM12 and WGM13 bits), and other options related to the clock source.

	//Toggle OC1A on Compare Match : COM1A0 = 1, COM1A1 = 0
	TCCR1A |= (1 << COM1A0);

	// This line selects the clock speed for the timer, so the timer counts slower, allowing longer timeouts to be generated.
	// This means that if the CPU is running at 1 MHz, the timer will count at 1,000,000 / 64 = 15,625 Hz.
	TCCR1B |= (1 << CS11) | (1 << CS10);  //Sets bits CS11 and CS10 to 1, and leaves CS12 at 0.
	// CS12 = 0, CS11 = 1, CS10 = 1  -> prescaler = 64
	// Clock Select bits (CS12, CS11, CS10) in TCCR1B register determine the prescaler value.
	
	// One cycle = 0.5s ON + 0.5s OFF = 1Hz, toggle all 0.5s, so toggle frequency = 2Hz
	// OCR1A compare value which defines the frequency : OCR1A = (15625/2) - 1 = 7811
	OCR1A = 7811;

	// Timer1 will count from 0 to OCR1A (7811), then toggle output OC1A (PB1).
	// The LED connected to PB1 therefore oscillates at 1 Hz (toggles every 0.5s).
	// The hardware timer flag does the work without CPU intervention, so empty loop.
	// No direct writing to PORTB in the loop, the hardware handles it.
	
	while(1){
		// empty loop
	}
	 return 0;
}