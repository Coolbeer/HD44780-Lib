#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	t_lcd lcd;
	lcd.init();
	
	lcd.writeStringXY(1,0,(char*)"Hello World!");
	for(uint32_t hepp = 0; hepp != 99000000; ++hepp)
		lcd.writeIntXY(5,1, hepp, 8);

	return 0;
}
