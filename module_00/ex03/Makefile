AVR = avr-gcc #AVR GCC compiler
MCU = atmega328p #Target AVR microcontroller
F_CPU =  800000UL #Target AVR clock rate in Hertz /8MHz
BAUD = 115200 #Baud rate for serial communication
CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) #Compiler flags
SRC = main.c
OBJ = main.bin
OBJCOPY = avr-objcopy #Program for copying and translating object files
HEX = main.hex

all: hex flash

hex: $(HEX)

$(OBJ): $(SRC)
	$(AVR) $(CFLAGS) -o $(OBJ) $(SRC)

$(HEX): $(OBJ)
	$(OBJCOPY) -O ihex $(OBJ) $(HEX)
#	-O ihex output format Intel Hex
	
flash: $(HEX)
	avrdude -c arduino -p $(MCU)-F -V -P /dev/ttyUSB0 -b $(BAUD) -U flash:w:$(HEX):i
#	-c arduino programmer type 
#	-p m328p microcontroller type 
#	-P /dev/ttyUSB0 communication port
#	-b $(BAUD) communication speed
#	-U flash:w:bin/main.hex:i flash memory option

clean:
	rm -f $(HEX) $(OBJ)

.PHONY: all clean hex flash