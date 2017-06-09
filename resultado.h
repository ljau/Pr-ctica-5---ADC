
double voltaje=0;

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void calculoRango(void)
{ 
if(newsamplig==1){ 
   newsamplig=0;
   portBinary= binaryBuffer/10;
   binaryBuffer=0;   
   
}
voltaje= segmentBox*.004882813;
   if(voltaje>=0 && voltaje <=.49)
   {
      portSegment=1;
   }
   else if(voltaje>.49 && voltaje <=.99)
   {
      portSegment=2;
   }
   else if(voltaje>.99 && voltaje <=1.49)
   {
      portSegment=4;
   }
   else if(voltaje>1.49 && voltaje <=1.99)
   {
      portSegment=8;
   }
   else if(voltaje>1.99 && voltaje <=2.49)
   {
      portSegment=16;
   }
   else if(voltaje>2.49  && voltaje <=2.99)
   {
      portSegment=32;
   }
   else if(voltaje>2.99 && voltaje <=3.49)
   {
      portSegment=64;
   }
   else if(voltaje>3.49 && voltaje <=3.99)
   {
      portSegment=128;
   }
   else if(voltaje>3.99 && voltaje <=4.49)
   {
      portSegment=256;
   }
   else if(voltaje>4.49 && voltaje <=5)
   {
      portSegment=512;
   }
   else;


}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 void resultados(void)
 {        
      
      calculoRango();
      output_a(portBinary<<2);
      output_b(portBinary>>4);
      output_c(portSegment);
      output_d(portSegment>>8);
 }
