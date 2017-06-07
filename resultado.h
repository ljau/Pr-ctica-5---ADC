
double voltaje=0;
int16 valorPort2=0;//valor para indicar el rango en que se encuentra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void calculoRango(void)
{
   voltaje= Port2*.004882813;
   if(voltaje>=0 && voltaje <=.49)
   {
      valorPort2=1;
   }
   else if(voltaje>.49 && voltaje <=.99)
   {
      valorPort2=2;
   }
   else if(voltaje>.99 && voltaje <=1.49)
   {
      valorPort2=4;
   }
   else if(voltaje>1.49 && voltaje <=1.99)
   {
     valorPort2=8;
   }
   else if(voltaje>1.99 && voltaje <=2.49)
   {
      valorPort2=16;
   }
   else if(voltaje>2.49  && voltaje <=2.99)
   {
      valorPort2=32;
   }
   else if(voltaje>2.99 && voltaje <=3.49)
   {
      valorPort2=64;
   }
   else if(voltaje>3.49 && voltaje <=3.99)
   {
      valorPort2=128;
   }
   else if(voltaje>3.99 && voltaje <=4.49)
   {
     valorPort2=256;
   }
   else if(voltaje>4.49 && voltaje <=5)
   {
      valorPort2=512;
   }
   else
   {
     valorPort2=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 void mostrarResultados(void)
 {
      read_adc(ADC_START_ONLY);
      output_a(Port1<<2);
      output_b(Port1>>4);
      calculoRango();
      output_c(valorPort2);
      output_d(valorPort2>>8);
 }
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
