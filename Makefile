#
# Based on
# https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_Makefile
#

TARGET=blink
MCU=attiny13
SOURCES=blink.c

# For example a usbasp
PROGRAMMER=usbasp

# avrdude tries to determine
#PORT=-P/dev/ttyACM0
#BAUD=9600

# Leave everything as given
OBJECTS=$(SOURCES:.c=.o)
CFLAGS=-c -Os
LDFLAGS=

all: hex

hex: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $(TARGET).elf $(TARGET).hex

$(TARGET).elf: $(OBJECTS)
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) $(OBJECTS) -o $(TARGET).elf

.c.o:
	avr-gcc $(CFLAGS) -mmcu=$(MCU) $< -o $@

program:
	avrdude -p$(MCU) $(PORT) $(BAUD) -c$(PROGRAMMER) -Uflash:w:$(TARGET).hex:a

# This rule fails, when the MCU cannot be detected or the programmer is wrong configured or connected
checkmcu:
	avrdude -p$(MCU) $(PORT) $(BAUD) -c$(PROGRAMMER)

clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.hex
