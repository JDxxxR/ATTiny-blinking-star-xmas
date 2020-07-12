#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>

int main(void)
{
	DDRB = 0b00000111;
	uint8_t mode = 1;
	uint8_t towrite = 2;
	uint8_t curr_value;
	curr_value = eeprom_read_byte((uint8_t*) 1);
	
	if (curr_value == 1)
	{
		mode = 1;
		towrite = 2;
	}
	if (curr_value == 2)
	{
		mode = 2;
		towrite = 1;
	}	
	
	eeprom_write_byte((uint8_t*) 1, towrite);

	
	if (mode == 1)
	{
		PORTB |= 0b00000111;
	}
	
	if (mode == 2)
	{
		while(1)
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
