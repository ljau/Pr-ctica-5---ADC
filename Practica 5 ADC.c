#include <ADCconfig.h>
#include <Resultado.h>
void main()
{
   configuracionADC();//Setea los puertos ADC y manda a llamar funciones de otra librer�a para setear los puertos TRIS, tambien setea las interrupciones 
   while(TRUE)
   {
      mostrarResultados();//Muestra los resultados despu�s de obtener los valores de salida
   }
}

