#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

void t_lcd::init(void)
{
	//Set the ports as output
	DDR(RS_PORT)	|= (1 << DD(RS_PORT, RS_PIN));
	DDR(E_PORT)		|= (1 << DD(E_PORT, E_PIN));
	DDR(RW_PORT)	|= (1 << DD(RW_PORT, RW_PIN));
	DDR(DB4_PORT)	|= (1 << DD(DB4_PORT, DB4_PIN));
	DDR(DB5_PORT)	|= (1 << DD(DB5_PORT, DB5_PIN));
	DDR(DB6_PORT)	|= (1 << DD(DB6_PORT, DB6_PIN));
	DDR(DB7_PORT)	|= (1 << DD(DB7_PORT, DB7_PIN));

	_delay_ms(15);
	setDBPort(0x3); //0b0011
	_delay_ms(5);

}

void t_lcd::setDBPort(uint8_t bits)
{
	if(bits & (1 << 0))
		SETPIN(DB4_PORT, DB4_PIN);
	else
		CLEARPIN(DB4_PORT, DB4_PIN);

	if(bits & (1 << 1))
		SETPIN(DB5_PORT, DB5_PIN);
	else
		CLEARPIN(DB5_PORT, DB5_PIN);

	if(bits & (1 << 2))
		SETPIN(DB6_PORT, DB6_PIN);
	else
		CLEARPIN(DB6_PORT, DB6_PIN);

	if(bits & (1 << 3))
		SETPIN(DB7_PORT, DB7_PIN);
	else
		CLEARPIN(DB7_PORT, DB7_PIN);
}

void t_lcd::sendByte(uint8_t data, bool type)
{
	if(type)
		SETPIN(RS_PORT, RS_PIN);
	else
		CLEARPIN(RS_PORT, RS_PIN);

	for(uint8_t teller = 0; teller != 2; ++teller)
	{
		_delay_us(1);
		SETPIN(E_PORT, E_PIN);

		setDBPort(data);
		
		_delay_us(1);

		CLEARPIN(E_PORT, E_PIN);

		data = data >> 4;
	}
}
