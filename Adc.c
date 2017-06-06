#include <config.h>
#include <Resultado.h>

void calculo(void);

void main()
{
   configuracionADC();
   banderaCanal=0;
   while(TRUE)
   {
      read_adc(ADC_START_ONLY);
      output_a(valorPot1<<2);
      output_b(valorPot1>>4);
      calculo();
      output_c(valor);
      output_d(valor>>8);
   }

}


