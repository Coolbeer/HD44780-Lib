#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	t_lcd lcd;
	lcd.init();
	
	lcd.sendStringXY(1,0,"Hello World!");
	lcd.sendStringXY(1,1,"Wooooohoooooo!");

	return 0;
}
