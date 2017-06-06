#device PIC18F4620
#device ADC=10

#define uC18f4620
#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#fuses XT, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, MCLR, STVREN, NOLVP, NODEBUG
//
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use delay(clock=16000000)
byte banderas=0;
#bit banderaCanal =banderas.0

int16 valorPot1=0;
int16 valorPot2=0;
double voltaje=0;
int16 valor=0;

#INT_AD
void AD_isr(void)
{
   if(banderaCanal==0)
   {
      delay_ms(10);
      valorPot1=read_ADC(ADC_READ_ONLY);
      set_adc_channel(1);
     banderaCanal=1;
   }
   else if(banderaCanal==1)
   {
      delay_ms(10);
      valorPot2=read_ADC(ADC_READ_ONLY);
      set_adc_channel(0);
      banderaCanal=0;
   }
   

}



void configuracionADC(){
   setup_oscillator(OSC_NORMAL);
   set_tris_a(0x03);
   set_tris_b(0x00);       //todos pines estan en salida en el puerto b
   set_tris_c(0x00);       //todos los pines estan en salida
   set_tris_d(0x00);
   setup_adc(adc_clock_internal);
   setup_adc_ports(0011);
   enable_interrupts(INT_AD);
   enable_interrupts(global); 
   set_adc_channel(0);
}
