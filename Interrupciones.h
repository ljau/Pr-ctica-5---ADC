///////////////////////////////////////
byte banderas=0;
#bit banderaCanal = banderas.0
int counter=0;
int16 Port1=0;
double Port2=0;
///////////////////////////////////////
#INT_AD
void AD_isr(void)
{
   if(counter>3)
   {
      read_adc(ADC_START_ONLY);
      if(banderaCanal==0)
      {
         Port1=read_ADC(ADC_READ_ONLY);
         set_adc_channel(1);
         banderaCanal=1;
      }
      else if(banderaCanal==1)
      {
         Port2=read_ADC(ADC_READ_ONLY);
         set_adc_channel(0);
         banderaCanal=0;
      }
      counter=0;
   }
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
#int_timer0
void timer_0()
{
   counter++;
   set_timer0(0);
}
