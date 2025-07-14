#include <xc.h>


void init_timer2(void)
{
   
    
    
    // turn on the timer2
    TMR2ON = 0;
    
   
    
    //no of ticks in PR2
    PR2 = 250;
    
    // enable timer2 interrupt
    TMR2IE = 1;
    
    
    // clear timer2 int flag
    TMR2IF = 0;
    
    
    
    
    
}
