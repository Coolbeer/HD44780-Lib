#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	t_lcd lcd;
	lcd.init();
	
	lcd.sendString("Hello World!");
	lcd.gotoXY(0,1);
	lcd.sendString("Wooooohoooooo!");

	return 0;
}
