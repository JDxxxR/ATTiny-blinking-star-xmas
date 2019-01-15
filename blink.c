#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>

int main(void)
{
	DDRB = 0b00000111;
	uint8_t bla = 1;
	uint8_t towrite = 2;
	uint8_t wert;
	wert = eeprom_read_byte((uint8_t*) 1);
	
	if (wert == 1)
	{
		bla = 1;
		towrite = 2;
	}
	if (wert == 2)
	{
		bla = 2;
		towrite = 1;
	}	
	
	eeprom_write_byte((uint8_t*) 1, towrite);

	
	if (bla == 1)
	{
		PORTB |= 0b00000111;
	}
	
	if (bla == 2)
	{
		while(bla = 2)
		{
			PORTB |= 0b00000111;
			_delay_ms(1000);
			PORTB &= ~0b00000001;
			_delay_ms(1000);
			PORTB |= 0b00000001;
			PORTB &= ~0b00000010;
			_delay_ms(1000);
			PORTB |= 0b00000010;
			_delay_ms(1000);
			PORTB &= ~0b00000100;
			_delay_ms(1000);
		}
	}
		
	
}
