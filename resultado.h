
double voltaje=0;
int16 valorPort2=0;//variable para guardar el valor que indicará el rango en que se encuentra
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void calculoRango(void)
{
   voltaje= Port2*.004882813;
   if(voltaje>=0 && voltaje <=.49)//Comparaciones hechas para encontrar el rango de voltaje leido en el segundo puerto de señal analogica
   {                              //
      valorPort2=1;
   }
   else if(voltaje>.49 && voltaje <=.99)//Los valores ueron puestos en terminación de 9 para tener mayor precisión
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
   else//fuera de rango, en caso de que sucediera
   {
     valorPort2=0;
   }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 void mostrarResultados(void)
 {
      read_adc(ADC_START_ONLY);
      output_a(Port1<<2);//Imprime la salida de 10 bits de la lectura directa del ADC (va de 0 a 1023)
      output_b(Port1>>4);//
      calculoRango();
      output_c(valorPort2);//Imprime el rango en que se encuentra la lectura del ADC (este trabaja en porcentaje, cada bit es un 10%)
      output_d(valorPort2>>8);//
 }
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
