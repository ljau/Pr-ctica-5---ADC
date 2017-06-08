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
   if(counter>3)//Esta condicion es para ralentizar la lectura del adc
   {
      read_adc(ADC_START_ONLY);//Inicia el adc
      if(banderaCanal==0)//Estas condiciones son para alternar la entrada de voltaje que será leída
      {
         Port1=read_ADC(ADC_READ_ONLY);//lee el ADC
         set_adc_channel(1);//Setea el canal 1
         banderaCanal=1;//Activa la bandera en 1 para señalar que canal se usó
      }
      else if(banderaCanal==1)//checa la bandera del canal 1, si está activada ahora le toca al canal 0
      {
         Port2=read_ADC(ADC_READ_ONLY);
         set_adc_channel(0);
         banderaCanal=0;
      }
      counter=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#int_timer0
void timer_0()
{
   counter++;
   set_timer0(0);
}
