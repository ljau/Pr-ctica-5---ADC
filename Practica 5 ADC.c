#include <ADCconfig.h>
#include <Resultado.h>

void main()
{
   configuracionADC();
   while(TRUE)
   {
   read_adc(ADC_START_ONLY);
      resultados();
   }
}

