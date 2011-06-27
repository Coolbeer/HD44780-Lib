#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	t_lcd lcd;
	lcd.init();
	
	lcd.writeStringXY(1,0,(char*)"Hello World!");
	lcd.writeIntXY(5,1, 100000, 8);

	return 0;
}
