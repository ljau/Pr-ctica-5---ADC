//////////////
double voltaje=0;
int16 valorPort2=0;
/////////////////////////////////////////////////////////////
void calculoValorRango(void)
{
   voltaje= Port2*.004882813;
   if(voltaje>=0 && voltaje <.5)
   {
      valorPort2=1;
   }
   else if(voltaje>=.5 && voltaje <1)
   {
      valorPort2=2;
   }
   else if(voltaje>=1 && voltaje <1.5)
   {
      valorPort2=4;
   }
   else if(voltaje>=1.5 && voltaje <2)
   {
     valorPort2=8;
   }
   else if(voltaje>=2 && voltaje <2.5)
   {
      valorPort2=16;
   }
   else if(voltaje>=2.5  && voltaje <3)
   {
      valorPort2=32;
   }
   else if(voltaje>=3 && voltaje <3.5)
   {
      valorPort2=64;
   }
   else if(voltaje>=3.5 && voltaje <4)
   {
      valorPort2=128;
   }
   else if(voltaje>=4 && voltaje <4.5)
   {
     valorPort2=256;
   }
   else if(voltaje>=4.5 && voltaje <5)
   {
      valorPort2=512;
   }
   else
   {
     valorPort2=0;
   }
}
//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
 void mostrarResultados(void)
 {
      read_adc(ADC_START_ONLY);
      output_a(Port1<<2);
      output_b(Port1>>4);
      calculoValorRango();
      output_c(valorPort2);
      output_d(valorPort2>>8);
 }
/////////////////////////////////////////////////////////////////////
