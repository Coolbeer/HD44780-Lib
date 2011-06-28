#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	t_lcd lcd;
	lcd.init();
	
	lcd.writeStringXY(1,0,(char*)"Hello World! Hello World! Hello World!");
	lcd.writeIntXY(5,1, 1234567890, 8);
	while(1)
	{
		for(uint32_t delay = 0; delay != 0x02FFFF; ++delay)
			asm volatile ( "nop" );		
		lcd.displayShift();
	}

	return 0;
}
