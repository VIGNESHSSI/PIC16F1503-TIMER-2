/*
 * 1KHz
 *time delay=0.5 milli second 
 * pre scalar 1:1
 * post scalar 1:2
 * T2CON=0XC0
 * TMR2=0;
 * PR2=255;
 */
#include <xc.h>
#define _XTAL_FRE 4e6
void __interrupt()isr()
{ 
    if(TMR2IF)
    {
         RA0=~RA0;
        TMR2=0;
        PR2=255;
        TMR2IF=0;
    }
  
}

void main()
{  
    OSCCON=0X68;
    PORTA=0X00;
    TRISA=0X00;
    ANSELA=0X00;
    
    TMR2IF=0;
    PIE1=0X02;
    INTCON=0XC0;
    TMR2=0;
    PR2=255;
    T2CON=0X0C ;
    
    while(1)
    {
        
    }
}
