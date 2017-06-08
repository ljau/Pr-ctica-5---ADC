#device PIC18F4620
#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#fuses XT, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, MCLR, STVREN, NOLVP, NODEBUG

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use delay(clock=16000000)

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\
void setPorts(void)
{
   setup_oscillator(OSC_NORMAL);
   set_tris_a(0x03);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
}
void configTimer0(void)
{
   set_timer0(0);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128|T0_8_BIT);
   enable_interrupts(int_timer0);
}
//////////////////////////////////////////////////////////////////
