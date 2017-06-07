#include <ADCconfig.h>
#include <Resultado.h>
void main()
{
   configuracionADC();
   while(TRUE)
   {
      mostrarResultados();
   }
}

