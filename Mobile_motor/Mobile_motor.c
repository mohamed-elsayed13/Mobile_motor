/*
 * Mobile_motor.c
 *
 * Created: 12/06/2020 7:35:19 PM
 *  Author: Mohamed Elsayed
 */ 

#include "PWM.h"
#include "UART.h"
int main(void)
{
	uint8_t receiver=0;
	Uart_init();
	PWM_init_timer1_oc1a();
	set_duty_oc1a(0);
	Uart_Write_string(" T to turn on & O to turn off & R to reverse & 4 speeds 70% --> 100% ");
    while(1)
    {

		receiver=Uart_Read();			
		if(receiver=='T'){
			SETBIT(DDRC,0);
			SETBIT(DDRC,1);
			SETBIT(PORTC,0);
			CLRBIT(PORTC,1);
			Uart_Write_string(" T to turn on & O to turn off & R to reverse & 4 speeds 70% --> 100% ");
			}
		else if(receiver=='6'){set_duty_oc1a(60);}
		else if(receiver=='7'){set_duty_oc1a(70);}
		else if(receiver=='8'){set_duty_oc1a(80);}
		else if(receiver=='9'){set_duty_oc1a(90);}
		else if(receiver=='1'){
			receiver=Uart_Read();
			if (receiver=='0')
			{
				set_duty_oc1a(100);
			}
				}
		else if(receiver=='R'){
			TOGBIT(PORTC,0);
			TOGBIT(PORTC,1);
			}
		else if(receiver=='O'){
			CLRBIT(DDRC,0);
			CLRBIT(DDRC,1);		
		}
		
    }
}