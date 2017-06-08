#device PIC18F4620
#device ADC=10
#define uC18f4620
#include <config.h>
#include <Interrupciones.h>

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\\
void configuracionADC()
{
   setPorts();
   configTimer0();
   setup_adc(adc_clock_internal);
   setup_adc_ports(0x03);
   set_adc_channel(0x00);
   banderaCanal=0;
   enable_interrupts(INT_AD);
   enable_interrupts(global);
}

